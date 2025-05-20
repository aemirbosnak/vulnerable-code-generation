//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_MEDICINES 1000
#define MAX_CUSTOMERS 50

int medicines_in_stock[MAX_MEDICINES] = {0};
int total_medicines = 0;

struct Customer {
    int id;
    char name[50];
    int order[MAX_MEDICINES];
    int num_medicines;
};

struct ThreadArgs {
    int customer_id;
    int medicine_id;
    int quantity;
};

void* place_order(void* args) {
    struct ThreadArgs* tArgs = (struct ThreadArgs*) args;
    int customer_id = tArgs->customer_id;
    int medicine_id = tArgs->medicine_id;
    int quantity = tArgs->quantity;

    if (quantity > medicines_in_stock[medicine_id]) {
        printf("Insufficient stock of medicine %d for customer %d.\n", medicine_id, customer_id);
    } else {
        medicines_in_stock[medicine_id] -= quantity;
        printf("%d units of medicine %d sold to customer %d.\n", quantity, medicine_id, customer_id);
    }

    pthread_exit(NULL);
}

int main(void) {
    // Initialize medicines
    printf("Enter number of medicines: ");
    scanf("%d", &total_medicines);
    printf("Enter number of units of each medicine in stock:\n");
    for (int i = 0; i < total_medicines; i++) {
        scanf("%d", &medicines_in_stock[i]);
    }

    // Initialize customers
    struct Customer customers[MAX_CUSTOMERS];
    int num_customers = 0;

    printf("Enter number of customers: ");
    scanf("%d", &num_customers);

    for (int i = 0; i < num_customers; i++) {
        printf("\nCustomer %d:\n", i);
        customers[i].id = i;
        printf("Enter name: ");
        scanf("%s", customers[i].name);
        printf("Enter number of medicines ordered: ");
        scanf("%d", &customers[i].num_medicines);
        printf("Enter medicine IDs and quantities:\n");
        for (int j = 0; j < customers[i].num_medicines; j++) {
            scanf("%d%d", &customers[i].order[j], &customers[i].order[j+1]);
            j++;
        }
    }

    // Process orders using threads
    pthread_t threads[MAX_CUSTOMERS * MAX_MEDICINES];
    int thread_index = 0;

    for (int i = 0; i < num_customers; i++) {
        for (int j = 0; j < customers[i].num_medicines; j++) {
            struct ThreadArgs* tArgs = (struct ThreadArgs*) malloc(sizeof(struct ThreadArgs));
            tArgs->customer_id = i;
            tArgs->medicine_id = customers[i].order[j];
            tArgs->quantity = customers[i].order[j+1];

            pthread_create(&threads[thread_index], NULL, place_order, (void*)tArgs);
            thread_index++;
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < thread_index; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print final stock status
    printf("\nCurrent Stock:\n");
    for (int i = 0; i < total_medicines; i++) {
        printf("Medicine %d: %d units\n", i, medicines_in_stock[i]);
    }

    return 0;
}