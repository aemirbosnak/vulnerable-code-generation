//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#define NUM_THREADS 2

// Struct representing a cafe item
typedef struct CafeItem {
    char name[50];
    double price;
} CafeItem;

// Array of cafe items
CafeItem items[] = {
    {"Coffee", 1.99},
    {"Sandwich", 4.99},
    {"Muffin", 2.49},
    {"Tea", 1.49}
};

// Global variables
double total = 0.0;
int quantities[4] = {0};

void *order(void *t) {
    int choice, quantity;
    printf("Enter item number to order: ");
    scanf("%d", &choice);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    quantities[choice - 1] += quantity;
    total += items[choice - 1].price * quantity;
    printf("Added %d %s to your order.\n", quantity, items[choice - 1].name);
    return NULL;
}

void *display_total(void *t) {
    while (1) {
        printf("Total: $%.2f\n", total);
        sleep(5);
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int rc, t;
    for (t = 0; t < NUM_THREADS; t++) {
        if (t == 0) {
            rc = pthread_create(&threads[t], NULL, order, (void *) t);
        } else if (t == 1) {
            rc = pthread_create(&threads[t], NULL, display_total, (void *) t);
        }
        if (rc) {
            printf("ERROR: return code from pthread_create() is %d\n", rc);
            exit(-1);
        }
    }
    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }
    printf("Your order:\n");
    for (t = 0; t < 4; t++) {
        if (quantities[t] > 0) {
            printf("%d %s for $%.2f each\n", quantities[t], items[t].name, items[t].price);
        }
    }
    printf("Total: $%.2f", total);
    return 0;
}