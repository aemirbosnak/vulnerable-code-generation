//FormAI DATASET v1.0 Category: Product Inventory System ; Style: medieval
#include <stdio.h>
#include <string.h>

struct item {
    char name[20];
    int quantity;
    float price;
};

void printMenu() {
    printf("\n\nWelcome to the Medieval Market!\n\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. Update item quantity\n");
    printf("4. Display inventory\n");
    printf("5. Exit\n");
    printf("\nEnter your choice: ");
}

int main() {
    int choice, i, flag, update_qty;
    char item_name[20];
    struct item inventory[100];

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add item to inventory
                printf("\nEnter item name: ");
                scanf("%s", item_name);
                printf("Enter item quantity: ");
                scanf("%d", &inventory[i].quantity);
                printf("Enter item price: ");
                scanf("%f", &inventory[i].price);

                // Copy item name into struct
                strcpy(inventory[i].name, item_name);
                i++;
                break;
            case 2:
                // Remove item from inventory
                printf("\nEnter item name: ");
                scanf("%s", item_name);

                flag = 0;
                for(int j=0; j<i; j++) {
                    if(strcmp(inventory[j].name, item_name) == 0) {
                        flag = 1;
                        // Shift array elements to remove item
                        for(int k=j; k<i-1; k++) {
                            strcpy(inventory[k].name, inventory[k+1].name);
                            inventory[k].quantity = inventory[k+1].quantity;
                            inventory[k].price = inventory[k+1].price;
                        }
                        i--;
                        printf("\n%s removed from inventory.", item_name);
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\n%s not found in inventory.", item_name);
                }
                break;
            case 3:
                // Update item quantity
                printf("\nEnter item name: ");
                scanf("%s", item_name);

                flag = 0;
                for(int j=0; j<i; j++) {
                    if(strcmp(inventory[j].name, item_name) == 0) {
                        flag = 1;
                        printf("\nEnter updated quantity: ");
                        scanf("%d", &update_qty);
                        inventory[j].quantity = update_qty;
                        printf("\n%s updated to %d.", item_name, update_qty);
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\n%s not found in inventory.", item_name);
                }
                break;
            case 4:
                // Display inventory
                printf("\n-------INVENTORY-------\n");
                for(int j=0; j<i; j++) {
                    printf("Item: %s\t Quantity: %d\t Price: %.2f\n", inventory[j].name, inventory[j].quantity, inventory[j].price);
                }
                break;
            case 5:
                // Exit
                printf("\nThank you for visiting the Medieval Market!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
        }

    } while(choice != 5);

    return 0;
}