//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define MAX_ORDERS 100

typedef struct {
    int order_id;
    char item[30];
    float price;
} Order;

Order orders[MAX_ORDERS];
int order_count = 0;
pthread_mutex_t order_mutex;

void* take_order(void* arg) {
    while (1) {
        pthread_mutex_lock(&order_mutex);
        if (order_count < MAX_ORDERS) {
            Order new_order;
            new_order.order_id = order_count + 1;

            printf("Enter item name: ");
            scanf("%s", new_order.item);

            printf("Enter price: ");
            scanf("%f", &new_order.price);

            orders[order_count] = new_order;
            printf("Order ID: %d, Item: %s, Price: %.2f has been taken!\n", 
                   new_order.order_id, new_order.item, new_order.price);
            order_count++;
        } else {
            printf("Order limit reached, no more orders can be taken.\n");
        }
        pthread_mutex_unlock(&order_mutex);
        
        sleep(1);
    }
    return NULL;
}

void* process_bills(void* arg) {
    while (1) {
        pthread_mutex_lock(&order_mutex);
        if (order_count > 0) {
            Order order_to_bill = orders[--order_count];
            printf("Processing bill for Order ID: %d, Item: %s, Price: %.2f\n", 
                   order_to_bill.order_id, order_to_bill.item, order_to_bill.price);
            printf("Bill processed for Order ID: %d. Thank you for your visit!\n\n", order_to_bill.order_id);
        }
        pthread_mutex_unlock(&order_mutex);
        
        sleep(2);  // Simulate time taken to process bill
    }
    return NULL;
}

int main() {
    pthread_t order_thread, bill_thread;

    pthread_mutex_init(&order_mutex, NULL);

    // Creating threads for taking orders and processing bills
    pthread_create(&order_thread, NULL, take_order, NULL);
    pthread_create(&bill_thread, NULL, process_bills, NULL);

    // Joining threads (in this case, they will run indefinitely)
    pthread_join(order_thread, NULL);
    pthread_join(bill_thread, NULL);

    pthread_mutex_destroy(&order_mutex);
    return 0;
}