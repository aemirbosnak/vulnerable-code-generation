//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[20];
    int price;
};

int main() {
    struct Item menu[10] = { {"Coffee", 50}, {"Tea", 40}, {"Pastry", 60}, {"Sandwich", 80}, {"Burger", 100}, {"Pizza", 200}, {"Fries", 50}, {"Salad", 150}, {"Juice", 70}, {"Smoothie", 90} };

    int order[10] = { 0 };
    int total_items = 0;

    int choice;
    do {
        printf("\n\nWelcome to C Cafe Billing System!\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. View Order\n");
        printf("4. Calculate Total Bill\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMenu\n");
                for (int i = 0; i < 10; i++)
                    printf("%d. %s\tRs. %d\n", i+1, menu[i].name, menu[i].price);
                break;

            case 2:
                printf("\nEnter the item number and quantity to order (0 to exit): ");
                int item_num, qty;
                scanf("%d %d", &item_num, &qty);
                if (item_num == 0)
                    break;
                else if (item_num < 1 || item_num > 10) {
                    printf("Invalid item number!\n");
                    break;
                }
                order[item_num-1] += qty;
                total_items += qty;
                break;

            case 3:
                printf("\nOrder\n");
                for (int i = 0; i < 10; i++)
                    if (order[i] > 0)
                        printf("%d. %s\tQty. %d\n", i+1, menu[i].name, order[i]);
                break;

            case 4:
                printf("\nTotal Bill\n");
                int total = 0;
                for (int i = 0; i < 10; i++)
                    if (order[i] > 0)
                        total += menu[i].price * order[i];
                printf("Total items ordered: %d\n", total_items);
                printf("Total amount payable: Rs. %d\n", total);
                break;

            case 5:
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 5);

    printf("\nThank you for using C Cafe Billing System!\n");
    return 0;
}