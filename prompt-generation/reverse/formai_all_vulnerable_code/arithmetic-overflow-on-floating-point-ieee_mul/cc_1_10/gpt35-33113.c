//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <string.h>

// Global variables
int noOfOrders = 0;
float totalBill = 0.0;

// Structure to hold order details
struct order {
    char itemName[50];
    int qty;
    float price;
};

// Function to display menu
void displayMenu() {
    printf("-------- MENU --------\n");
    printf("1. Coffee (Rs.50)\n");
    printf("2. Sandwich (Rs.100)\n");
    printf("3. Cake (Rs.150)\n");
    printf("----------------------\n");
}

// Function to create order
void createOrder(struct order *o) {
    printf("Enter item name: ");
    scanf("%s", o->itemName);
    printf("Enter quantity: ");
    scanf("%d", &o->qty);
    switch(o->itemName[0]) {
        case '1': // For coffee
            o->price = 50;
            break;
        case '2': // For sandwich
            o->price = 100;
            break;
        case '3': // For cake
            o->price = 150;
            break;
        default: // Invalid input
            printf("Invalid item name!\n");
            break;
    }
}

// Function to print order details
void printOrder(struct order o) {
    printf("Item: %s | Quantity: %d | Price: Rs.%0.2f\n", o.itemName, o.qty, o.price);
}

// Function to calculate bill
void calculateBill(struct order o) {
    totalBill += o.qty * o.price;
}

// Function to display final bill and exit program
void exitProgram() {
    printf("Thanks for visiting! Your total bill is Rs.%0.2f\n", totalBill);
}

// Main function
int main() {
    int choice;
    struct order orders[10];
    
    while(1) {
        printf("\nWelcome to C Cafe!\n");
        printf("1. Place order\n");
        printf("2. View orders\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        
        switch(choice) {
            case 1: {
                displayMenu();
                struct order o;
                createOrder(&o);
                if(strcmp(o.itemName, "") != 0) {
                    orders[noOfOrders] = o;
                    noOfOrders++;
                    printf("Order added!\n");
                }
                break;
            }
            case 2: {
                printf("Your orders:\n");
                for(int i = 0; i < noOfOrders; i++) {
                    printOrder(orders[i]);
                }
                calculateBill(orders[0]);
                break;
            }
            case 3: {
                exitProgram();
                return 0;
            }
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    
    return 0;
}