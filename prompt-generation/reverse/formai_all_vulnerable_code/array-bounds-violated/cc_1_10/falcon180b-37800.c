//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// Define the maximum number of products in the warehouse
#define MAX_PRODUCTS 100

// Define the number of threads
#define NUM_THREADS 3

// Define the number of producers
#define NUM_PRODUCERS 1

// Define the number of consumers
#define NUM_CONSUMERS 2

// Define the structure of a product
typedef struct {
    int id;
    int quantity;
} Product;

// Define the structure of a thread argument
typedef struct {
    int id;
} ThreadArg;

// Define the global variables
Product products[MAX_PRODUCTS];
int num_products = 0;
int finished = 0;

// Define the semaphores
sem_t mutex;
sem_t empty;
sem_t full;

// Define the functions
void *producer(void *arg);
void *consumer(void *arg);

// Define the main function
int main() {
    // Initialize the semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, MAX_PRODUCTS);
    sem_init(&full, 0, 0);

    // Create the threads
    pthread_t threads[NUM_THREADS];
    ThreadArg args[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        args[i].id = i;
        if (i < NUM_PRODUCERS) {
            pthread_create(&threads[i], NULL, producer, &args[i]);
        } else {
            pthread_create(&threads[i], NULL, consumer, &args[i]);
        }
    }

    // Wait for the threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

// Define the producer function
void *producer(void *arg) {
    ThreadArg *t_arg = (ThreadArg *) arg;
    int id = t_arg->id;

    // Produce products
    for (int i = 0; i < 10; i++) {
        Product product;
        product.id = i + 1;
        product.quantity = i + 1;

        // Wait until there is space in the warehouse
        sem_wait(&empty);

        // Add the product to the warehouse
        sem_wait(&mutex);
        products[num_products++] = product;
        sem_post(&mutex);

        // Signal that a product has been added
        sem_post(&full);

        sleep(1);
    }

    return NULL;
}

// Define the consumer function
void *consumer(void *arg) {
    ThreadArg *t_arg = (ThreadArg *) arg;
    int id = t_arg->id;

    // Consume products
    for (int i = 0; i < 10; i++) {
        // Wait until there is a product in the warehouse
        sem_wait(&full);

        // Remove a product from the warehouse
        sem_wait(&mutex);
        Product product = products[--num_products];
        sem_post(&mutex);

        printf("Consumer %d consumed product %d with quantity %d\n", id, product.id, product.quantity);

        // Signal that a product has been removed
        sem_post(&empty);

        sleep(1);
    }

    return NULL;
}