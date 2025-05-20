//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure for medicines
struct medicine {
    char name[50];
    int quantity;
    float price;
};

//function to add a new medicine
void addMedicine(struct medicine *med, int *numMeds) {
    printf("Enter the name of the medicine: ");
    scanf("%s", med[*numMeds].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &med[*numMeds].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &med[*numMeds].price);
    (*numMeds)++;
    printf("Medicine successfully added!\n");
}

//function to display all medicines
void displayMedicines(struct medicine *med, int numMeds) {
    if (numMeds == 0) {
        printf("No medicines available.\n");
        return;
    }
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < numMeds; i++) {
        printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
    }
}

//function to search for a medicine
void searchMedicine(struct medicine *med, int numMeds) {
    char searchName[50];
    printf("Enter the name of the medicine to search for: ");
    scanf("%s", searchName);
    for (int i = 0; i < numMeds; i++) {
        if (strcmp(med[i].name, searchName) == 0) {
            printf("Name\tQuantity\tPrice\n");
            printf("%s\t%d\t%.2f\n", med[i].name, med[i].quantity, med[i].price);
            return;
        }
    }
    printf("Medicine not found.\n");
}

//function to update the quantity of a medicine
void updateMedicine(struct medicine *med, int numMeds) {
    char updateName[50];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", updateName);
    for (int i = 0; i < numMeds; i++) {
        if (strcmp(med[i].name, updateName) == 0) {
            printf("Enter the new quantity: ");
            scanf("%d", &med[i].quantity);
            printf("Quantity updated!\n");
            return;
        }
    }
    printf("Medicine not found.\n");
}

//main function
int main() {
    struct medicine meds[100];
    int numMeds = 0;
    int choice = 0;
    while (choice != 5) {
        printf("Medical Store Management System\n");
        printf("1. Add a new medicine\n");
        printf("2. Display all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Update the quantity of a medicine\n");
        printf("5. Quit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(meds, &numMeds);
                break;
            case 2:
                displayMedicines(meds, numMeds);
                break;
            case 3:
                searchMedicine(meds, numMeds);
                break;
            case 4:
                updateMedicine(meds, numMeds);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}