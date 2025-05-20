//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *med, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the name of the medicine: ");
        scanf("%s", med[i].name);
        printf("Enter the quantity of the medicine: ");
        scanf("%d", &med[i].quantity);
        printf("Enter the price of the medicine: ");
        scanf("%f", &med[i].price);
    }
}

void displayMedicine(medicine *med, int n) {
    printf("Medicine Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", med[i].name);
        printf("Quantity: %d\n", med[i].quantity);
        printf("Price: %f\n", med[i].price);
    }
}

void searchMedicine(medicine *med, int n) {
    char search[50];
    printf("Enter the name of the medicine you want to search for: ");
    scanf("%s", search);
    for (int i = 0; i < n; i++) {
        if (strcmp(med[i].name, search) == 0) {
            printf("Medicine Found:\n");
            printf("Name: %s\n", med[i].name);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %f\n", med[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

void updateMedicine(medicine *med, int n) {
    char search[50];
    printf("Enter the name of the medicine you want to update: ");
    scanf("%s", search);
    for (int i = 0; i < n; i++) {
        if (strcmp(med[i].name, search) == 0) {
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &med[i].quantity);
            printf("Enter the new price of the medicine: ");
            scanf("%f", &med[i].price);
            printf("Medicine updated.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

void deleteMedicine(medicine *med, int n) {
    char search[50];
    printf("Enter the name of the medicine you want to delete: ");
    scanf("%s", search);
    for (int i = 0; i < n; i++) {
        if (strcmp(med[i].name, search) == 0) {
            for (int j = i; j < n-1; j++) {
                med[j] = med[j+1];
            }
            printf("Medicine deleted.\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

int main() {
    int choice, n;
    printf("Enter the number of medicines: ");
    scanf("%d", &n);
    medicine *med = malloc(n * sizeof(medicine));
    addMedicine(med, n);
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Display Medicines\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayMedicine(med, n);
                break;
            case 2:
                searchMedicine(med, n);
                break;
            case 3:
                updateMedicine(med, n);
                break;
            case 4:
                deleteMedicine(med, n);
                break;
            case 5:
                free(med);
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}