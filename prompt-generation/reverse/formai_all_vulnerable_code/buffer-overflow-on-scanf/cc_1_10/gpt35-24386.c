//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[100];
    int quantity;
    float price;
};

void addMedicine(struct medicine meds[], int *numMeds) {
    char name[100];
    int quantity;
    float price;

    printf("Enter name of medicine: ");
    scanf("%s", name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    printf("Enter price: ");
    scanf("%f", &price);

    strcpy(meds[*numMeds].name, name);
    meds[*numMeds].quantity = quantity;
    meds[*numMeds].price = price;

    *numMeds += 1;

    printf("Medicine added!\n");
}

void displayMedicine(struct medicine meds[], int numMeds) {
    int i;

    if (numMeds == 0) {
        printf("No medicine to display.\n");
        return;
    }

    printf("%-20s%-15s%-10s\n", "Name", "Quantity", "Price");

    for (i = 0; i < numMeds; i++) {
        printf("%-20s%-15d%-10.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
    }
}

void searchMedicine(struct medicine meds[], int numMeds) {
    char name[100];
    int i, found = 0;

    printf("Enter name of the medicine to search for: ");
    scanf("%s", name);

    for (i = 0; i < numMeds; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("%-20s%-15s%-10s\n", "Name", "Quantity", "Price");
            printf("%-20s%-15d%-10.2f\n", meds[i].name, meds[i].quantity, meds[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine not found.\n");
    }
}

int main() {
    struct medicine meds[100];
    int numMeds = 0;

    int choice;

    printf("Welcome to Medical Store Management System!\n");

    while (1) {
        printf("\n1. Add Medicine\n2. Display Medicine\n3. Search Medicine\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(meds, &numMeds);
                break;
            case 2:
                displayMedicine(meds, numMeds);
                break;
            case 3:
                searchMedicine(meds, numMeds);
                break;
            case 4:
                printf("Thank you for using Medical Store Management System!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}