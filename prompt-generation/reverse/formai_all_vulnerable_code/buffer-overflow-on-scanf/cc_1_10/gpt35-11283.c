//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct medicine {
    char name[50];
    float price;
    int quantity;
};

struct medicine inventory[MAX_ITEMS];
int num_items = 0;

void add_item() {
    struct medicine med;
    printf("Enter medicine name: ");
    scanf("%s", med.name);
    printf("Enter medicine price: ");
    scanf("%f", &med.price);
    printf("Enter quantity: ");
    scanf("%d", &med.quantity);
    inventory[num_items++] = med;
    printf("Item added successfully!\n");
}

void display_items() {
    printf("Name\t\tPrice\tQuantity\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s\t\t%f\t%d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
}

void search_item() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    int index = -1;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Item not found!\n");
    } else {
        printf("Name\t\tPrice\tQuantity\n");
        printf("%s\t\t%f\t%d\n", inventory[index].name, inventory[index].price, inventory[index].quantity);
    }
}

int main() {
    int choice;
    do {
        printf("Medical Store Management System\n");
        printf("1. Add item\n");
        printf("2. Display items\n");
        printf("3. Search item\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_item();
                break;
            case 2:
                display_items();
                break;
            case 3:
                search_item();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}