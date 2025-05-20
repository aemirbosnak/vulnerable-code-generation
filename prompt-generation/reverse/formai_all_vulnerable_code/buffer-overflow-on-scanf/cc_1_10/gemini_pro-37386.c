//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} Medicine;

void addMedicine(Medicine *medicines, int *numMedicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter quantity: ");
    scanf("%d", &medicines[*numMedicines].quantity);
    printf("Enter price: ");
    scanf("%f", &medicines[*numMedicines].price);
    (*numMedicines)++;
}

void displayMedicines(Medicine *medicines, int numMedicines) {
    printf("Here's a list of our medicines:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(Medicine *medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine(Medicine *medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            found = 1;
            printf("Medicine updated!\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void deleteMedicine(Medicine *medicines, int *numMedicines) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*numMedicines)--;
            found = 1;
            printf("Medicine deleted!\n");
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void generateBill(Medicine *medicines, int numMedicines) {
    char customerName[50];
    printf("Enter customer name: ");
    scanf("%s", customerName);
    float total = 0;
    printf("Here's your bill, %s:\n", customerName);
    for (int i = 0; i < numMedicines; i++) {
        printf("%s\t%d\t%.2f\n", medicines[i].name, medicines[i].quantity, medicines[i].price);
        total += medicines[i].quantity * medicines[i].price;
    }
    printf("Total: %.2f\n", total);
}

int main() {
    Medicine medicines[100];
    int numMedicines = 0;
    int choice;
    do {
        printf("\n1. Add medicine\n2. Display medicines\n3. Search medicine\n4. Update medicine\n5. Delete medicine\n6. Generate bill\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                displayMedicines(medicines, numMedicines);
                break;
            case 3:
                searchMedicine(medicines, numMedicines);
                break;
            case 4:
                updateMedicine(medicines, numMedicines);
                break;
            case 5:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 6:
                generateBill(medicines, numMedicines);
                break;
            case 7:
                printf("Thank you for using our medical store management system!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);
    return 0;
}