//Falcon-180B DATASET v1.0 Category: Memory management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

int main() {
    Item *items = NULL;
    int num_items = 0;
    char choice;
    bool quit = false;

    while (!quit) {
        printf("Menu:\n");
        printf("A - Add item\n");
        printf("D - Delete item\n");
        printf("L - List items\n");
        printf("Q - Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                if (num_items == MAX_ITEMS) {
                    printf("Maximum number of items reached.\n");
                } else {
                    items = (Item*) realloc(items, (num_items + 1) * sizeof(Item));
                    printf("Enter item ID: ");
                    scanf("%d", &items[num_items].id);
                    printf("Enter item name: ");
                    scanf("%s", items[num_items].name);
                    printf("Enter item price: ");
                    scanf("%f", &items[num_items].price);
                    num_items++;
                }
                break;
            case 'D':
                if (num_items == 0) {
                    printf("No items to delete.\n");
                } else {
                    printf("Enter item ID to delete: ");
                    int id;
                    scanf("%d", &id);
                    for (int i = 0; i < num_items; i++) {
                        if (items[i].id == id) {
                            for (int j = i; j < num_items - 1; j++) {
                                items[j] = items[j + 1];
                            }
                            num_items--;
                            items = (Item*) realloc(items, num_items * sizeof(Item));
                            break;
                        }
                    }
                }
                break;
            case 'L':
                printf("List of items:\n");
                for (int i = 0; i < num_items; i++) {
                    printf("ID: %d, Name: %s, Price: %.2f\n", items[i].id, items[i].name, items[i].price);
                }
                break;
            case 'Q':
                quit = true;
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    free(items);
    return 0;
}