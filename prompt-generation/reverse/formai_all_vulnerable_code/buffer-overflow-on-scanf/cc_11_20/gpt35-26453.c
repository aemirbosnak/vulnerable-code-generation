//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_WAREHOUSE_CAPACITY 1000

int main() {
    int warehouse[MAX_WAREHOUSE_CAPACITY];
    int current_capacity = 0;
    int input;
    printf("*** Welcome to Happy Warehouse Management System! ***\n");

    do {
        // Take user input
        printf("\n\nPlease choose an option:\n");
        printf("1 - Add item to the warehouse\n");
        printf("2 - Remove item from the warehouse\n");
        printf("3 - View current warehouse inventory\n");
        printf("4 - Exit\n");
        printf("Choice: ");
        scanf("%d", &input);

        switch (input) {
            case 1: {
                // Add item to warehouse
                if (current_capacity == MAX_WAREHOUSE_CAPACITY) {
                    printf("\nSorry, the warehouse is currently full.");
                } else {
                    printf("\nEnter the item ID: ");
                    int item_id;
                    scanf("%d", &item_id);
                    warehouse[current_capacity] = item_id;
                    current_capacity++;
                    printf("\nItem %d has been added to the warehouse.", item_id);
                }
                break;
            }
            case 2: {
                // Remove item from warehouse
                if (current_capacity == 0) {
                    printf("\nSorry, the warehouse is currently empty.");
                } else {
                    printf("\nEnter the item ID to remove: ");
                    int item_id;
                    scanf("%d", &item_id);
                    int index = -1;

                    for (int i = 0; i < current_capacity; i++) {
                        if (warehouse[i] == item_id) {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1) {
                        printf("\nSorry, item %d is not in the warehouse.", item_id);
                    } else {
                        // Shift items to fill the gap
                        for (int i = index; i < current_capacity - 1; i++) {
                            warehouse[i] = warehouse[i + 1];
                        }
                        current_capacity--;
                        printf("\nItem %d has been removed from the warehouse.", item_id);
                    }
                }
                break;
            }
            case 3: {
                // View current warehouse inventory
                if (current_capacity == 0) {
                    printf("\nThe warehouse is currently empty.");
                } else {
                    printf("\nThe current inventory is:\n");
                    for (int i = 0; i < current_capacity; i++) {
                        printf(" - Item %d\n", warehouse[i]);
                    }
                }
                break;
            }
            case 4: {
                // Exit
                printf("\nThank you for using Happy Warehouse Management System!");
                break;
            }
            default:
                printf("\nInvalid choice. Please try again.");
                break;
        }
    } while (input != 4);

    return 0;
}