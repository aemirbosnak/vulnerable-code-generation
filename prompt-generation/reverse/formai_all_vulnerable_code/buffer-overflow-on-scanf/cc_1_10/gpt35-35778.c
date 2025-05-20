//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[100];
    float price;
    int quantity;
};

void add_medicine(struct medicine store[], int *n) {
    printf("\nEnter the medicine name: ");
    scanf("%s", store[*n].name);
    printf("\nEnter the medicine price: ");
    scanf("%f", &store[*n].price);
    printf("\nEnter the quantity: ");
    scanf("%d", &store[*n].quantity);
    (*n)++;
}

void display(struct medicine store[], int n) {
    int i;
    printf("\n%-20s%-10s%-10s\n", "MEDICINE NAME", "PRICE", "QUANTITY");
    for (i = 0; i < n; i++) {
        printf("%-20s%-10.2f%-10d\n", store[i].name, store[i].price, store[i].quantity);
    }
}

int search(struct medicine store[], int n, char name[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(store[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void sell_medicine(struct medicine store[], int *n) {
    char name[100];
    int index, quantity;
    printf("\nEnter the name of medicine: ");
    scanf("%s", name);
    index = search(store, *n, name);
    if (index == -1) {
        printf("\nMedicine not found!\n");
    } else {
        printf("\nEnter the quantity to sell: ");
        scanf("%d", &quantity);
        if (store[index].quantity < quantity) {
            printf("\nInsufficient quantity!\n");
        } else {
            printf("\nTotal bill amount: %0.2f\n", store[index].price * quantity);
            store[index].quantity -= quantity;
        }
    }
}

int main() {
    struct medicine store[100];
    int choice, n = 0;
    do {
        printf("\nMEDICAL STORE MANAGEMENT SYSTEM\n");
        printf("\n1. Add medicine\n2. Sell medicine\n3. Display inventory\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine(store, &n);
                break;
            case 2:
                sell_medicine(store, &n);
                break;
            case 3:
                display(store, n);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}