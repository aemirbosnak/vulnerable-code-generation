//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

typedef struct medicine Medicine;

void addMedicine(Medicine *medicines, int *numOfMedicines) {
    medicines[*numOfMedicines].id = *numOfMedicines + 1;
    printf("Enter the name of the medicine: ");
    scanf("%s", medicines[*numOfMedicines].name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicines[*numOfMedicines].quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicines[*numOfMedicines].price);
    *numOfMedicines += 1;
    printf("Medicine added successfully!\n");
}

void viewMedicines(Medicine *medicines, int numOfMedicines) {
    if (numOfMedicines <= 0) {
        printf("No medicines found!\n");
        return;
    }
    printf("ID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < numOfMedicines; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name,
            medicines[i].quantity, medicines[i].price);
    }
}

void deleteMedicine(Medicine *medicines, int *numOfMedicines) {
    int idToDelete;
    printf("Enter the ID of the medicine to delete: ");
    scanf("%d", &idToDelete);
    for (int i = 0; i < *numOfMedicines; i++) {
        if (medicines[i].id == idToDelete) {
            for (int j = i; j < *numOfMedicines - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            *numOfMedicines -= 1;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("No medicine found with the given ID!\n");
}

int main() {
    Medicine medicines[100];
    int numOfMedicines = 0;
    int choice;

    while (1) {
        printf("\n");
        printf("1. Add a new medicine\n");
        printf("2. View all medicines\n");
        printf("3. Delete a medicine\n");
        printf("4. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &numOfMedicines);
                break;
            case 2:
                viewMedicines(medicines, numOfMedicines);
                break;
            case 3:
                deleteMedicine(medicines, &numOfMedicines);
                break;
            case 4:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}