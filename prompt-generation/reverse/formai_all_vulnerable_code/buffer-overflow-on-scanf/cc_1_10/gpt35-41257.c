//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

void addMedicine(struct medicine *med, int *count) {
    printf("\nEnter medicine name: ");
    scanf("%s", med[*count].name);
    printf("Enter quantity: ");
    scanf("%d", &med[*count].quantity);
    printf("Enter price: ");
    scanf("%f", &med[*count].price);
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(struct medicine *med, int count) {
    printf("\nMedicine List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", med[i].name);
        printf("Quantity: %d\n", med[i].quantity);
        printf("Price: %.2f\n\n", med[i].price);
    }
}

void searchMedicine(struct medicine *med, int count, char *searchTerm) {
    for (int i = 0; i < count; i++) {
        if (strcmp(med[i].name, searchTerm) == 0) {
            printf("\nMedicine Found!\n");
            printf("Name: %s\n", med[i].name);
            printf("Quantity: %d\n", med[i].quantity);
            printf("Price: %.2f\n\n", med[i].price);
            return;
        }
    }
    printf("\nMedicine not found!\n");
}

int main() {
    struct medicine meds[100];
    int count = 0, choice;
    char searchTerm[50];

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(&meds, &count);
                break;
            case 2:
                displayMedicines(&meds, count);
                break;
            case 3:
                printf("\nEnter medicine name to search: ");
                scanf("%s", searchTerm);
                searchMedicine(&meds, count, searchTerm);
                break;
            case 4:
                printf("\nThank you for using Medical Store Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}