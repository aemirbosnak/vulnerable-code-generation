//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int choice, i, n = 0;
    float total = 0.0;
    struct medicine inventory[100];
    char search[50];

    printf("Welcome to XYZ Medical Store\n");

    while (1) {
        printf("-----------------------------\n");
        printf("What would you like to do?\n");
        printf("1. Add medicine to inventory\n");
        printf("2. Search medicine by name\n");
        printf("3. Buy medicine\n");
        printf("4. Check inventory status\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many medicines do you want to add? ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Enter name of medicine: ");
                    scanf("%s", inventory[i].name);
                    printf("Enter price of medicine: ");
                    scanf("%f", &(inventory[i].price));
                    printf("Enter quantity of medicine: ");
                    scanf("%d", &(inventory[i].quantity));
                    printf("Medicine added to inventory!\n");
                }
                break;
            case 2:
                printf("Enter name of medicine to search: ");
                scanf("%s", search);
                for (i = 0; i < n; i++) {
                    if (strcmp(inventory[i].name, search) == 0) {
                        printf("Name: %s\nPrice: %.2f\nQuantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
                    }
                }
                break;
            case 3:
                printf("Enter name of medicine to buy: ");
                scanf("%s", search);
                for (i = 0; i < n; i++) {
                    if (strcmp(inventory[i].name, search) == 0) {
                        if (inventory[i].quantity == 0) {
                            printf("Sorry, medicine is out of stock.\n");
                        } else {
                            printf("Price of %s is %.2f. How many do you want to buy? ", inventory[i].name, inventory[i].price);
                            int num;
                            scanf("%d", &num);
                            if (num > inventory[i].quantity) {
                                printf("Sorry, we do not have enough stock for that amount.\n");
                            } else {
                                inventory[i].quantity -= num;
                                total += (num * inventory[i].price);
                                printf("You have bought %d of %s for a total of %.2f\n", num, inventory[i].name, (num * inventory[i].price));
                            }
                        }
                    }
                }
                break;
            case 4:
                printf("Inventory status:\n");
                for (i = 0; i < n; i++) {
                    printf("Name: %s\nPrice: %.2f\nQuantity: %d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
                }
                break;
            case 5:
                printf("Thank you for using XYZ Medical Store!\n");
                printf("Total revenue: %.2f", total);
                exit(0);
            default:
                printf("Invalid input, please enter a number from 1-5.\n");
        }
    }

    return 0;
}