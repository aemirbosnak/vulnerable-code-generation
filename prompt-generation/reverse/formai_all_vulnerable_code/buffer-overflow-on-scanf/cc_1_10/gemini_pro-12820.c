//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store medicine details
typedef struct medicine {
    char name[50];
    char company[50];
    float price;
    int quantity;
} medicine;

// Function to add a new medicine
void addMedicine(medicine *medicines, int *numMedicines) {
    printf("Enter medicine name: ");
    scanf("%s", medicines[*numMedicines].name);
    printf("Enter medicine company: ");
    scanf("%s", medicines[*numMedicines].company);
    printf("Enter medicine price: ");
    scanf("%f", &medicines[*numMedicines].price);
    printf("Enter medicine quantity: ");
    scanf("%d", &medicines[*numMedicines].quantity);
    (*numMedicines)++;
}

// Function to delete a medicine
void deleteMedicine(medicine *medicines, int *numMedicines) {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    for (int i = 0; i < *numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*numMedicines)--;
            break;
        }
    }
}

// Function to search for a medicine
void searchMedicine(medicine *medicines, int numMedicines) {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Company: %s\n", medicines[i].company);
            printf("Price: %.2f\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            break;
        }
    }
}

// Function to display all medicines
void displayMedicines(medicine *medicines, int numMedicines) {
    printf("All medicines:\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("Name: %s\n", medicines[i].name);
        printf("Company: %s\n", medicines[i].company);
        printf("Price: %.2f\n", medicines[i].price);
        printf("Quantity: %d\n\n", medicines[i].quantity);
    }
}

// Main function
int main() {
    medicine medicines[100];
    int numMedicines = 0;
    int choice;

    while (1) {
        printf("1. Add medicine\n");
        printf("2. Delete medicine\n");
        printf("3. Search for medicine\n");
        printf("4. Display all medicines\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                deleteMedicine(medicines, &numMedicines);
                break;
            case 3:
                searchMedicine(medicines, numMedicines);
                break;
            case 4:
                displayMedicines(medicines, numMedicines);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}