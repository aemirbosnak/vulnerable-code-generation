//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Item;

int main() {
    int num_items = 0;
    Item items[MAX_ITEMS];

    while (num_items < MAX_ITEMS) {
        printf("Enter the name of the item: ");
        scanf("%s", items[num_items].name);

        printf("Enter the price of the item: ");
        scanf("%s", items[num_items].price);

        num_items++;
    }

    printf("\n");

    int choice = 0;
    while (choice!= 4) {
        printf("1. View all items\n");
        printf("2. Add an item\n");
        printf("3. Remove an item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            for (int i = 0; i < num_items; i++) {
                printf("%s - %s\n", items[i].name, items[i].price);
            }
            break;
        case 2:
            printf("Enter the name of the item: ");
            scanf("%s", items[num_items].name);

            printf("Enter the price of the item: ");
            scanf("%s", items[num_items].price);

            num_items++;
            printf("\nItem added!\n");
            break;
        case 3:
            printf("Enter the name of the item you want to remove: ");
            scanf("%s", items[num_items - 1].name);

            for (int i = 0; i < num_items - 1; i++) {
                strcpy(items[i].name, items[i + 1].name);
                strcpy(items[i].price, items[i + 1].price);
            }

            num_items--;
            printf("\nItem removed!\n");
            break;
        case 4:
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}