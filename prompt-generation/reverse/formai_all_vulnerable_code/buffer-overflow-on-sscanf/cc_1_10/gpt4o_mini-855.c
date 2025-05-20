//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 50
#define NAME_LENGTH 30

typedef struct {
    int productId;
    char name[NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    int orderId;
    int productId;
    int quantity;
} Order;

Product products[MAX_PRODUCTS];
int productCount = 0;
Order orders[MAX_ORDERS];
int orderCount = 0;
pthread_mutex_t productMutex;
pthread_mutex_t orderMutex;

void *manageProducts(void *arg) {
    char command[50];
    while (1) {
        printf("Enter product command (ADD/REMOVE): ");
        fgets(command, sizeof(command), stdin);
        if (strncmp(command, "ADD", 3) == 0) {
            pthread_mutex_lock(&productMutex);
            if (productCount < MAX_PRODUCTS) {
                sscanf(command + 4, "%d %s %d", &products[productCount].productId, products[productCount].name, &products[productCount].quantity);
                productCount++;
                printf("Added product: %s\n", products[productCount - 1].name);
            } else {
                printf("Product limit reached.\n");
            }
            pthread_mutex_unlock(&productMutex);
        } else if (strncmp(command, "REMOVE", 6) == 0) {
            int idToRemove;
            sscanf(command + 7, "%d", &idToRemove);
            pthread_mutex_lock(&productMutex);
            for (int i = 0; i < productCount; i++) {
                if (products[i].productId == idToRemove) {
                    printf("Removed product: %s\n", products[i].name);
                    products[i] = products[--productCount]; // Remove product and shift
                    break;
                }
            }
            pthread_mutex_unlock(&productMutex);
        }
    }
}

void *manageOrders(void *arg) {
    char command[50];
    while (1) {
        printf("Enter order command (CREATE): ");
        fgets(command, sizeof(command), stdin);
        if (strncmp(command, "CREATE", 6) == 0) {
            int orderId, productId, quantity;
            sscanf(command + 7, "%d %d %d", &orderId, &productId, &quantity);
            pthread_mutex_lock(&orderMutex);
            if (orderCount < MAX_ORDERS) {
                orders[orderCount].orderId = orderId;
                orders[orderCount].productId = productId;
                orders[orderCount].quantity = quantity;
                orderCount++;
                printf("Created order with ID: %d for product ID: %d\n", orderId, productId);
            } else {
                printf("Order limit reached.\n");
            }
            pthread_mutex_unlock(&orderMutex);
        }
    }
}

void printProducts() {
    pthread_mutex_lock(&productMutex);
    printf("Available Products:\n");
    for (int i = 0; i < productCount; i++) {
        printf("ID: %d, Name: %s, Quantity: %d\n", products[i].productId, products[i].name, products[i].quantity);
    }
    pthread_mutex_unlock(&productMutex);
}

void printOrders() {
    pthread_mutex_lock(&orderMutex);
    printf("Active Orders:\n");
    for (int i = 0; i < orderCount; i++) {
        printf("Order ID: %d, Product ID: %d, Quantity: %d\n", orders[i].orderId, orders[i].productId, orders[i].quantity);
    }
    pthread_mutex_unlock(&orderMutex);
}

int main() {
    pthread_t productThread, orderThread;

    pthread_mutex_init(&productMutex, NULL);
    pthread_mutex_init(&orderMutex, NULL);

    pthread_create(&productThread, NULL, manageProducts, NULL);
    pthread_create(&orderThread, NULL, manageOrders, NULL);

    while (1) {
        printProducts();
        printOrders();
        sleep(5); // Print status every 5 seconds
    }

    pthread_join(productThread, NULL);
    pthread_join(orderThread, NULL);

    pthread_mutex_destroy(&productMutex);
    pthread_mutex_destroy(&orderMutex);

    return 0;
}