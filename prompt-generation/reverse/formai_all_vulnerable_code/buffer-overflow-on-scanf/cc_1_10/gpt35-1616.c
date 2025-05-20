//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PRODUCTS 100

// Product struct holding information about each product
typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Product;

// Global variables
Product inventory[MAX_PRODUCTS];
int numProducts = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a product to the inventory
void addProduct(int id, char *name, int quantity, float price) {
    pthread_mutex_lock(&mutex);
    if (numProducts < MAX_PRODUCTS) {
        inventory[numProducts].id = id;
        strcpy(inventory[numProducts].name, name);
        inventory[numProducts].quantity = quantity;
        inventory[numProducts].price = price;
        numProducts++;
        printf("Product %s added to inventory.\n", name);
    }
    pthread_mutex_unlock(&mutex);
}

// Function to remove a product from the inventory
void removeProduct(int id) {
    pthread_mutex_lock(&mutex);
    int i;
    for (i = 0; i < numProducts; i++) {
        if (inventory[i].id == id) {
            printf("Product %s removed from inventory.\n", inventory[i].name);
            for (; i < numProducts - 1; i++) {
                inventory[i] = inventory[i + 1];
            }
            numProducts--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
}

// Function to print all products in the inventory
void printInventory() {
    pthread_mutex_lock(&mutex);
    int i;
    printf("Product ID\tProduct Name\t\tQuantity\tPrice\n");
    for (i = 0; i < numProducts; i++) {
        printf("%d\t\t%s\t\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
    pthread_mutex_unlock(&mutex);
}

// Thread function to continuously ask user for requests
void *userInput(void *arg) {
    int id, quantity;
    char name[20];
    float price;
    char operation;

    while (1) {
        printf("\nEnter operation (a - add product, r - remove product, p - print inventory, q - quit): ");
        scanf(" %c", &operation);

        switch(operation) {
            case 'a':
                printf("Enter product details (ID, name, quantity, price): ");
                scanf("%d %s %d %f", &id, name, &quantity, &price);
                addProduct(id, name, quantity, price);
                break;
            case 'r':
                printf("Enter product ID to remove: ");
                scanf("%d", &id);
                removeProduct(id);
                break;
            case 'p':
                printInventory();
                break;
            case 'q':
                pthread_exit(NULL);
            default:
                printf("Invalid operation.\n");
        }
    }

    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, userInput, NULL);

    pthread_exit(NULL);
    return 0;
}