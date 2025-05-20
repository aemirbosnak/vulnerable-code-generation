//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} product;

product inventory[MAX_PRODUCTS];
int total_products = 0;

pthread_mutex_t inventory_mutex;

void* add_product(void* arg) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    printf("Enter product name: ");
    scanf("%s", name);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    pthread_mutex_lock(&inventory_mutex);
    if(total_products < MAX_PRODUCTS) {
        strcpy(inventory[total_products].name, name);
        inventory[total_products].quantity = quantity;
        total_products++;
        printf("Product added to inventory\n");
    } else {
        printf("Inventory is full. Cannot add product\n");
    }
    pthread_mutex_unlock(&inventory_mutex);
    return NULL;
}

void* display_inventory(void* arg) {
    pthread_mutex_lock(&inventory_mutex);
    printf("Inventory:\n");
    for(int i = 0; i < total_products; i++) {
        printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&inventory_mutex);
    return NULL;
}

int main() {
    pthread_t threads[2];
    pthread_mutex_init(&inventory_mutex, NULL);

    while(1) {
        printf("1. Add product to inventory\n");
        printf("2. Display inventory\n");
        printf("3. Exit\n");
        int option;
        scanf("%d", &option);
        switch(option) {
            case 1: {
                pthread_create(&threads[0], NULL, add_product, NULL);
                break;
            }
            case 2: {
                pthread_create(&threads[1], NULL, display_inventory, NULL);
                break;
            }
            case 3: {
                printf("Exiting program\n");
                pthread_mutex_destroy(&inventory_mutex);
                return 0;
            }
            default: {
                printf("Invalid option\n");
                break;
            }
        }
        pthread_join(threads[0], NULL);
        pthread_join(threads[1], NULL);
    }
}