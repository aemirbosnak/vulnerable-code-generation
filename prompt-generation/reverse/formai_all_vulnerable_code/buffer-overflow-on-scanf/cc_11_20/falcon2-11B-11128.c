//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: sophisticated
#include <stdio.h>

#define MAX_ITEMS 100

int main() {
    int items[MAX_ITEMS];
    int item_count = 0;
    int item_index = 0;

    printf("Welcome to the Warehouse Management System!\n");
    printf("1. Add an item\n");
    printf("2. Remove an item\n");
    printf("3. List all items\n");
    printf("4. Quit\n");

    while (1) {
        printf("Please choose an option: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the item number: ");
            int item_number;
            scanf("%d", &item_number);

            if (item_count < MAX_ITEMS) {
                items[item_count] = item_number;
                item_count++;
                printf("Item %d added to the inventory.\n", item_number);
            } else {
                printf("Inventory is full.\n");
            }
        } else if (choice == 2) {
            printf("Enter the item number to remove: ");
            int item_number;
            scanf("%d", &item_number);

            if (item_number >= 0 && item_number < item_count) {
                items[item_number] = -1;
                item_count--;
                printf("Item %d removed from the inventory.\n", item_number);
            } else {
                printf("Item not found in the inventory.\n");
            }
        } else if (choice == 3) {
            if (item_count > 0) {
                printf("Item #:\tItem\n");
                for (int i = 0; i < item_count; i++) {
                    if (items[i]!= -1) {
                        printf("%d:\t%d\n", i+1, items[i]);
                    }
                }
            } else {
                printf("Inventory is empty.\n");
            }
        } else if (choice == 4) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}