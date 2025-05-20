//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 100 // maximum number of medicines in the store

// structure for each medicine
typedef struct Medicine {
    int id;
    char name[50];
    double price;
    int quantity;
} Medicine;

// function to display all medicines in the store
void displayMedicines(Medicine medicines[], int numMedicines) {
    printf("ID   Name                  Price   Quantity\n");
    printf("----------------------------------------------\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-3d  %-20s  %.2lf  %-8d\n", medicines[i].id, medicines[i].name, medicines[i].price, medicines[i].quantity);
    }
}

// function to add a new medicine to the store
void addMedicine(Medicine medicines[], int* numMedicines) {
    if (*numMedicines == MAX_MEDICINES) {
        printf("Error: store already has maximum number of medicines.\n");
        return;
    }

    Medicine newMedicine;
    newMedicine.id = *numMedicines + 1;

    // get user input for medicine name, price, and quantity
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine price: ");
    scanf("%lf", &newMedicine.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);

    // add the new medicine to the array of medicines
    medicines[*numMedicines] = newMedicine;
    (*numMedicines)++;

    printf("New medicine added successfully.\n");
}

// function to sell a medicine from the store
void sellMedicine(Medicine medicines[], int numMedicines) {
    int id, quantity;
    double totalPrice = 0;

    // get user input for medicine id and quantity
    printf("Enter medicine ID to sell: ");
    scanf("%d", &id);
    printf("Enter quantity to sell: ");
    scanf("%d", &quantity);

    // find the medicine with the given id
    Medicine* medicine = NULL;
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            medicine = &medicines[i];
            break;
        }
    }

    // check if the medicine exists and has enough quantity
    if (medicine == NULL) {
        printf("Error: medicine with ID %d not found.\n", id);
        return;
    } else if (medicine->quantity < quantity) {
        printf("Error: not enough quantity for medicine %s.\n", medicine->name);
        return;
    }

    // calculate total price and update quantity of medicine
    totalPrice = quantity * medicine->price;
    medicine->quantity -= quantity;

    printf("%d unit(s) of %s sold. Total price: %.2lf.\n", quantity, medicine->name, totalPrice);
}

// main function
int main() {
    Medicine medicines[MAX_MEDICINES];
    int numMedicines = 0;
    int option;

    do {
        printf("\nMedical Store Management System\n");
        printf("--------------------------------\n");
        printf("1. Display all medicines\n");
        printf("2. Add new medicine\n");
        printf("3. Sell medicine\n");
        printf("4. Exit\n");

        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displayMedicines(medicines, numMedicines);
                break;
            case 2:
                addMedicine(medicines, &numMedicines);
                break;
            case 3:
                sellMedicine(medicines, numMedicines);
                break;
            case 4:
                printf("Thank you for using the system.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break; 
        }

    } while (option != 4);
    
    return 0;
}