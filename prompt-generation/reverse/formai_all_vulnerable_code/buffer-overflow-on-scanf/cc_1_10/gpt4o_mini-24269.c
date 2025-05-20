//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PRODUCTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int productCount = 0;
pthread_mutex_t lock;

void addProduct(const char *name, int quantity) {
    pthread_mutex_lock(&lock);
    if (productCount < MAX_PRODUCTS) {
        strncpy(inventory[productCount].name, name, NAME_LENGTH);
        inventory[productCount].quantity = quantity;
        productCount++;
        printf("Product %s added with quantity %d\n", name, quantity);
    } else {
        printf("Inventory full! Cannot add more products.\n");
    }
    pthread_mutex_unlock(&lock);
}

void viewProducts() {
    pthread_mutex_lock(&lock);
    printf("Current inventory:\n");
    for (int i = 0; i < productCount; i++) {
        printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&lock);
}

void *userSession(void *arg) {
    char command[100];
    char name[NAME_LENGTH];
    int quantity;

    while (1) {
        printf("Enter command (add/view/exit): ");
        scanf(" %s", command);

        if (strcmp(command, "add") == 0) {
            printf("Enter product name: ");
            scanf(" %s", name);
            printf("Enter product quantity: ");
            scanf("%d", &quantity);
            addProduct(name, quantity);
        } else if (strcmp(command, "view") == 0) {
            viewProducts();
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting user session.\n");
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    return NULL;
}

int main() {
    pthread_t users[5];
    pthread_mutex_init(&lock, NULL);

    // Create multiple user threads
    for (int i = 0; i < 5; i++) {
        printf("Starting user session %d\n", i + 1);
        pthread_create(&users[i], NULL, userSession, NULL);
    }

    // Join all user threads
    for (int i = 0; i < 5; i++) {
        pthread_join(users[i], NULL);
    }

    pthread_mutex_destroy(&lock);
    printf("Final inventory:\n");
    viewProducts();
    return 0;
}