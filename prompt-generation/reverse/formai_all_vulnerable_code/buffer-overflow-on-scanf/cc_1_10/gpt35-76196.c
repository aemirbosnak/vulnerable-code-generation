//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 1000
#define MAX_STRING_SIZE 100

struct medicine {
    char name[MAX_STRING_SIZE];
    int quantity;
    float price;
};

struct medicine inventory[MAX_MEDICINES];
int inventory_size = 0;

void add_medicine() {
    printf("Enter medicine name: ");
    scanf("%s", inventory[inventory_size].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[inventory_size].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &inventory[inventory_size].price);
    inventory_size++;
    printf("Medicine added to inventory.\n");
}

void display_inventory() {
    if (inventory_size == 0) {
        printf("Inventory is empty.\n");
    } else {
        printf("Medicine\tQuantity\tPrice\n");
        for (int i = 0; i < inventory_size; i++) {
            printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
        }
    }
}

void search_medicine() {
    char name[MAX_STRING_SIZE];
    printf("Enter medicine name: ");
    scanf("%s", name);
    for (int i = 0; i < inventory_size; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine found: %s %d %.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("1. Add medicine to inventory\n");
        printf("2. Display inventory\n");
        printf("3. Search medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}