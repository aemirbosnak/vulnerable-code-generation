//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void addMedicine();
void editMedicine();
void deleteMedicine();
void displayMenu();
void viewAllMedicines();
void searchMedicine();

// Structure to hold medicine information
typedef struct medicine {
    int id;
    char name[50];
    char manufacturer[50];
    char expiryDate[20];
    int quantity;
    float price;
} Medicine;

int main() {
    int choice;
    do {
        // Display menu
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                editMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                viewAllMedicines();
                break;
            case 5:
                searchMedicine();
                break;
            case 6:
                printf("\nThank you for using our system!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// Function to add new medicine
void addMedicine() {
    Medicine med;
    FILE *file = fopen("medicine.txt", "a");

    if (file == NULL) {
        printf("\nUnable to open file.\n");
        return;
    }

    printf("\nEnter Medicine ID: ");
    scanf("%d", &med.id);

    printf("Enter Medicine Name: ");
    scanf("%s", med.name);

    printf("Enter Medicine Manufacturer: ");
    scanf("%s", med.manufacturer);

    printf("Enter Medicine Expiry Date (dd/mm/yyyy): ");
    scanf("%s", med.expiryDate);

    printf("Enter Medicine Quantity: ");
    scanf("%d", &med.quantity);

    printf("Enter Medicine Price: ");
    scanf("%f", &med.price);

    fwrite(&med, sizeof(Medicine), 1, file);

    fclose(file);

    printf("\nMedicine added successfully.\n");
}

// Function to edit medicine information
void editMedicine() {
    int id;
    Medicine med;
    FILE *file = fopen("medicine.txt", "r+");

    if (file == NULL) {
        printf("\nUnable to open file.\n");
        return;
    }

     printf("\nEnter Medicine ID to edit: ");
     scanf("%d", &id);

    while (fread(&med, sizeof(Medicine), 1, file)) {
        if (med.id == id) {
            printf("Enter Medicine Name: ");
            scanf("%s", med.name);

            printf("Enter Medicine Manufacturer: ");
            scanf("%s", med.manufacturer);

            printf("Enter Medicine Expiry Date (dd/mm/yyyy): ");
            scanf("%s", med.expiryDate);

            printf("Enter Medicine Quantity: ");
            scanf("%d", &med.quantity);

            printf("Enter Medicine Price: ");
            scanf("%f", &med.price);

            fseek(file, -sizeof(Medicine), SEEK_CUR);
            fwrite(&med, sizeof(Medicine), 1, file);

            printf("\nMedicine updated successfully.\n");
            fclose(file);
            return;
        }
    }

    printf("\nMedicine not found.\n");
    fclose(file);
}

// Function to delete medicine information
void deleteMedicine() {
    int id;
    Medicine med;
    FILE *file = fopen("medicine.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (file == NULL || temp == NULL) {
        printf("\nUnable to open file.\n");
        return;
    }

    printf("\nEnter Medicine ID to delete: ");
    scanf("%d", &id);

    while (fread(&med, sizeof(Medicine), 1, file)) {
        if (med.id != id) {
            fwrite(&med, sizeof(Medicine), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);

    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");

    printf("\nMedicine deleted successfully.\n");
}

// Function to display main menu
void displayMenu() {
    printf("\n------ Medical Store Management System Menu ------\n");
    printf("1. Add new Medicine\n");
    printf("2. Edit Medicine information\n");
    printf("3. Delete Medicine information\n");
    printf("4. View All Medicines\n");
    printf("5. Search Medicines\n");
    printf("6. Exit\n");
}

// Function to view all medicines
void viewAllMedicines() {
    Medicine med;
    FILE *file = fopen("medicine.txt", "r");

    if (file == NULL) {
        printf("\nUnable to open file.\n");
        return;
    }

    printf("\n------ All Medicines List ------\n");

    while (fread(&med, sizeof(Medicine), 1, file)) {
        printf("\nMedicine ID         : %d", med.id);
        printf("\nMedicine Name       : %s", med.name);
        printf("\nMedicine Quantity   : %d", med.quantity);
        printf("\nMedicine Manufacturer : %s", med.manufacturer);
        printf("\nMedicine Expiry Date  : %s", med.expiryDate);
        printf("\nMedicine Price        : %.2f\n", med.price);
    }

    fclose(file);
}

// Function to search for a medicine
void searchMedicine() {
    int id;
    Medicine med;
    FILE *file = fopen("medicine.txt", "r");

    if (file == NULL) {
        printf("\nUnable to open file.\n");
        return;
    }

    printf("\nEnter Medicine ID to search: ");
    scanf("%d", &id);

    while (fread(&med, sizeof(Medicine), 1, file)) {
        if (med.id == id) {
            printf("\nMedicine ID         : %d", med.id);
            printf("\nMedicine Name       : %s", med.name);
            printf("\nMedicine Quantity   : %d", med.quantity);
            printf("\nMedicine Manufacturer : %s", med.manufacturer);
            printf("\nMedicine Expiry Date  : %s", med.expiryDate);
            printf("\nMedicine Price        : %.2f\n", med.price);
            fclose(file);
            return;
        }
    }

    printf("\nMedicine not found.\n");
    fclose(file);
}