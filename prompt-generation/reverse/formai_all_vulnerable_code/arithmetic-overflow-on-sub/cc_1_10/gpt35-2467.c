//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

struct product{      //defining a structure to store products and their details
    char name[50];
    int pid;
    float price;
};

struct order{        //defining a structure to store details of orders
    struct product p;
    int quantity;
    float total;
};

void printMenu(struct product[], int);    //function to print the menu
void newOrder(struct order[], struct product[], int);   //function to take order from customer
void printBill(struct order[], int);    //function to print the final bill

int main(){

    struct product menu[5] = {{"Espresso", 1, 2.5},
                         {"Latte", 2, 3.5},
                         {"Cappuccino", 3, 4.5},
                         {"Mocha", 4, 5.5},
                         {"Iced Coffee", 5, 6.5}};   //creating an array of products

    int totalOrders = 0;    //variable to store total number of orders
    struct order orders[50];   //creating an array of orders

    printf("Welcome to CafeX Billing System\n\n");

    int choice = 0;
    while(choice!=3){      //loop to display the menu until customer chooses to exit
        printf("Please choose an option:\n1. Display Menu\n2. New Order\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printMenu(menu, 5);    //calling function to print menu
                break;
            case 2:
                newOrder(orders, menu, totalOrders);   //calling function to take new order
                totalOrders++;
                break;
            case 3:
                printf("Thank you for using CafeX Billing System. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    printBill(orders, totalOrders);   //calling function to print final bill

    return 0;
}

void printMenu(struct product menu[], int n){   //function to print the menu
    printf("Menu:\n");
    printf("------------------------------\n");
    printf("| %-12s | %-4s | %-6s |\n", "Product", "ID", "Price");
    printf("------------------------------\n");
    for(int i=0; i<n; i++){
        printf("| %-12s | %-4d | $%-5.2f |\n", menu[i].name, menu[i].pid, menu[i].price);
    }
    printf("------------------------------\n\n");
}

void newOrder(struct order orders[], struct product menu[], int totalOrders){   //function to take order from customer
    int pid=0, quantity=0;
    printf("Please enter product ID: ");
    scanf("%d", &pid);
    printf("Please enter quantity: ");
    scanf("%d", &quantity);

    struct order o = {menu[pid-1], quantity, quantity * menu[pid-1].price};  //creating new order and calculating total
    orders[totalOrders] = o;   //adding order to array of orders
    printf("Order accepted successfully!\n\n");
}

void printBill(struct order orders[], int totalOrders){   //function to print the final bill
    float subTotal=0, serviceCharge=0, tax=0, total=0;

    printf("CafeX Bill\n");
    printf("-------------------------------------------------\n");
    printf("| %-12s | %-4s | %-8s | %-8s |\n", "Product", "Qty", "Price", "Total");
    printf("-------------------------------------------------\n");
    for(int i=0; i<totalOrders; i++){
        printf("| %-12s | %-4d | $%-6.2f | $%-6.2f |\n", orders[i].p.name, orders[i].quantity, orders[i].p.price, orders[i].total);
        subTotal += orders[i].total;   //calculating subtotal
    }
    printf("-------------------------------------------------\n");
    serviceCharge = (0.1 * subTotal);   //calculating service charge
    tax = (0.15 * subTotal);    //calculating tax
    total = subTotal + serviceCharge + tax;   //calculating total

    printf("Subtotal: $%.2f\n", subTotal);
    printf("Service Charge (10%%): $%.2f\n", serviceCharge);
    printf("Tax (15%%): $%.2f\n", tax);
    printf("Total: $%.2f\n", total);
}