//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEM_NUM 10

typedef struct Item {
    char name[20];
    int quantity;
    double price;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 10, 5.0},
    {"Tea", 5, 4.0},
    {"Juice", 7, 3.5},
    {"Smoothie", 8, 4.5},
    {"Biscuits", 9, 2.0},
    {"Cookies", 6, 2.5},
    {"Brownies", 3, 3.0},
    {"Muffins", 4, 2.0},
    {"Scones", 2, 3.5},
    {"Pancakes", 6, 4.0}
};

int main() {
    int item_num, quantity, total_items = 0, total_price = 0;
    char item_name[20];

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to add items to the order
    while (1) {
        printf("Enter item name: ");
        scanf("%s", item_name);

        for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++) {
            if (strcmp(item_name, items[item_num].name) == 0) {
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                items[item_num].quantity += quantity;
                total_items++;
                total_price += items[item_num].quantity * items[item_num].price;
                break;
            }
        }

        if (item_num == MAX_ITEM_NUM) {
            printf("Item not found.\n");
        }

        // Check if the user wants to continue
        printf("Do you want to add more items? (Y/N): ");
        char continue_char;
        scanf("%c", &continue_char);

        if (continue_char == 'N') {
            break;
        }
    }

    // Calculate the total cost
    double tax = 0.1;
    double total_amount = total_price * (1 + tax);

    // Print the receipt
    printf("----------------------------------------\n");
    printf("Order Summary:\n");
    printf("Total items: %d\n", total_items);
    printf("Total price: $%.2f\n", total_price);
    printf("Tax: 10%\n");
    printf("Total amount: $%.2f\n", total_amount);
    printf("----------------------------------------\n");

    return 0;
}