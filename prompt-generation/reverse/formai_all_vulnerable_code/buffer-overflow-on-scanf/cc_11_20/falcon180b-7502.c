//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_PRICE 1000

typedef struct {
    char name[MAX_NAME_LEN];
    int price;
} Item;

int main() {
    int numItems, choice;
    char name[MAX_NAME_LEN];
    int price;
    char menu[5][20] = {"1. Add item", "2. Remove item", "3. View items", "4. Exit"};
    Item items[MAX_ITEMS];
    int numItemsInMenu = 0;

    printf("Welcome to the Cafe Billing System!\n");
    printf("Please enter the number of items you wish to add: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of the %dth item: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter the price of the %dth item: ", i + 1);
        scanf("%d", &items[i].price);
    }

    do {
        printf("\nPlease select an option:\n");
        for (int i = 0; i < numItemsInMenu; i++) {
            printf("%d. %s\n", i + 1, menu[i]);
        }
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (numItems >= MAX_ITEMS) {
                    printf("You have reached the maximum number of items.\n");
                } else {
                    printf("Enter the name of the new item: ");
                    scanf("%s", name);
                    printf("Enter the price of the new item: ");
                    scanf("%d", &price);
                    strcpy(items[numItems].name, name);
                    items[numItems].price = price;
                    numItems++;
                    printf("Item added successfully!\n");
                }
                break;

            case 2:
                printf("Enter the name of the item you wish to remove: ");
                scanf("%s", name);
                for (int i = 0; i < numItems; i++) {
                    if (strcmp(items[i].name, name) == 0) {
                        for (int j = i; j < numItems - 1; j++) {
                            strcpy(items[j].name, items[j + 1].name);
                            items[j].price = items[j + 1].price;
                        }
                        numItems--;
                        printf("Item removed successfully!\n");
                        break;
                    }
                }
                break;

            case 3:
                printf("\nItem List:\n");
                for (int i = 0; i < numItems; i++) {
                    printf("%d. %s - $%d\n", i + 1, items[i].name, items[i].price);
                }
                break;

            case 4:
                printf("Thank you for using the Cafe Billing System!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}