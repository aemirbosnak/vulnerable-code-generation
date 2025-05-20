//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure for medicine data
typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
} Medicine;

// function to print the menu options
void printMenu() {
    printf("1. Add medicine\n");
    printf("2. Sell medicine\n");
    printf("3. Check medicine stock\n");
    printf("4. Display all medicines\n");
    printf("5. Exit\n");
}

// function to add medicine to the store
void addMedicine(Medicine *medicines, int *numOfMedicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*numOfMedicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*numOfMedicines].quantity);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*numOfMedicines].price);
    (*numOfMedicines)++;
    printf("Medicine added to the store.\n");
}

// function to sell medicine from the store
void sellMedicine(Medicine *medicines, int numOfMedicines) {
    char medName[50];
    printf("Enter medicine name: ");
    scanf("%s", medName);
    int i;
    for (i = 0; i < numOfMedicines; i++) {
        if (strcmp(medicines[i].name, medName) == 0) {
            int quantity;
            printf("Enter medicine quantity: ");
            scanf("%d", &quantity);
            if (medicines[i].quantity < quantity) {
                printf("Sorry, stock not available.\n");
            } else {
                medicines[i].quantity -= quantity;
                printf("Medicine sold.\n");
            }
            return;
        }
    }
    printf("Medicine not found.\n");
}

// function to check medicine stock in the store
void checkStock(Medicine *medicines, int numOfMedicines) {
    char medName[50];
    printf("Enter medicine name: ");
    scanf("%s", medName);
    int i;
    for (i = 0; i < numOfMedicines; i++) {
        if (strcmp(medicines[i].name, medName) == 0) {
            printf("Available stock: %d\n", medicines[i].quantity);
            return;
        }
    }
    printf("Medicine not found.\n");
}

// function to display all the medicines in the store
void displayMedicines(Medicine *medicines, int numOfMedicines) {
    int i;
    printf("Medicine\tQuantity\tPrice\n");
    for (i = 0; i < numOfMedicines; i++) {
        printf("%s\t\t%d\t\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

int main() {
    Medicine medicines[100];    // maximum capacity of 100 medicines in the store
    int numOfMedicines = 0;
    int option;
    printf("Welcome to the Medical Store Management System.\n");
    do {
        printMenu();
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                addMedicine(medicines, &numOfMedicines);
                break;
            case 2:
                sellMedicine(medicines, numOfMedicines);
                break;
            case 3:
                checkStock(medicines, numOfMedicines);
                break;
            case 4:
                displayMedicines(medicines, numOfMedicines);
                break;
            case 5:
                printf("Thank you for using the system.\n");
                break;
            default:
                printf("Invalid option selected.\n");
        }
    } while (option != 5);
    return 0;
}