//GPT-4o-mini DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define NAME_LEN 30

typedef struct {
    char name[NAME_LEN];
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];
int product_count = 0;

pthread_mutex_t inventory_mutex;

void add_product(const char* name, int quantity) {
    pthread_mutex_lock(&inventory_mutex);
    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            inventory[i].quantity += quantity;
            pthread_mutex_unlock(&inventory_mutex);
            return;
        }
    }
    if (product_count < MAX_PRODUCTS) {
        strcpy(inventory[product_count].name, name);
        inventory[product_count].quantity = quantity;
        product_count++;
    }
    pthread_mutex_unlock(&inventory_mutex);
}

void remove_product(const char* name, int quantity) {
    pthread_mutex_lock(&inventory_mutex);
    for (int i = 0; i < product_count; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            if (inventory[i].quantity >= quantity) {
                inventory[i].quantity -= quantity;
                if (inventory[i].quantity == 0) {
                    inventory[i] = inventory[product_count - 1];
                    product_count--;
                }
            }
            break;
        }
    }
    pthread_mutex_unlock(&inventory_mutex);
}

void check_inventory() {
    pthread_mutex_lock(&inventory_mutex);
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < product_count; i++) {
        printf("Product: %s, Quantity: %d\n", inventory[i].name, inventory[i].quantity);
    }
    pthread_mutex_unlock(&inventory_mutex);
}

void* inventory_thread(void* arg) {
    char* command = (char*)arg;
    char name[NAME_LEN];
    int quantity;

    if (sscanf(command, "ADD %s %d", name, &quantity) == 2) {
        add_product(name, quantity);
    } else if (sscanf(command, "REMOVE %s %d", name, &quantity) == 2) {
        remove_product(name, quantity);
    } else if (strcmp(command, "CHECK") == 0) {
        check_inventory();
    }

    return NULL;
}

int main() {
    pthread_mutex_init(&inventory_mutex, NULL);
    char command[50];
    pthread_t threads[10];
    int thread_count = 0;

    while (1) {
        printf("\nEnter command (ADD <name> <quantity>, REMOVE <name> <quantity>, CHECK, or EXIT): ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove newline character

        if (strcmp(command, "EXIT") == 0) {
            break;
        }

        pthread_create(&threads[thread_count], NULL, inventory_thread, (void*)strdup(command));
        thread_count++;

        // Join threads if they exceed 10
        if (thread_count >= 10) {
            for (int i = 0; i < thread_count; i++) {
                pthread_join(threads[i], NULL);
            }
            thread_count = 0;
        }
    }

    // Join remaining threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&inventory_mutex);
    return 0;
}