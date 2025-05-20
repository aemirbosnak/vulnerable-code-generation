//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int quantity;
} Item;

int main() {
    int choice, num_items = 0;
    char input[MAX_SIZE];
    Item items[MAX_SIZE];

    printf("Welcome to the Warehouse Management System!\n");
    printf("Please choose an option:\n");
    printf("1. Add item\n");
    printf("2. Remove item\n");
    printf("3. View inventory\n");
    printf("4. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the item: ");
                scanf("%s", input);

                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        printf("Item already exists!\n");
                        break;
                    }
                }

                if (num_items == MAX_SIZE) {
                    printf("Warehouse is full!\n");
                } else {
                    printf("Enter the quantity of the item: ");
                    scanf("%d", &items[num_items].quantity);
                    strcpy(items[num_items].name, input);
                    num_items++;
                }
                break;

            case 2:
                printf("Enter the name of the item to remove: ");
                scanf("%s", input);

                for (int i = 0; i < num_items; i++) {
                    if (strcmp(items[i].name, input) == 0) {
                        items[i] = items[--num_items];
                        break;
                    }
                }
                break;

            case 3:
                if (num_items == 0) {
                    printf("Warehouse is empty!\n");
                } else {
                    printf("Inventory:\n");
                    for (int i = 0; i < num_items; i++) {
                        printf("%s - %d\n", items[i].name, items[i].quantity);
                    }
                }
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}