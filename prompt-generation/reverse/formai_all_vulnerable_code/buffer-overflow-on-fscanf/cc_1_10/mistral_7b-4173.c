//MISTRAL-7B DATASET v1.0 Category: Product Inventory System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_ITEMS 100
#define ITEM_NAME_SIZE 50
#define ITEM_QUANTITY_SIZE 10
#define FILE_NAME "product.txt"

typedef struct {
    char name[ITEM_NAME_SIZE];
    int quantity;
} Item;

void load_items(Item items[]) {
    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", FILE_NAME);
        exit(1);
    }

    for (int i = 0; i < MAX_ITEMS && fscanf(file, "%s %d", items[i].name, &items[i].quantity) == 2; i++);

    fclose(file);
}

void save_items(Item items[]) {
    FILE *file = fopen(FILE_NAME, "w");
    if (file == NULL) {
        printf("Unable to open file: %s\n", FILE_NAME);
        exit(1);
    }

    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            fprintf(file, "%s %d\n", items[i].name, items[i].quantity);
        }
    }

    fclose(file);
}

void print_items(Item items[]) {
    printf("\nCURRENT INVENTORY\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        if (items[i].quantity > 0) {
            printf("%s: %d\n", items[i].name, items[i].quantity);
        }
    }
}

int main() {
    srand(time(NULL));
    Item inventory[MAX_ITEMS];

    load_items(inventory);

    int choice, index;
    char name[ITEM_NAME_SIZE];
    int quantity;

    while (1) {
        printf("\n1. Add item\n2. Remove item\n3. Print inventory\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter item quantity: ");
                scanf("%d", &quantity);

                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (strcmp(name, inventory[i].name) == 0) {
                        inventory[i].quantity += quantity;
                        save_items(inventory);
                        printf("Item added successfully!\n");
                        break;
                    }

                    if (i == MAX_ITEMS - 1) {
                        if (quantity > 0) {
                            strcpy(inventory[i].name, name);
                            inventory[i].quantity = quantity;
                            save_items(inventory);
                            printf("Item added successfully at position %d!\n", i + 1);
                        } else {
                            printf("Invalid quantity. Item not added.\n");
                        }
                        break;
                    }
                }
                break;

            case 2:
                printf("Enter item name to remove: ");
                scanf("%s", name);

                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (strcmp(name, inventory[i].name) == 0) {
                        if (inventory[i].quantity > 0) {
                            inventory[i].quantity = 0;
                            save_items(inventory);
                            printf("Item removed successfully!\n");
                        } else {
                            printf("Item not found in inventory.\n");
                        }
                        break;
                    }
                }
                break;

            case 3:
                print_items(inventory);
                break;

            case 4:
                save_items(inventory);
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        system("clear"); // For Linux/macOS
        // system("cls"); // For Windows
    }

    return 0;
}