//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} medicine;

void addMedicine(medicine *med, int *count) {
    printf("Enter medicine ID: ");
    scanf("%d", &med[*count].id);
    printf("Enter medicine name: ");
    scanf(" %[^\n]%*c", med[*count].name);
    printf("Enter medicine price: ");
    scanf("%f", &med[*count].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &med[*count].quantity);
    (*count)++;
}

void displayMedicine(medicine *med, int count) {
    printf("\nMedicine List:\n");
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%-20s\t%.2f\t%d\n", med[i].id, med[i].name, med[i].price, med[i].quantity);
    }
}

void searchMedicine(medicine *med, int count) {
    int id;
    printf("\nEnter medicine ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("\nMedicine found:\n");
            printf("ID:\t%d\n", med[i].id);
            printf("Name:\t%s\n", med[i].name);
            printf("Price:\t%.2f\n", med[i].price);
            printf("Quantity:\t%d\n", med[i].quantity);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void updateMedicine(medicine *med, int count) {
    int id;
    printf("\nEnter medicine ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("\nEnter new medicine name: ");
            scanf(" %[^\n]%*c", med[i].name);
            printf("Enter new medicine price: ");
            scanf("%f", &med[i].price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &med[i].quantity);
            printf("\nMedicine updated!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

void deleteMedicine(medicine *med, int *count) {
    int id;
    printf("\nEnter medicine ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *count; i++) {
        if (med[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                med[j] = med[j + 1];
            }
            (*count)--;
            printf("\nMedicine deleted!\n");
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

int main() {
    int choice, count = 0;
    medicine med[100];

    while (1) {
        printf("\n1. Add Medicine\n");
        printf("2. Display Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(med, &count);
                break;
            case 2:
                displayMedicine(med, count);
                break;
            case 3:
                searchMedicine(med, count);
                break;
            case 4:
                updateMedicine(med, count);
                break;
            case 5:
                deleteMedicine(med, &count);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}