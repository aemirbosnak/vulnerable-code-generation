//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 50

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

void displayMenu();
Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

void addMedicine() {
    if (numMedicines == MAX_MEDICINES) {
        printf("Maximum capacity reached.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", medicines[numMedicines].name);
    printf("Enter stock: ");
    scanf("%d", &medicines[numMedicines].stock);
    printf("Enter price: ");
    scanf("%f", &medicines[numMedicines].price);

    numMedicines++;
}

void deleteMedicine() {
    char name[50];
    int index = -1;

    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    for (int i = index; i < numMedicines - 1; i++) {
        medicines[i] = medicines[i + 1];
    }

    numMedicines--;
}

void displayMedicines() {
    printf("\nCurrent inventory:\n");

    for (int i = 0; i < numMedicines; i++) {
        printf("%d. %s - Stock: %d, Price: %.2f\n", i + 1, medicines[i].name, medicines[i].stock, medicines[i].price);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                displayMedicines();
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n1. Add Medicine\n");
    printf("2. Delete Medicine\n");
    printf("3. Display Inventory\n");
    printf("0. Exit\n");
}