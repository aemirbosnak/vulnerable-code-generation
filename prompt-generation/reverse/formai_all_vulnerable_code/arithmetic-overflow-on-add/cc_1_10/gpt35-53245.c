//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[20];
    int quantity;
    float price;
};

int main() {
    int choice, count = 0;
    float total = 0.0;
    struct Item menu[10];
    menu[0] = (struct Item){"Coffee", 0, 1.50};
    menu[1] = (struct Item){"Tea", 0, 1.25};
    menu[2] = (struct Item){"Coke", 0, 1.75};
    menu[3] = (struct Item){"Fries", 0, 2.00};
    menu[4] = (struct Item){"Burger", 0, 3.50};
    menu[5] = (struct Item){"Salad", 0, 3.00};
    menu[6] = (struct Item){"Pizza", 0, 5.00};
    menu[7] = (struct Item){"Pasta", 0, 4.00};
    menu[8] = (struct Item){"Chicken Wings", 0, 6.00};
    menu[9] = (struct Item){"Beer", 0, 4.50};

    printf("Welcome to the C Cafe!\n");
    printf("Here is our menu:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %-20s $%.2f\n", i+1, menu[i].name, menu[i].price);
    }

    printf("What would you like to order? Enter the item number or 0 to exit.\n");
    while (1) {
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > 10) {
            printf("Invalid choice. Please enter a number between 1 and 10 or 0 to exit.\n");
        } else {
            int index = choice - 1;
            printf("How many %s would you like?\n", menu[index].name);
            int quantity;
            scanf("%d", &quantity);
            menu[index].quantity += quantity;
            printf("%d %s added to your order.\n", quantity, menu[index].name);
            total += menu[index].price * quantity;
            count++;
        }
    }

    printf("\nThank you for your order!\n");
    printf("Here is your bill:\n");
    printf("Item Name           Quantity    Price\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < 10; i++) {
        if (menu[i].quantity > 0) {
            printf("%-20s %5d      $%.2f\n", menu[i].name, menu[i].quantity, menu[i].price);
        }
    }
    printf("-------------------------------------\n");
    printf("Total items ordered: %d\n", count);
    printf("Total amount payable: $%.2f\n", total);
    printf("Thank you, please come again!\n");

    return 0;
}