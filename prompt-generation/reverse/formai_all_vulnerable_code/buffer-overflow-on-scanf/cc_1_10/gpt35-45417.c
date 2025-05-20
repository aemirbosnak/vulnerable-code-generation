//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

// Structure to hold item details
struct item {
    int item_code;
    char item_name[20];
    float item_price;
};

// Function to display menu
void display_menu(struct item menu[], int size) {
    printf("*************** MENU ***************\n\n");
    printf("CODE\t\tITEM\t\tPRICE\n");

    for(int i=0; i<size; i++) {
        printf("%d\t\t%s\t\t$%.2f\n", menu[i].item_code, menu[i].item_name, menu[i].item_price);
    }

    printf("\n");
}

// Function to calculate bill
float calculate_bill(int quantity, float price) {
    return quantity * price;
}

// Function to print bill
void print_bill(int item_code, char item_name[], int quantity, float price, float total) {
    printf("----------------------------------------------\n");
    printf("\t\t%s\n", "CAFE BILL");
    printf("----------------------------------------------\n");
    printf("ITEM CODE: %d\n", item_code);
    printf("ITEM NAME: %s\n", item_name);
    printf("QUANTITY : %d\n", quantity);
    printf("PRICE    : $%.2f\n", price);
    printf("----------------------------------------------\n");
    printf("TOTAL    : $%.2f\n", total);
    printf("----------------------------------------------\n");
}

int main() {
    struct item menu[5] = {
        {101, "Coffee", 2.99},
        {102, "Sandwich", 3.99},
        {103, "Burger", 4.99},
        {104, "Noodles", 5.99},
        {105, "Pizza", 7.99},
    };

    display_menu(menu, 5);

    int choice, quantity;
    float price, total=0.0;

    do {
        printf("Enter item CODE (0 to exit): ");
        scanf("%d", &choice);

        if(choice == 0) {
            printf("Exiting...\n");
            exit(1);
        }

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        for(int i=0; i<5; i++) {
            if(menu[i].item_code == choice) {
                price = menu[i].item_price;
                total += calculate_bill(quantity, price);
                print_bill(choice, menu[i].item_name, quantity, price, total);
                break;
            }
        }
    } while(choice != 0);

    return 0;
}