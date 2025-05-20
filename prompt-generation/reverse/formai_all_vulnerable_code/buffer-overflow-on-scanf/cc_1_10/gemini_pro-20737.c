//GEMINI-pro DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Mutex to protect shared resources
pthread_mutex_t mutex;

// Conditional variable to wait for orders
pthread_cond_t cond_order;

// Data structure to represent an order
typedef struct order {
    int id;
    int quantity;
    char item[20];
    float price;
} order_t;

// Queue to store orders
order_t *queue[100];
int front = 0;
int rear = 0;

// Function to add an order to the queue
void enqueue(order_t *order) {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Add the order to the queue
    queue[rear++] = order;

    // Signal that an order has been added
    pthread_cond_signal(&cond_order);

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

// Function to get an order from the queue
order_t *dequeue() {
    // Lock the mutex
    pthread_mutex_lock(&mutex);

    // Wait for an order to be added
    while (front == rear) {
        pthread_cond_wait(&cond_order, &mutex);
    }

    // Get the order from the queue
    order_t *order = queue[front++];

    // Unlock the mutex
    pthread_mutex_unlock(&mutex);

    return order;
}

// Function to calculate the total bill
float calculate_bill(order_t *order) {
    return order->quantity * order->price;
}

// Function to print the bill
void print_bill(order_t *order) {
    printf("Order ID: %d\n", order->id);
    printf("Item: %s\n", order->item);
    printf("Quantity: %d\n", order->quantity);
    printf("Price: %.2f\n", order->price);
    printf("Total: %.2f\n", calculate_bill(order));
}

// Function to take orders from customers
void *take_orders(void *arg) {
    int id = *(int *)arg;
    order_t order;

    while (1) {
        printf("Customer %d, please enter your order (item, quantity, price): ", id);
        scanf("%s %d %f", order.item, &order.quantity, &order.price);
        order.id = id;

        // Add the order to the queue
        enqueue(&order);
    }

    return NULL;
}

// Function to process orders
void *process_orders(void *arg) {
    while (1) {
        // Get an order from the queue
        order_t *order = dequeue();

        // Calculate the bill
        float bill = calculate_bill(order);

        // Print the bill
        print_bill(order);
    }

    return NULL;
}

int main() {
    // Initialize the mutex and conditional variable
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond_order, NULL);

    // Create threads to take orders and process orders
    pthread_t threads[10];
    int ids[10];
    for (int i = 0; i < 10; i++) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, take_orders, &ids[i]);
    }
    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, process_orders, NULL);
    }

    // Join the threads
    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex and conditional variable
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond_order);

    return 0;
}