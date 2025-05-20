//Falcon2-11B DATASET v1.0 Category: Warehouse Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char* name;
    int quantity;
};

int main() {
    struct Item items[] = {
        {"Item 1", 10},
        {"Item 2", 5},
        {"Item 3", 20},
        {"Item 4", 15},
        {"Item 5", 30},
        {"Item 6", 25},
        {"Item 7", 18},
        {"Item 8", 12},
    };

    int nItems = sizeof(items) / sizeof(items[0]);

    printf("Warehouse Management System\n\n");
    printf("Available Items:\n");
    for (int i = 0; i < nItems; i++) {
        printf("%d) %s (%d)\n", i + 1, items[i].name, items[i].quantity);
    }

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= nItems) {
        printf("You have selected item %d - %s (%d)\n", choice - 1, items[choice - 1].name, items[choice - 1].quantity);
        items[choice - 1].quantity -= 1;
        if (items[choice - 1].quantity == 0) {
            printf("Item %d has been sold out.\n", choice - 1);
            for (int i = choice - 1; i < nItems - 1; i++) {
                items[i].quantity += 1;
            }
            nItems--;
        }
    } else {
        printf("Invalid choice!\n");
    }

    printf("Items available:\n");
    for (int i = 0; i < nItems; i++) {
        printf("%d) %s (%d)\n", i + 1, items[i].name, items[i].quantity);
    }

    return 0;
}