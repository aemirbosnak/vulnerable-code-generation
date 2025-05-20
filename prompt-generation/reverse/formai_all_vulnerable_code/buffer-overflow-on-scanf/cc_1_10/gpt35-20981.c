//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Structure to hold medicine information
struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Function to add new medicine
void addMedicine(struct Medicine *medicines, int *numMedicines) {
    int id, quantity;
    float price;
    char name[50];

    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Quantity: ");
    scanf("%d", &quantity);
    printf("Enter Price: ");
    scanf("%f", &price);

    // Add medicine to array
    medicines[*numMedicines].id = id;
    strcpy(medicines[*numMedicines].name, name);
    medicines[*numMedicines].quantity = quantity;
    medicines[*numMedicines].price = price;

    (*numMedicines)++;
}

// Function to display all medicines
void displayMedicines(struct Medicine *medicines, int numMedicines) {
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numMedicines; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for medicine by name
void searchMedicine(struct Medicine *medicines, int numMedicines, char *name) {
    int found = 0;
    printf("ID\tName\tQuantity\tPrice\n");
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            found = 1;
            printf("%d\t%s\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
        }
    }
    if (!found) {
        printf("Medicine not found\n");
    }
}

// Function to update medicine quantity
void updateQuantity(struct Medicine *medicines, int numMedicines, int id, int quantity) {
    for (int i = 0; i < numMedicines; i++) {
        if (medicines[i].id == id) {
            medicines[i].quantity += quantity;
            return;
        }
    }
    printf("Medicine with ID %d not found\n", id);
}

// Function to delete medicine
void deleteMedicine(struct Medicine *medicines, int *numMedicines, int id) {
    int found = 0;
    for (int i = 0; i < *numMedicines; i++) {
        if (medicines[i].id == id) {
            found = 1;
            for (int j = i; j < *numMedicines - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            (*numMedicines)--;
        }
    }
    if (!found) {
        printf("Medicine with ID %d not found\n", id);
    }
}

int main() {
    struct Medicine medicines[100];
    int numMedicines = 0;
    int choice;
    char name[50];
    int id, quantity;

    printf("Welcome to the Medical Store Management System\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add New Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Search for Medicine\n");
        printf("4. Update Medicine Quantity\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &numMedicines);
                break;
            case 2:
                displayMedicines(medicines, numMedicines);
                break;
            case 3:
                printf("Enter Medicine Name: ");
                scanf("%s", name);
                searchMedicine(medicines, numMedicines, name);
                break;
            case 4:
                printf("Enter Medicine ID: ");
                scanf("%d", &id);
                printf("Enter Quantity to Add/Subtract: ");
                scanf("%d", &quantity);
                updateQuantity(medicines, numMedicines, id, quantity);
                break;
            case 5:
                printf("Enter Medicine ID: ");
                scanf("%d", &id);
                deleteMedicine(medicines, &numMedicines, id);
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}