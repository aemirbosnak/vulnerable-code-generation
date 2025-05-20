//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int numMedicines = 0;

void addMedicine() {
    if(numMedicines >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }

    Medicine newMedicine;
    printf("Enter the name of the medicine: ");
    scanf("%s", newMedicine.name);

    printf("Enter the quantity: ");
    scanf("%d", &newMedicine.quantity);

    printf("Enter the price: ");
    scanf("%f", &newMedicine.price);

    medicines[numMedicines] = newMedicine;
    numMedicines++;

    printf("Medicine added successfully!\n");
}

void removeMedicine() {
    if(numMedicines == 0) {
        printf("No medicines to remove.\n");
        return;
    }

    char medicineName[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to remove: ");
    scanf("%s", medicineName);

    int medicineIndex = -1;
    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, medicineName) == 0) {
            medicineIndex = i;
            break;
        }
    }

    if(medicineIndex == -1) {
        printf("Medicine not found.\n");
        return;
    }

    medicines[medicineIndex] = medicines[numMedicines - 1];
    numMedicines--;

    printf("Medicine removed successfully!\n");
}

void displayMedicines() {
    if(numMedicines == 0) {
        printf("No medicines to display.\n");
        return;
    }

    printf("List of medicines:\n");
    for(int i = 0; i < numMedicines; i++) {
        printf("%-30s %5d %10.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void sellMedicine() {
    if(numMedicines == 0) {
        printf("No medicines to sell.\n");
        return;
    }

    char medicineName[MAX_NAME_LENGTH];
    printf("Enter the name of the medicine to sell: ");
    scanf("%s", medicineName);

    int medicineIndex = -1;
    for(int i = 0; i < numMedicines; i++) {
        if(strcmp(medicines[i].name, medicineName) == 0) {
            medicineIndex = i;
            break;
        }
    }

    if(medicineIndex == -1) {
        printf("Medicine not found.\n");
        return;
    }

    int quantity;
    printf("Enter the quantity to sell: ");
    scanf("%d", &quantity);

    if(quantity > medicines[medicineIndex].quantity) {
        printf("Not enough stock to sell. Available stock: %d\n", medicines[medicineIndex].quantity);
        return;
    }

    float totalAmount = medicines[medicineIndex].price * quantity;
    printf("Total amount to pay: %.2f\n", totalAmount);

    medicines[medicineIndex].quantity -= quantity;

    printf("Sold %d unit(s) of %s. Stock remaining: %d\n", quantity, medicineName, medicines[medicineIndex].quantity);
}

void mainMenu() {
    while(1) {
        printf("\n\nMedical Store Management System\n");
        printf("------------------------------------\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Display medicines\n");
        printf("4. Sell medicine\n");
        printf("5. Exit\n");

        int choice;
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                displayMedicines();
                break;
            case 4:
                sellMedicine();
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }
}

int main() {
    mainMenu();
    return 0;
}