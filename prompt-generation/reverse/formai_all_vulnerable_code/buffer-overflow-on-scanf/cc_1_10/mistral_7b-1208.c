//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct {
    Medicine medicines[100];
    int count;
} Store;

void print_menu() {
    printf("---------------------------------\n");
    printf("| Welcome to Ada's Apothecary! |\n");
    printf("---------------------------------\n");
    printf("| 1. Add Medicine               |\n");
    printf("| 2. Display Inventory          |\n");
    printf("| 3. Sell Medicine              |\n");
    printf("| 4. Quit                       |\n");
    printf("---------------------------------\n");
}

void add_medicine(Store* store) {
    if (store->count >= 100) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", store->medicines[store->count].name);

    printf("Enter stock level: ");
    scanf("%d", &store->medicines[store->count].stock);

    printf("Enter price per unit: ");
    scanf("%f", &store->medicines[store->count].price);

    store->count++;
}

void display_inventory(Store store) {
    printf("--------------------------------------------------------\n");
    printf("|             Ada's Apothecary Inventory Report          |\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < store.count; i++) {
        printf("| %-25s | %-5d | %-10.2f |\n", store.medicines[i].name, store.medicines[i].stock, store.medicines[i].price);
    }

    printf("--------------------------------------------------------\n");
}

void sell_medicine(Store* store, char name[50]) {
    for (int i = 0; i < store->count; i++) {
        if (strcmp(store->medicines[i].name, name) == 0) {
            if (store->medicines[i].stock > 0) {
                printf("Sold 1 unit of %s for %.2f.\n", name, store->medicines[i].price);
                store->medicines[i].stock--;
                return;
            } else {
                printf("Out of stock.\n");
                return;
            }
        }
    }

    printf("Medicine not found.\n");
}

int main() {
    Store store = { 0 };
    int choice;
    char medicine_name[50];

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine(&store);
                break;
            case 2:
                display_inventory(store);
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf("%s", medicine_name);
                sell_medicine(&store, medicine_name);
                break;
            case 4:
                printf("Thank you for shopping at Ada's Apothecary! See you soon!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}