//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS];

int main() {

    int i, item_count = 0;
    float total_amount = 0.0f;

    // Create a loop to add items to the list
    while (1) {
        printf("Enter item name: ");
        scanf("%s", items[item_count].name);

        printf("Enter item quantity: ");
        scanf("%d", &items[item_count].quantity);

        printf("Enter item price: ");
        scanf("%f", &items[item_count].price);

        item_count++;

        // Check if the user wants to continue or quit
        char answer;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &answer);

        if (answer == 'N') {
            break;
        }
    }

    // Calculate the total amount
    for (i = 0; i < item_count; i++) {
        total_amount += items[i].quantity * items[i].price;
    }

    // Print the bill
    printf("--------------------------------------------------------\n");
    printf("Items:\n");
    for (i = 0; i < item_count; i++) {
        printf("%s - %d @ %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("Total Amount: %.2f\n", total_amount);
    printf("--------------------------------------------------------\n");

    return 0;
}