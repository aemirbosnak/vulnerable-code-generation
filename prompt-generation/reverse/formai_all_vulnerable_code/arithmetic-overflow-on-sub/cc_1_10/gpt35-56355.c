//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structure to hold the information of a particular item
struct item {
    char name[20];
    int price;
};

void displayMenu(struct item menu[], int n) {
    printf("MENU:\n");
    for(int i=0; i<n; i++) {
        printf("%d) Name: %s | Price: %d\n", i+1, menu[i].name, menu[i].price);
    }
}

// function to place an order
void placeOrder(struct item menu[], int n, int order_list[], int quantity[], int *num_orders, int *total_bill) {

    int more=1, choice, qty;
    while(more) {
        printf("\nEnter the item number you want to order: ");
        scanf("%d", &choice);
        printf("Enter the quantity: ");
        scanf("%d", &qty);

        if(choice-1 < 0 || choice-1 >= n) {
            printf("Invalid choice!\n");
            continue;
        }

        // updating the order list and quantity
        order_list[*num_orders] = choice-1;
        quantity[*num_orders] = qty;
        *num_orders += 1;

        // updating the total bill
        *total_bill += qty*menu[choice-1].price;

        // asking if they want to order more items
        printf("\nDo you want to order more items? (1 for Yes, 0 for No): ");
        scanf("%d", &more);
    }
}

// function to display the bill
void printBill(struct item menu[], int order_list[], int quantity[], int num_orders, int total_bill) {
    printf("\nBILL:\n");
    for(int i=0; i<num_orders; i++) {
        printf("%d) Name: %s | Price: %d | Quantity: %d\n", i+1, menu[order_list[i]].name, menu[order_list[i]].price, quantity[i]);
    }
    printf("\nTotal Bill: %d\n", total_bill);
}

int main() {

    // defining the items in the menu
    struct item menu[] = {{"Cappucino", 120},
                          {"Espresso", 80},
                          {"Americano", 90},
                          {"Cafe Latte", 130},
                          {"Iced Coffee", 150}};

    int n=sizeof(menu)/sizeof(menu[0]);

    int order_list[n], quantity[n];
    int num_orders = 0;
    int total_bill=0;

    printf("Welcome to our Cafe Billing System!\n");
    displayMenu(menu, n);

    // placing the order
    printf("\n\n");
    placeOrder(menu, n, order_list, quantity, &num_orders, &total_bill);

    // printing the bill
    printf("\n\n");
    printBill(menu, order_list, quantity, num_orders, total_bill);

    return 0;
}