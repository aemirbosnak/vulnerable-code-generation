//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50
#define MAX_NAME_LEN 50
#define MAX_QUANTITY 100

struct Medicine {
    char name[MAX_NAME_LEN];
    int stock;
};

void addMedicine(struct Medicine medicines[], char name[], int quantity) {
    int i;
    for (i = 0; i < MAX_MEDICINES; i++) {
        if (medicines[i].stock == 0) {
            strcpy(medicines[i].name, name);
            medicines[i].stock = quantity;
            break;
        }
    }
}

void displayInventory(struct Medicine medicines[]) {
    int i;
    printf("CURRENT INVENTORY:\n");
    for (i = 0; i < MAX_MEDICINES; i++) {
        if (medicines[i].stock > 0) {
            printf("%s: %d\n", medicines[i].name, medicines[i].stock);
        }
    }
}

int main() {
    struct Medicine store[MAX_MEDICINES];
    int choice, quantity;
    char name[MAX_NAME_LEN];

    while (1) {
        printf("\n\n----- MEDICAL STORE MANAGEMENT SYSTEM -----");
        printf("\n1. Add Medicine");
        printf("\n2. Display Inventory");
        printf("\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                addMedicine(store, name, quantity);
                break;
            case 2:
                displayInventory(store);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid Option!\n");
        }
    }

    return 0;
}