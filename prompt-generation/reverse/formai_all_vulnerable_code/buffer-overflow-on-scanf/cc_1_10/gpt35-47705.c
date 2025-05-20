//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    int qty;
    float price;
};

void addMedicine(struct Medicine *medicines, int *numMedicines) {
    char newName[50];
    int newQty;
    float newPrice;

    printf("Enter name of the medicine: ");
    scanf("%s", newName);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &newQty);
    printf("Enter price of the medicine: ");
    scanf("%f", &newPrice);

    struct Medicine newMedicine = {newName, newQty, newPrice};
    medicines[*numMedicines] = newMedicine;
    (*numMedicines)++;
}

void findMedicine(struct Medicine *medicines, int numMedicines) {
    char searchName[50];
    printf("Enter name of the medicine to search for: ");
    scanf("%s", searchName);

    int i, found = 0;
    for (i=0; i<numMedicines; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Found medicine with name %s, quantity %d, and price %f.\n", 
                   medicines[i].name, medicines[i].qty, medicines[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("Medicine with name %s not found.\n", searchName);
    }
}

void sellMedicine(struct Medicine *medicines, int numMedicines) {
    char sellName[50];
    int sellQty;
    printf("Enter name of the medicine to sell: ");
    scanf("%s", sellName);
    printf("Enter quantity of the medicine to sell: ");
    scanf("%d", &sellQty);

    int i, found = 0;
    for (i=0; i<numMedicines; i++) {
        if (strcmp(medicines[i].name, sellName) == 0) {
            if (medicines[i].qty >= sellQty) {
                medicines[i].qty -= sellQty;
                printf("Sold %d %s(s) for total price %f.\n", sellQty, medicines[i].name, 
                       medicines[i].price * sellQty);
            } else {
                printf("Insufficient quantity %d for medicine %s.\n", medicines[i].qty, sellName);
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medicine with name %s not found.\n", sellName);
    }
}

void printInventory(struct Medicine *medicines, int numMedicines) {
    int i;
    printf("Inventory:\n");
    for (i=0; i<numMedicines; i++) {
        printf("%d. Name: %s, Quantity: %d, Price: %f\n", i+1, 
               medicines[i].name, medicines[i].qty, medicines[i].price);
    }
}

int main() {
    int choice;
    struct Medicine *medicines;
    int numMedicines = 0, maxMedicines = 10;
    medicines = malloc(maxMedicines * sizeof(struct Medicine));

    while (1) {
        printf("\n1. Add medicine\n");
        printf("2. Find medicine\n");
        printf("3. Sell medicine\n");
        printf("4. Print inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (numMedicines >= maxMedicines) {
                    maxMedicines *= 2;
                    medicines = realloc(medicines, maxMedicines * sizeof(struct Medicine));
                }
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                findMedicine(medicines, numMedicines);
                break;
            case 3:
                sellMedicine(medicines, numMedicines);
                break;
            case 4:
                printInventory(medicines, numMedicines);
                break;
            case 5:
                free(medicines);
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}