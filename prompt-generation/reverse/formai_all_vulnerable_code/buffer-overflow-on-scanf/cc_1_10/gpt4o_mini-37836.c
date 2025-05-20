//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MX 100

typedef struct {
    char name[50];
    int id;
    int qty;
    float price;
} MedItem;

MedItem store[MX];
int current_count = 0;

void add_item() {
    if (current_count < MX) {
        MedItem item;
        printf("Enter Name: ");
        scanf("%s", item.name);
        printf("Enter ID: ");
        scanf("%d", &item.id);
        printf("Enter Quantity: ");
        scanf("%d", &item.qty);
        printf("Enter Price: ");
        scanf("%f", &item.price);
        store[current_count++] = item;
        printf("Item Added!\n");
    } else {
        printf("Store is Full!\n");
    }
}

void view_items() {
    if (current_count == 0) {
        printf("No Items in Store!\n");
        return;
    }
    printf("\n--- Medicine Inventory ---\n");
    printf("%-20s %-10s %-10s %-10s\n", "Name", "ID", "Qty", "Price");
    for (int i = 0; i < current_count; i++) {
        printf("%-20s %-10d %-10d $%-9.2f\n", store[i].name, store[i].id, store[i].qty, store[i].price);
    }
    printf("--------------------------\n");
}

void delete_item() {
    int id;
    printf("Enter ID of Item to Remove: ");
    scanf("%d", &id);
    for (int i = 0; i < current_count; i++) {
        if (store[i].id == id) {
            for (int j = i; j < current_count - 1; j++) {
                store[j] = store[j + 1];
            }
            current_count--;
            printf("Item Removed!\n");
            return;
        }
    }
    printf("Item Not Found!\n");
}

void menu() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Delete Item\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: add_item(); break;
            case 2: view_items(); break;
            case 3: delete_item(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid Option! Try Again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}