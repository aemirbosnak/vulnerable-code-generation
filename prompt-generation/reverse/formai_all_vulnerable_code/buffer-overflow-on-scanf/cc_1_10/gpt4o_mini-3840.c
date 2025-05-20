//GPT-4o-mini DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define MAX_ORDERS 50
#define MAX_ITEMS 5

typedef struct {
    int order_id;
    char items[MAX_ITEMS][20];
    int item_count;
    double total_price;
} Order;

Order orderQueue[MAX_ORDERS];
int orderCount = 0;

pthread_mutex_t lock;

void* takeOrder(void* arg) {
    pthread_mutex_lock(&lock);

    if (orderCount < MAX_ORDERS) {
        Order newOrder;
        newOrder.order_id = orderCount + 1;

        printf("Taking Order %d\n", newOrder.order_id);
        
        printf("Enter number of items (max %d): ", MAX_ITEMS);
        scanf("%d", &(newOrder.item_count));
        
        for(int i = 0; i < newOrder.item_count; i++) {
            printf("Enter item %d: ", i + 1);
            scanf("%s", newOrder.items[i]);
            // Example prices (this should be implemented in a better way ideally)
            newOrder.total_price += (rand() % 20 + 5); // Random price between $5 and $25
        }

        orderQueue[orderCount] = newOrder;
        orderCount++;
        printf("Order %d taken successfully!\n", newOrder.order_id);
    } else {
        printf("Order queue is full!\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void* processPayment(void* arg) {
    pthread_mutex_lock(&lock);

    if (orderCount > 0) {
        Order orderToPay = orderQueue[0];
        printf("Processing payment for Order %d.\n", orderToPay.order_id);

        printf("Items ordered:\n");
        for (int i = 0; i < orderToPay.item_count; i++) {
            printf(" - %s\n", orderToPay.items[i]);
        }

        printf("Total price: $%.2f\n", orderToPay.total_price);
        printf("Payment processed for Order %d.\n", orderToPay.order_id);

        // Shift orders
        for (int i = 1; i < orderCount; i++) {
            orderQueue[i - 1] = orderQueue[i];
        }
        orderCount--;
    } else {
        printf("No orders to process!\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

void* generateBill(void* arg) {
    pthread_mutex_lock(&lock);

    if (orderCount > 0) {
        Order billOrder = orderQueue[0];
        printf("Generating bill for Order %d...\n", billOrder.order_id);

        printf("Bill details:\n");
        for (int i = 0; i < billOrder.item_count; i++) {
            printf("Item: %s\n", billOrder.items[i]);
        }
        printf("Total amount: $%.2f\n", billOrder.total_price);
    } else {
        printf("No orders in queue to generate bill!\n");
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t orderThread, paymentThread, billThread;
    pthread_mutex_init(&lock, NULL);
    srand(time(NULL));

    while (1) {
        int choice;
        printf("\n1. Place Order\n2. Process Payment\n3. Generate Bill\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                pthread_create(&orderThread, NULL, takeOrder, NULL);
                pthread_join(orderThread, NULL);
                break;
            case 2:
                pthread_create(&paymentThread, NULL, processPayment, NULL);
                pthread_join(paymentThread, NULL);
                break;
            case 3:
                pthread_create(&billThread, NULL, generateBill, NULL);
                pthread_join(billThread, NULL);
                break;
            case 4:
                pthread_mutex_destroy(&lock);
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}