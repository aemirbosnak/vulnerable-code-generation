//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

struct Medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
};

struct Medicine medicines[MAX_MEDICINES];

int numMedicines = 0;

void addMedicine() {
    printf("Enter name of medicine - ");
    scanf("%s", medicines[numMedicines].name);
    printf("Enter name of company - ");
    scanf("%s", medicines[numMedicines].company);
    printf("Enter price of medicine - ");
    scanf("%f", &medicines[numMedicines].price);
    printf("Enter quantity of medicine - ");
    scanf("%d", &medicines[numMedicines].quantity);

    numMedicines++;

    printf("Medicine added successfully!\n");
}

void displayMedicines() {
    printf("==== LIST OF MEDICINES ====\n");
    printf("Name\tCompany\tPrice\tQuantity\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%s\t%.2f\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter name of medicine to search - ");
    scanf("%s", name);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name\tCompany\tPrice\tQuantity\n");
            printf("%s\t%s\t%.2f\t%d\n", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void sellMedicine() {
    char name[50];
    int quantity;
    printf("Enter name of medicine to sell - ");
    scanf("%s", name);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("Current quantity - %d\n", medicines[i].quantity);
            printf("Enter quantity to sell - ");
            scanf("%d", &quantity);
            if (quantity > medicines[i].quantity) {
                printf("Quantity entered is more than the current stock!\n");
                return;
            }
            medicines[i].quantity -= quantity;
            printf("Total amount - %.2f\n", medicines[i].price * quantity);
            printf("%d units of %s sold successfully!\n", quantity, name);
            return;
        }
    }

    printf("Medicine not found!\n");
}

void menu() {
    printf("==== MEDICAL STORE MANAGEMENT SYSTEM ====\n");
    printf("1. Add Medicine\n2. Display Medicines\n3. Search Medicine\n4. Sell Medicine\n5. Exit\n");
    printf("Enter your choice - ");
}

int main() {
    int choice;

    do {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("Thank you for using our system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}