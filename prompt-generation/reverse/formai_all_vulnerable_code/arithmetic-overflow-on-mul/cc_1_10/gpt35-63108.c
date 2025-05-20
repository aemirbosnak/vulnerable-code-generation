//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Global Variables
int totalSales = 0;
int totalOrders = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Structures
typedef struct MenuItem {
    int ID;
    char itemName[20];
    int price;
} MenuItem;

typedef struct Order {
    int orderNumber;
    int itemID;
    int quantity;
} Order;

// Menu Items
MenuItem menu[5] = {
    {1, "Coffee", 50},
    {2, "Tea", 30},
    {3, "Muffin", 40},
    {4, "Sandwich", 60},
    {5, "Cake", 70}
};

// Function Declarations
void* takeOrder(void *arg);
void updateSales(int amount);
void printMenu();
void printStats();

int main() {
    int numThreads = 5;
    pthread_t threads[numThreads];
    
    printf("Welcome to the Cafe Billing System!\n");
    printMenu();
    
    for(int i = 0; i < numThreads; i++) {
        pthread_create(&threads[i], NULL, takeOrder, NULL);
    }
    
    for(int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printStats();
    return 0;
}

void* takeOrder(void *arg) {
    int orderNumber = ++totalOrders;
    printf("Order %d:\n", orderNumber);
    
    int itemID = 0;
    printf("Enter Item ID: ");
    scanf("%d", &itemID);
    
    if(itemID < 1 || itemID > 5) {
        printf("Invalid Item ID. Order cancelled.\n");
        return NULL;
    }
    
    int quantity = 0;
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    
    Order order = {orderNumber, itemID, quantity};
    int amount = menu[itemID - 1].price * quantity;
    
    pthread_mutex_lock(&mutex);
    updateSales(amount);
    pthread_mutex_unlock(&mutex);
    
    printf("Order placed successfully!\n");
    return NULL;
}

void updateSales(int amount) {
    totalSales += amount;
}

void printMenu() {
    printf("\nMENU:\n");
    printf("-------------------\n");
    for(int i = 0; i < 5; i++) {
        printf("%d. %s - Rs. %d\n", menu[i].ID, menu[i].itemName, menu[i].price);
    }
    printf("-------------------\n");
}

void printStats() {
    printf("\nSALES STATS:\n");
    printf("-------------------\n");
    printf("Total Sales: Rs. %d\n", totalSales);
    printf("Total Orders: %d\n", totalOrders);
    printf("-------------------\n");
}