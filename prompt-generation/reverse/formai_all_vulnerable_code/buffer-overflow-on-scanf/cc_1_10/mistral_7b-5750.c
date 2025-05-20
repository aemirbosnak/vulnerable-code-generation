//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_QUANTITY 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Medicine;

typedef struct {
    Medicine medicines[MAX_MEDICINES];
    int count;
} Store;

void addMedicine(Store *store, const char *name, int quantity) {
    if (store->count == MAX_MEDICINES) {
        printf("Store is full!\n");
        return;
    }

    strcpy(store->medicines[store->count].name, name);
    store->medicines[store->count].quantity = quantity;
    store->count++;
}

void displayStore(const Store *store) {
    printf("----STORE INVENTORY----\n");
    for (int i = 0; i < store->count; i++) {
        printf("%d. %s - %d\n", i + 1, store->medicines[i].name, store->medicines[i].quantity);
    }
}

int main() {
    Store store = {0};

    printf("Welcome to C Medical Store Management System!\n");

    while (true) {
        printf("\n1. Add Medicine\n2. Display Inventory\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char name[MAX_NAME_LENGTH];
                int quantity;

                printf("Enter Medicine Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);

                addMedicine(&store, name, quantity);
                break;
            }

            case 2: {
                displayStore(&store);
                break;
            }

            case 3: {
                printf("Exiting...\n");
                exit(0);
            }

            default: {
                printf("Invalid Choice!\n");
                break;
            }
        }
    }

    return 0;
}