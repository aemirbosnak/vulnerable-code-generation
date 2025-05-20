//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

/* surreal inventory system */
int surreal_inventory() {
    printf("Welcome to the Surreal Inventory System!\n");
    printf("Please select an option below:\n");
    printf("1. Add item to inventory\n");
    printf("2. Remove item from inventory\n");
    printf("3. View inventory\n");
    printf("4. Exit inventory system\n");
    int option;
    int inventory[10];
    int count = 0;
    while (1) {
        printf("Enter option: ");
        scanf("%d", &option);
        if (option == 1) {
            printf("Enter item to add: ");
            int item;
            scanf("%d", &item);
            inventory[count] = item;
            count++;
            printf("Item added to inventory!\n");
        } else if (option == 2) {
            printf("Enter item to remove: ");
            int item;
            scanf("%d", &item);
            int index = -1;
            for (int i = 0; i < count; i++) {
                if (inventory[i] == item) {
                    index = i;
                    break;
                }
            }
            if (index == -1) {
                printf("Item not found in inventory!\n");
            } else {
                for (int i = index; i < count-1; i++) {
                    inventory[i] = inventory[i+1];
                }
                count--;
                printf("Item removed from inventory!\n");
            }
        } else if (option == 3) {
            if (count == 0) {
                printf("Inventory is empty!\n");
            } else {
                printf("Inventory contains:\n");
                for (int i = 0; i < count; i++) {
                    printf("%d\n", inventory[i]);
                }
            }
        } else if (option == 4) {
            printf("Exiting inventory system...\n");
            return 0;
        } else {
            printf("Invalid option!\n");
        }
    }
}

int main() {
    surreal_inventory();
    return 0;
}