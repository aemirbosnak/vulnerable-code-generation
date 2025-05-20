//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *med, int *n) {
    printf("Enter the name of the medicine: ");
    scanf("%s", med[*n].name);
    printf("Enter the company of the medicine: ");
    scanf("%s", med[*n].company);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med[*n].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &med[*n].price);
    (*n)++;
}

void displayMedicine(medicine *med, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", med[i].name);
        printf("Company: %s\n", med[i].company);
        printf("Quantity: %d\n", med[i].quantity);
        printf("Price: %f\n\n", med[i].price);
    }
}

void searchMedicine(medicine *med, int n) {
    char name[50];
    printf("Enter the name of the medicine you want to search: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(name, med[i].name) == 0) {
            printf("Name: %s\n", med[i].name);
            printf("Company: %s\n", med[i].company);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %f\n\n", med[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void updateMedicine(medicine *med, int n) {
    char name[50];
    printf("Enter the name of the medicine you want to update: ");
    scanf("%s", name);
    for (int i = 0; i < n; i++) {
        if (strcmp(name, med[i].name) == 0) {
            printf("Enter the new name of the medicine: ");
            scanf("%s", med[i].name);
            printf("Enter the new company of the medicine: ");
            scanf("%s", med[i].company);
            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &med[i].quantity);
            printf("Enter the new price of the medicine: ");
            scanf("%f", &med[i].price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine(medicine *med, int *n) {
    char name[50];
    printf("Enter the name of the medicine you want to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *n; i++) {
        if (strcmp(name, med[i].name) == 0) {
            for (int j = i; j < *n - 1; j++) {
                med[j] = med[j + 1];
            }
            (*n)--;
            return;
        }
    }
    printf("Medicine not found!\n");
}

int main() {
    medicine med[100];
    int n = 0;
    int choice;
    do {
        printf("1. Add a medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search a medicine\n");
        printf("4. Update a medicine\n");
        printf("5. Delete a medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(med, &n);
                break;
            case 2:
                displayMedicine(med, n);
                break;
            case 3:
                searchMedicine(med, n);
                break;
            case 4:
                updateMedicine(med, n);
                break;
            case 5:
                deleteMedicine(med, &n);
                break;
            case 6:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}