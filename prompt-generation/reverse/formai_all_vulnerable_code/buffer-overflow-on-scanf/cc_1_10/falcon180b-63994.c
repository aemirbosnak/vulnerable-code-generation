//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_ITEMS 100
#define MAX_THREADS 10

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < num_items; i++) {
        printf("Thread %d is processing item %d: %s (%d units at $%.2f)\n", thread_id, items[i].id, items[i].name, items[i].quantity, items[i].price);
        sleep(1);
    }

    printf("Thread %d finished\n", thread_id);
    return NULL;
}

int main() {
    printf("Product Inventory System\n");

    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Enter details for item %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &items[i].id);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Price: ");
        scanf("%f", &items[i].price);
        num_items++;
    }

    pthread_t threads[MAX_THREADS];
    int thread_ids[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        thread_ids[i] = i+1;
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}