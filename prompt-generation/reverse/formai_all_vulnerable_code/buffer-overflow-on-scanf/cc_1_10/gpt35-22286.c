//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MenuItem {
    char name[50], category[20];
    int price, quantity;
};

struct Order {
    struct MenuItem menu_item;
    int order_number;
};

int generate_order_number() {
    static int orderNumber = 0;
    return ++orderNumber;
}

int main() {
    int choice, total_amount = 0, order_quantity;
    struct MenuItem menu[50];
    char item_name[50], item_category[20];
    int item_price, num_menu_items = 0;

    while (1) {
        printf("\nCurious C Cafe Billing System\n");
        printf("1. Add menu item\n2. Show menu\n3. Place order\n4. Exit\nSelect from 1-4: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter name of new menu item: ");
                scanf("%s", item_name);
                strcpy(menu[num_menu_items].name, item_name);

                printf("Enter category of new menu item: ");
                scanf("%s", item_category);
                strcpy(menu[num_menu_items].category, item_category);

                printf("Enter price of new menu item: ");
                scanf("%d", &item_price);
                menu[num_menu_items].price = item_price;

                printf("Enter quantity of new menu item: ");
                scanf("%d", &menu[num_menu_items].quantity);

                printf("New menu item added successfully!\n");
                num_menu_items++;
                break;

            case 2:
                printf("\n---MENU---\n");
                printf("%-20s %-20s %-20s\n", "NAME", "CATEGORY", "PRICE");
                for (int i = 0; i < num_menu_items; i++) {
                    printf("%-20s %-20s %-20d\n", menu[i].name, menu[i].category, menu[i].price);
                }
                break;

            case 3:
                printf("\n---PLACE ORDER---\n");
                printf("Enter item name: ");
                scanf("%s", item_name);

                for (int i = 0; i < num_menu_items; i++) {
                    if (strcmp(menu[i].name, item_name) == 0) {
                        printf("Enter quantity: ");
                        scanf("%d", &order_quantity);

                        if (menu[i].quantity >= order_quantity) {
                            total_amount += (order_quantity * menu[i].price);
                            menu[i].quantity -= order_quantity;
                            printf("Item added to order!\n");

                            struct Order order_item = {menu[i], generate_order_number()};
                            printf("Order number is %d\n", order_item.order_number);
                        } else {
                            printf("Not enough quantity available for order!\n");
                        }
                    }
                }
                break;

            case 4:
                printf("Total amount due: %d\nThank you for visiting Curious C Cafe!\n", total_amount);
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}