//Falcon-180B DATASET v1.0 Category: Product Inventory System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_PRODUCTS 1000
#define MAX_THREADS 10

typedef struct {
    char name[50];
    int quantity;
    int price;
} Product;

Product products[MAX_PRODUCTS];
int num_products = 0;

pthread_mutex_t product_mutex = PTHREAD_MUTEX_INITIALIZER;

void add_product(Product* product) {
    pthread_mutex_lock(&product_mutex);
    if (num_products < MAX_PRODUCTS) {
        products[num_products] = *product;
        num_products++;
    }
    pthread_mutex_unlock(&product_mutex);
}

void print_products() {
    pthread_mutex_lock(&product_mutex);
    for (int i = 0; i < num_products; i++) {
        printf("%s - %d in stock - $%d\n", products[i].name, products[i].quantity, products[i].price);
    }
    pthread_mutex_unlock(&product_mutex);
}

void* thread_func(void* arg) {
    int thread_num = *(int*)arg;
    char name[50];
    int quantity;
    int price;

    printf("Thread %d starting...\n", thread_num);

    while (1) {
        printf("Enter product name: ");
        scanf("%s", name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price: ");
        scanf("%d", &price);

        Product product = {.name = name,.quantity = quantity,.price = price };
        add_product(&product);

        printf("Product added successfully!\n");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void*)i);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_products();

    return 0;
}