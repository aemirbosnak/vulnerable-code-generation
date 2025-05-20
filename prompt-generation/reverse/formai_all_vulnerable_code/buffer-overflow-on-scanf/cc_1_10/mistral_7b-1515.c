//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct {
    Medicine med[10];
    int count;
} Store;

void addMedicine(Store *store, const char *name, int quantity, float price) {
    if (store->count >= 10) {
        printf("Store is full.\n");
        return;
    }
    strcpy(store->med[store->count].name, name);
    store->med[store->count].stock = quantity;
    store->med[store->count].price = price;
    store->count++;
}

void displayStore(Store store) {
    printf("\n***** MEDICAL STORE INVENTORY *****\n");
    for (int i = 0; i < store.count; i++) {
        printf("\n%s\tStock: %d\tPrice: %.2f", store.med[i].name, store.med[i].stock, store.med[i].price);
    }
}

int main() {
    Store myStore;
    char inputName[50];
    int inputQuantity;
    float inputPrice;
    char choice;

    do {
        printf("\n1. Add Medicine\n2. Display Inventory\n3. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                printf("Enter Medicine Name: ");
                scanf("%s", inputName);
                printf("Enter Stock: ");
                scanf("%d", &inputQuantity);
                printf("Enter Price: ");
                scanf("%f", &inputPrice);
                addMedicine(&myStore, inputName, inputQuantity, inputPrice);
                break;
            case '2':
                displayStore(myStore);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice.\n");
        }
    } while (choice != '3');

    return 0;
}