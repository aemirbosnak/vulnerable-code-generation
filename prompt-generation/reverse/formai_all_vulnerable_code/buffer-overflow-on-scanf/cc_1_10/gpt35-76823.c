//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_ORDERS 100
#define NUM_THREADS 4

// Global variables
int inventory = 20;
float total_bill = 0;
pthread_mutex_t mutex_inventory;
pthread_mutex_t mutex_bill;

// Order data structure
typedef struct order_t {
    int table_number;
    char item[50];
    float price;
} Order;

// Menu definition
Order menu[] = {
    {1, "Coffee", 2.50},
    {2, "Tea", 1.75},
    {3, "Croissant", 2.00},
    {4, "Sandwich", 3.50},
};

// Orders queue
Order orders[MAX_ORDERS];
int num_orders = 0;

// Thread function for taking orders
void* take_order(void* arg) {
    int table_number;
    char item[50];
    float price;
    Order order;
    
    while (1) {
        // Acquire lock on the inventory
        pthread_mutex_lock(&mutex_inventory);
        
        // Check if we have enough items in the inventory
        if (inventory > 0) {
            
            // Decrement inventory count
            inventory--;
            
            // Release lock on the inventory
            pthread_mutex_unlock(&mutex_inventory);
            
            // Get order information
            printf("Table number: ");
            scanf("%d", &table_number);
            printf("Item: ");
            scanf("%s", item);
            
            // Look up item in the menu
            for (int i = 0; i < sizeof(menu)/sizeof(Order); i++) {
                if (strcmp(item, menu[i].item) == 0) {
                    
                    // Add order to the queue
                    order.table_number = table_number;
                    strcpy(order.item, menu[i].item);
                    order.price = menu[i].price;
                    
                    // Acquire lock on the order queue
                    pthread_mutex_lock(&mutex_bill);
                    
                    if (num_orders < MAX_ORDERS) {
                        orders[num_orders++] = order;
                        total_bill += order.price;
                    } else {
                        printf("Sorry, maximum number of orders reached.\n");
                    }
                    
                    // Release lock on the order queue
                    pthread_mutex_unlock(&mutex_bill);
                    
                    break;
                }
            }
            
        } else {
            // Release lock on the inventory
            pthread_mutex_unlock(&mutex_inventory);
        }
    }
    
    return NULL;
}

// Thread function for serving orders
void* serve_order(void* arg) {
    int table_number;
    while (1) {
        if (num_orders > 0) {
            Order order = orders[--num_orders];
            
            // Acquire lock on the bill
            pthread_mutex_lock(&mutex_bill);
            total_bill -= order.price;
            pthread_mutex_unlock(&mutex_bill);
            
            // Serve order
            printf("Serving %s to table %d\n", order.item, order.table_number);
            printf("Total bill: %.2f\n", total_bill);
            
            // Sleep for some time
            sleep(1);
        } else {
            // Sleep for some time
            sleep(1);
        }
    }
    return NULL;
}

int main() {
    // Initialize mutexes
    pthread_mutex_init(&mutex_inventory, NULL);
    pthread_mutex_init(&mutex_bill, NULL);
    
    // Create threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (i % 2 == 0) {
            pthread_create(&threads[i], NULL, take_order, NULL);
        } else {
            pthread_create(&threads[i], NULL, serve_order, NULL);
        }
    }
    
    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // Clean up mutexes
    pthread_mutex_destroy(&mutex_inventory);
    pthread_mutex_destroy(&mutex_bill);
    
    return 0;
}