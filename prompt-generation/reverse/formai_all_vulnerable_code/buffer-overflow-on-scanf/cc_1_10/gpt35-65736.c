//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDS 100

struct Medicine {
    char name[100];
    int price;
    int quantity;
};

void addMedicine(struct Medicine meds[], int *size) {
    if (*size == MAX_MEDS) {
        printf("Cannot add more medicines.\n");
        return;
    }
    char name[100];
    int price;
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter medicine price: ");
    scanf("%d", &price);
    printf("Enter medicine quantity: ");
    scanf("%d", &quantity);
    strcpy(meds[*size].name, name);
    meds[*size].price = price;
    meds[*size].quantity = quantity;
    (*size)++;
    printf("Medicine added successfully!\n");
}

void printInventory(struct Medicine meds[], int size) {
    printf("Inventory:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s - %d - Rs.%d\n", i + 1, meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void sellMedicine(struct Medicine meds[], int *size) {
    char name[100];
    int quantity;
    printf("Enter medicine name: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    for (int i = 0; i < *size; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            if (meds[i].quantity >= quantity) {
                printf("Total amount to be paid: Rs. %d\n", meds[i].price * quantity);
                meds[i].quantity -= quantity;
            } else {
                printf("Cannot sell that much quantity of %s\n", name);
            }
            return;
        }
    }
    printf("Medicine not found in inventory.\n");
}

int main() {
    struct Medicine meds[MAX_MEDS];
    int size = 0;
    int choice;
    printf("Welcome to the Medical Store Management System!\n");
    do {
        printf("\n");
        printf("1. Add medicine\n");
        printf("2. Print inventory\n");
        printf("3. Sell medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(meds, &size);
                break;
            case 2:
                printInventory(meds, size);
                break;
            case 3:
                sellMedicine(meds, &size);
                break;
            case 4:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    } while (choice != 4);

    return 0;
}