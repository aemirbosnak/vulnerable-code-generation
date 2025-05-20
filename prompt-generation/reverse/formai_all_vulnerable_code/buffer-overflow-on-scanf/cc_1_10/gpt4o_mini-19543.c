//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_PRODUCTS 100
#define MAX_USERS 10
#define NAME_LEN 50

// Structure to represent a product
typedef struct {
    char name[NAME_LEN];
    int quantity;
} Product;

// Global inventory array
Product inventory[MAX_PRODUCTS];
int product_count = 0;
pthread_mutex_t lock;

// Function to display the inventory
void display_inventory() {
    pthread_mutex_lock(&lock);
    printf("Current Inventory:\n");
    for(int i = 0; i < product_count; i++) {
        printf("%d. %s - %d\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&lock);
}

// Function to add a product to the inventory
void add_product(char *name, int quantity) {
    pthread_mutex_lock(&lock);
    if (product_count < MAX_PRODUCTS) {
        strcpy(inventory[product_count].name, name);
        inventory[product_count].quantity = quantity;
        product_count++;
        printf("Added %s - %d to the inventory.\n", name, quantity);
    } else {
        printf("Inventory is full, cannot add more products.\n");
    }
    pthread_mutex_unlock(&lock);
}

// Function to remove a product from the inventory
void remove_product(int index) {
    pthread_mutex_lock(&lock);
    if (index >= 0 && index < product_count) {
        printf("Removing %s - %d from the inventory.\n", inventory[index].name, inventory[index].quantity);
        for (int i = index; i < product_count - 1; i++) {
            inventory[i] = inventory[i + 1];
        }
        product_count--;
    } else {
        printf("Invalid product index.\n");
    }
    pthread_mutex_unlock(&lock);
}

// Function to handle user operations
void *user_session(void *arg) {
    char username[NAME_LEN];
    snprintf(username, sizeof(username), "User %ld", (long)arg);
    printf("%s has joined the session.\n", username);

    int choice, quantity, index;
    char name[NAME_LEN];

    while (1) {
        printf("\n%s, select an option:\n", username);
        printf("1. View Inventory\n");
        printf("2. Add Product\n");
        printf("3. Remove Product\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_inventory();
                break;
            case 2:
                printf("Enter product name: ");
                scanf("%s", name);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_product(name, quantity);
                break;
            case 3:
                display_inventory();
                printf("Enter product index to remove (1 to %d): ", product_count);
                scanf("%d", &index);
                remove_product(index - 1);
                break;
            case 4:
                printf("%s is exiting the session.\n", username);
                return NULL;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    pthread_t users[MAX_USERS];
    pthread_mutex_init(&lock, NULL);
    
    int user_count = 0;
    for (long i = 0; i < MAX_USERS; i++) {
        if (pthread_create(&users[i], NULL, user_session, (void *)i) != 0) {
            printf("Failed to create user thread\n");
            return 1;
        }
        user_count++;
        sleep(1); // Stagger user creation for simulation
    }

    for (int i = 0; i < user_count; i++) {
        pthread_join(users[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    return 0;
}