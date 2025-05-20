//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PRODUCTS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

void add_product() {
    char name[50];
    int quantity;
    float price;

    printf("Enter product name: ");
    scanf("%s", name);

    printf("Enter product quantity: ");
    scanf("%d", &quantity);

    printf("Enter product price: ");
    scanf("%f", &price);

    strcpy(products[num_products].name, name);
    products[num_products].quantity = quantity;
    products[num_products].price = price;

    num_products++;
}

void display_products() {
    int i;

    printf("\nProduct List:\n");
    for (i = 0; i < num_products; i++) {
        printf("%s - %d units - $%.2f\n", products[i].name, products[i].quantity, products[i].price);
    }
}

void *thread_func(void *arg) {
    int thread_id = *(int *) arg;

    printf("Thread %d started...\n", thread_id);
    sleep(1);

    add_product();

    printf("Thread %d finished...\n", thread_id);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, thread_id;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &i);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    display_products();

    return 0;
}