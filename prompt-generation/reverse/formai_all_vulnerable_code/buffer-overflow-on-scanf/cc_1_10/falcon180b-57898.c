//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} product;

product products[MAX_PRODUCTS];
int num_products = 0;

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;
    printf("Thread %d started\n", thread_id);

    for (int i = 0; i < num_products; i++) {
        printf("Thread %d: Product %d - %s, Quantity: %d, Price: %.2f\n", thread_id, products[i].id, products[i].name, products[i].quantity, products[i].price);
    }

    printf("Thread %d finished\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("Enter product details for product %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &products[i].id);
        printf("Name: ");
        scanf("%s", products[i].name);
        printf("Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Price: ");
        scanf("%f", &products[i].price);
        num_products++;
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}