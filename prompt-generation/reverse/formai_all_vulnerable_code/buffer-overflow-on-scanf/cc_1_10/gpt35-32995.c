//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 50
#define MAX_MEDICINE_DETAILS 100
#define MAX_MEDICINE_LIST 50

typedef struct {
    char name[MAX_MEDICINE_NAME];
    char details[MAX_MEDICINE_DETAILS];
    int quantity;
    float price;
} Medicine;

Medicine medicineList[MAX_MEDICINE_LIST]; // store list of medicines
int numOfMedicines = 0; // keep track of number of medicines in the list

void addMedicine() {
    // read medicine details
    Medicine medicine;
    printf("Enter medicine name: ");
    fgets(medicine.name, MAX_MEDICINE_NAME, stdin);
    printf("Enter medicine details: ");
    fgets(medicine.details, MAX_MEDICINE_DETAILS, stdin);
    printf("Enter medicine price: ");
    scanf("%f", &medicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicine.quantity);
    getchar(); // consume the '\n' character from the input buffer

    // add medicine to the list
    if (numOfMedicines < MAX_MEDICINE_LIST) {
        medicineList[numOfMedicines++] = medicine;
        printf("Medicine added successfully!\n");
    } else {
        printf("Medicine list is full!\n");
    }
}

void searchMedicine() {
    char searchName[MAX_MEDICINE_NAME];
    printf("Enter medicine name to search: ");
    fgets(searchName, MAX_MEDICINE_NAME, stdin);

    // search for the medicine in the list
    int found = 0;
    for (int i = 0; i < numOfMedicines; i++) {
        if (strcmp(searchName, medicineList[i].name) == 0) {
            printf("Medicine details: %sPrice: INR %.2f, Available Quantity: %d\n", medicineList[i].details, medicineList[i].price, medicineList[i].quantity);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void sellMedicine() {
    char sellName[MAX_MEDICINE_NAME];
    printf("Enter the name of the medicine to be sold: ");
    fgets(sellName, MAX_MEDICINE_NAME, stdin);

    for (int i = 0; i < numOfMedicines; i++) {
        if (strcmp(sellName, medicineList[i].name) == 0) {
            int quantity;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity <= medicineList[i].quantity) {
                medicineList[i].quantity -= quantity;
                printf("%s sold successfully!\n", medicineList[i].name);
            } else {
                printf("Only %d %s available!\n", medicineList[i].quantity, medicineList[i].name);
            }
            return;
        }
    }

    printf("%s not found!\n", sellName);
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add new medicine\n");
        printf("2. Search for a medicine\n");
        printf("3. Sell a medicine\n");
        printf("4. Exit\n");

        int option;
        scanf("%d", &option);
        getchar(); // consume the '\n' character from the input buffer

        switch (option) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                sellMedicine();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }

    return 0;
}