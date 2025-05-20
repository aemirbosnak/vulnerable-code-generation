//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: interoperable
#include <stdio.h>
#include <string.h>

typedef struct menu_item {
    char name[50];
    float price;
} MenuItem;

typedef struct order_item {
    MenuItem menu_item;
    int quantity;
    float total_price;
} OrderItem;

int main() {

    // Define menu items
    MenuItem caff_latte = {"Caff Latte", 4.50};
    MenuItem espresso = {"Espresso", 3.00};
    MenuItem cappuccino = {"Cappuccino", 4.00};
    MenuItem americano = {"Americano", 3.50};

    // Define current order
    OrderItem current_order[50];
    int order_count = 0;

    // Define variables for input
    char input[50];
    int quantity;

    // Display menu and take order
    while (1) {
        printf("\nMenu:\n");
        printf("1. %s - $%.2f\n", caff_latte.name, caff_latte.price);
        printf("2. %s - $%.2f\n", espresso.name, espresso.price);
        printf("3. %s - $%.2f\n", cappuccino.name, cappuccino.price);
        printf("4. %s - $%.2f\n", americano.name, americano.price);
        printf("5. Checkout\n");
        printf("\nEnter item number (1-5): ");

        fgets(input, sizeof(input), stdin);

        // Remove newline character from input
        int len = strlen(input);
        if (input[len-1] == '\n') {
            input[len-1] = '\0';
        }

        // Take order
        if (strcmp(input, "1") == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            getchar(); // Remove newline character
            current_order[order_count].menu_item = caff_latte;
            current_order[order_count].quantity = quantity;
            current_order[order_count].total_price = quantity * caff_latte.price;
            order_count++;
        } else if (strcmp(input, "2") == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            getchar();
            current_order[order_count].menu_item = espresso;
            current_order[order_count].quantity = quantity;
            current_order[order_count].total_price = quantity * espresso.price;
            order_count++;
        } else if (strcmp(input, "3") == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            getchar();
            current_order[order_count].menu_item = cappuccino;
            current_order[order_count].quantity = quantity;
            current_order[order_count].total_price = quantity * cappuccino.price;
            order_count++;
        } else if (strcmp(input, "4") == 0) {
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            getchar();
            current_order[order_count].menu_item = americano;
            current_order[order_count].quantity = quantity;
            current_order[order_count].total_price = quantity * americano.price;
            order_count++;
        } else if (strcmp(input, "5") == 0) {
            break;
        } else {
            printf("\nInvalid input, please try again.\n");
        }
    }

    // Display receipt
    printf("\nReceipt:\n");
    float total_price = 0;
    for (int i = 0; i < order_count; i++) {
        printf("%2d. %dx %s - $%.2f\n", i+1, current_order[i].quantity, current_order[i].menu_item.name, current_order[i].total_price);
        total_price += current_order[i].total_price;
    }
    printf("Total: $%.2f\n", total_price);

    return 0;
}