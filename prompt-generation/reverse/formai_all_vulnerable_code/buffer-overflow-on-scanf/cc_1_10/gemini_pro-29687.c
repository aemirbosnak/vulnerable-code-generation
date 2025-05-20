//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine;

void addMedicine(medicine *med, int *size) {
    printf("Enter Medicine Name: ");
    scanf("%s", med[*size].name);
    printf("Enter Quantity: ");
    scanf("%d", &med[*size].quantity);
    printf("Enter Price: ");
    scanf("%f", &med[*size].price);
    (*size)++;
}

void displayMedicine(medicine *med, int size) {
    printf("\n\nMedicine List:\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

void searchMedicine(medicine *med, int size) {
    char name[50];
    printf("Enter Medicine Name to Search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("\nMedicine Found:\n");
            printf("Name: %s\n", med[i].name);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %.2f\n", med[i].price);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Medicine Not Found.\n");
    }
}

void updateMedicine(medicine *med, int size) {
    char name[50];
    printf("Enter Medicine Name to Update: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            printf("\nEnter New Quantity: ");
            scanf("%d", &med[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &med[i].price);
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Medicine Not Found.\n");
    }
}

void deleteMedicine(medicine *med, int *size) {
    char name[50];
    printf("Enter Medicine Name to Delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(med[i].name, name) == 0) {
            for (int j = i; j < *size - 1; j++) {
                med[j] = med[j + 1];
            }
            (*size)--;
            found = 1;
            break;
        }
    }
    if (found == 0) {
        printf("Medicine Not Found.\n");
    }
}

int main() {
    medicine med[100];
    int size = 0;
    int choice;
    do {
        printf("\n\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicine List\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(med, &size);
                break;
            case 2:
                displayMedicine(med, size);
                break;
            case 3:
                searchMedicine(med, size);
                break;
            case 4:
                updateMedicine(med, size);
                break;
            case 5:
                deleteMedicine(med, &size);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice. Please Enter a Valid Number.\n");
        }
    } while (choice != 6);
    return 0;
}