//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Global variables
int numItems = 0;
char menuItemNames[MAX_ITEMS][MAX_NAME_LENGTH];
float menuItemPrices[MAX_ITEMS];
int menuItemQuantities[MAX_ITEMS];
float totalBill = 0.0;
bool orderComplete = false;

// Synchronization variables
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

// Function to add a new item to the menu
void addItem(char* name, float price) {
    pthread_mutex_lock(&mutex);
    if (numItems < MAX_ITEMS) {
        strcpy(menuItemNames[numItems], name);
        menuItemPrices[numItems] = price;
        menuItemQuantities[numItems] = 0;
        numItems++;
    }
    pthread_mutex_unlock(&mutex);
}

// Function to update the quantity of an item
void updateQuantity(int index, int quantity) {
    pthread_mutex_lock(&mutex);
    menuItemQuantities[index] += quantity;
    pthread_mutex_unlock(&mutex);
}

// Function to display the menu items
void displayMenu() {
    printf("Menu Items:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, menuItemNames[i], menuItemPrices[i]);
    }
    printf("\n");
}

// Function to display the current order
void displayOrder() {
    printf("Current Order:\n");
    for (int i = 0; i < numItems; i++) {
        if (menuItemQuantities[i] > 0) {
            printf("%s: %d - $%.2f\n", menuItemNames[i], menuItemQuantities[i], menuItemPrices[i]*menuItemQuantities[i]);
        }
    }
    printf("Total Bill: $%.2f\n", totalBill);
    printf("\n");
}

// Function to handle the billing process
void* billingProcess(void *arg) {
    while (!orderComplete) {
        pthread_mutex_lock(&mutex);
        while (totalBill == 0.0) {
            pthread_cond_wait(&cond, &mutex);
        }
        printf("\nTotal Bill: $%.2f\n", totalBill);
        printf("Thank you for your order!\n");
        totalBill = 0.0;
        orderComplete = false;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

// Main function to handle user input
int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, billingProcess, NULL);
    printf("Welcome to C Cafe!\n");
    printf("------------------\n");
    printf("Please select an option:\n");
    printf("1. Add Item to Menu\n");
    printf("2. Update Item Quantity\n");
    printf("3. Display Menu\n");
    printf("4. Display Current Order\n");
    printf("5. Complete Order\n");
    printf("6. Exit\n");

    while (true) {
        int option;
        printf("Enter option number: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Enter item name: ");
                char name[MAX_NAME_LENGTH];
                scanf("%s", name);
                printf("Enter item price: ");
                float price;
                scanf("%f", &price);
                addItem(name, price);
                break;
            }
            case 2: {
                displayMenu();
                printf("Select item number: ");
                int itemNum;
                scanf("%d", &itemNum);
                if (itemNum < 1 || itemNum > numItems) {
                    printf("Invalid item number!\n");
                    break;
                }
                printf("Enter quantity: ");
                int quantity;
                scanf("%d", &quantity);
                updateQuantity(itemNum-1, quantity);
                break;
            }
            case 3: {
                displayMenu();
                break;
            }
            case 4: {
                displayOrder();
                break;
            }
            case 5: {
                pthread_mutex_lock(&mutex);
                totalBill = 0.0;
                for (int i = 0; i < numItems; i++) {
                    totalBill += menuItemQuantities[i] * menuItemPrices[i];
                }
                printf("Your total bill is $%.2f\n", totalBill);
                orderComplete = true;
                pthread_cond_signal(&cond);
                pthread_mutex_unlock(&mutex);
                break;
            }
            case 6: {
                printf("Thank you for visiting C Cafe!\n");
                exit(0);
            }
            default: {
                printf("Invalid option!\n");
                break;
            }
        }
    }
    return 0;
}