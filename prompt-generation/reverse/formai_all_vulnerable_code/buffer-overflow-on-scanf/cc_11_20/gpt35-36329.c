//FormAI DATASET v1.0 Category: Product Inventory System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char name[50];
    int id;
    float price;
    int quantity;
    struct item *next;
} Item;

int main() {
    Item *head = NULL;
    int choice;

    while (1) {
        printf("\n*** Product Inventory System ***\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                Item *newItem = malloc(sizeof(Item));
                printf("Enter item name: ");
                scanf("%s", newItem->name);
                printf("Enter item ID: ");
                scanf("%d", &newItem->id);
                printf("Enter item price: ");
                scanf("%f", &newItem->price);
                printf("Enter item quantity: ");
                scanf("%d", &newItem->quantity);
                newItem->next = head;
                head = newItem;
                printf("Item added successfully!\n");
                break;
            }
            case 2: {
                int idToRemove;
                printf("Enter item ID to remove: ");
                scanf("%d", &idToRemove);
                if (head == NULL) {
                    printf("Inventory is empty!\n");
                } else if (head->id == idToRemove) {
                    Item *temp = head;
                    head = head->next;
                    free(temp);
                    printf("Item removed successfully!\n");
                } else {
                    Item *current = head;
                    while (current->next != NULL && current->next->id != idToRemove) {
                        current = current->next;
                    }
                    if (current->next == NULL) {
                        printf("Item not found in inventory!\n");
                    } else {
                        Item *temp = current->next;
                        current->next = current->next->next;
                        free(temp);
                        printf("Item removed successfully!\n");
                    }
                }
                break;
            }
            case 3: {
                Item *current = head;
                if (current == NULL) {
                    printf("Inventory is empty!\n");
                } else {
                    printf("%-50s %-10s %-10s %-10s\n", "Item Name", "Item ID", "Price", "Quantity");
                    while (current != NULL) {
                        printf("%-50s %-10d %-10.2f %-10d\n", current->name, current->id, current->price, current->quantity);
                        current = current->next;
                    }
                }
                break;
            }
            case 4: {
                printf("Exiting program...\n");
                Item *current = head;
                while (current != NULL) {
                    Item *temp = current;
                    current = current->next;
                    free(temp);
                }
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}