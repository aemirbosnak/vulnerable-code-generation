//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    float price;
    int quantity;
};

void addMedicine(struct medicine* med, int* count) {
    printf("\nEnter medicine details: \n");
    printf("ID: ");
    scanf("%d", &med[*count].id);
    printf("Name: ");
    scanf("%s", med[*count].name);
    printf("Price: ");
    scanf("%f", &med[*count].price);
    printf("Quantity: ");
    scanf("%d", &med[*count].quantity);
    (*count)++;
}

void searchMedicine(struct medicine* med, int count) {
    int id, found = 0;
    printf("\nEnter medicine ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("\nMedicine details: \n");
            printf("ID: %d\n", med[i].id);
            printf("Name: %s\n", med[i].name);
            printf("Price: %.2f\n", med[i].price);
            printf("Quantity: %d\n", med[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

void updateMedicine(struct medicine* med, int count) {
    int id, found = 0;
    printf("\nEnter medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (med[i].id == id) {
            printf("\nEnter new details: \n");
            printf("ID: ");
            scanf("%d", &med[i].id);
            printf("Name: ");
            scanf("%s", med[i].name);
            printf("Price: ");
            scanf("%f", &med[i].price);
            printf("Quantity: ");
            scanf("%d", &med[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

void deleteMedicine(struct medicine* med, int* count) {
    int id, found = 0;
    printf("\nEnter medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (med[i].id == id) {
            (*count)--;
            for (int j = i; j < *count; j++) {
                med[j] = med[j+1];
            }
            found = 1;
            printf("\nMedicine deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("\nMedicine not found!\n");
    }
}

void displayMedicine(struct medicine* med, int count) {
    printf("\nMedicine details: \n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d\n", med[i].id);
        printf("Name: %s\n", med[i].name);
        printf("Price: %.2f\n", med[i].price);
        printf("Quantity: %d\n", med[i].quantity);
        printf("\n");
    }
}

int main() {
    struct medicine med[100];
    int choice, count = 0;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Display Medicines\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(med, &count);
                break;
            case 2:
                searchMedicine(med, count);
                break;
            case 3:
                updateMedicine(med, count);
                break;
            case 4:
                deleteMedicine(med, &count);
                break;
            case 5:
                displayMedicine(med, count);
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}