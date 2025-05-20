//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void *thread_func(void *param) {
    int thread_id = *(int *) param;

    printf("Thread %d started.\n", thread_id);

    // Simulate some work
    for (int i = 0; i < 10; i++) {
        printf("Thread %d is working...\n", thread_id);
        sleep(1);
    }

    pthread_exit(0);
}

int main() {
    pthread_t threads[NUM_THREADS];

    // Create items
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("Enter item %d details:\n", i+1);
        scanf("%d %s %f %d", &items[i].id, items[i].name, &items[i].price, &items[i].quantity);
        num_items++;
    }

    // Print items
    printf("\n medical items:\n");
    for (int i = 0; i < num_items; i++) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);
    }

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    // Join threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}