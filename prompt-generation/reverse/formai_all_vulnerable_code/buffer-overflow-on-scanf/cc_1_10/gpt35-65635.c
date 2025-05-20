//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Define structure for the medicine record */
typedef struct Medicine {
    char name[50];
    char category[50];
    char manufacturer[50];
    int price;
    int quantity;
} Medicine;

/* Define global array of medicines */
Medicine medicines[100];
int numMedicines = 0;

/* Define functions for the menu options */
void addMedicine();
void searchMedicine();
void updateMedicine();
void deleteMedicine();
void displayMedicines();

int main() {
    int choice;

    do {
        /* Display menu options */
        printf("\n==== Medical Store Management System ====\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Update Medicine\n");
        printf("4. Delete Medicine\n");
        printf("5. Display Medicines\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                updateMedicine();
                break;
            case 4:
                deleteMedicine();
                break;
            case 5:
                displayMedicines();
                break;
            case 6:
                printf("\nThank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 6);

    return 0;
}

/* Function to add a medicine to the store */
void addMedicine() {
    Medicine medicine;

    /* Get details of medicine to be added */
    printf("\nEnter name of medicine: ");
    scanf(" %[^\n]s", medicine.name);
    printf("Enter category of medicine: ");
    scanf(" %[^\n]s", medicine.category);
    printf("Enter manufacturer of medicine: ");
    scanf(" %[^\n]s", medicine.manufacturer);
    printf("Enter price of medicine: ");
    scanf("%d", &medicine.price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &medicine.quantity);

    /* Add medicine to array */
    medicines[numMedicines] = medicine;
    numMedicines++;

    printf("\nMedicine added successfully!\n");
}

/* Function to search for a medicine in the store */
void searchMedicine() {
    char searchName[50];
    int i, found = 0;

    /* Get name of medicine to search for */
    printf("\nEnter name of medicine to search for: ");
    scanf(" %[^\n]s", searchName);

    /* Convert search name to lowercase */
    for (i = 0; i < strlen(searchName); i++) {
        searchName[i] = tolower(searchName[i]);
    }

    /* Search for medicine in array */
    printf("\nSearch results:\n");
    for (i = 0; i < numMedicines; i++) {
        char lowerName[50];
        strcpy(lowerName, medicines[i].name);

        /* Convert medicine name to lowercase */
        int j;
        for (j = 0; j < strlen(lowerName); j++) {
            lowerName[j] = tolower(lowerName[j]);
        }

        /* Check if search name matches medicine name */
        if (strstr(lowerName, searchName) != NULL) {
            printf("Name: %s\n", medicines[i].name);
            printf("Category: %s\n", medicines[i].category);
            printf("Manufacturer: %s\n", medicines[i].manufacturer);
            printf("Price: Rs. %d\n", medicines[i].price);
            printf("Quantity: %d\n", medicines[i].quantity);
            found = 1;
        }
    }

    /* Display message if no medicines found */
    if (!found) {
        printf("No medicines found!\n");
    }
}

/* Function to update details of a medicine in the store */
void updateMedicine() {
    char searchName[50];
    int i, found = 0;

    /* Get name of medicine to update */
    printf("\nEnter name of medicine to update: ");
    scanf(" %[^\n]s", searchName);

    /* Convert search name to lowercase */
    for (i = 0; i < strlen(searchName); i++) {
        searchName[i] = tolower(searchName[i]);
    }

    /* Search for medicine in array */
    for (i = 0; i < numMedicines; i++) {
        char lowerName[50];
        strcpy(lowerName, medicines[i].name);

        /* Convert medicine name to lowercase */
        int j;
        for (j = 0; j < strlen(lowerName); j++) {
            lowerName[j] = tolower(lowerName[j]);
        }

        /* Check if search name matches medicine name */
        if (strcmp(lowerName, searchName) == 0) {
            /* Get updated details of medicine */
            printf("\nEnter updated details of medicine:\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Enter updated category of medicine: ");
            scanf(" %[^\n]s", medicines[i].category);
            printf("Enter updated manufacturer of medicine: ");
            scanf(" %[^\n]s", medicines[i].manufacturer);
            printf("Enter updated price of medicine: ");
            scanf("%d", &medicines[i].price);
            printf("Enter updated quantity of medicine: ");
            scanf("%d", &medicines[i].quantity);

            printf("\nMedicine updated successfully!\n");
            found = 1;
            break;
        }
    }

    /* Display message if medicine not found */
    if (!found) {
        printf("Medicine not found!\n");
    }
}

/* Function to delete a medicine from the store */
void deleteMedicine() {
    char searchName[50];
    int i, found = 0;

    /* Get name of medicine to delete */
    printf("\nEnter name of medicine to delete: ");
    scanf(" %[^\n]s", searchName);

    /* Convert search name to lowercase */
    for (i = 0; i < strlen(searchName); i++) {
        searchName[i] = tolower(searchName[i]);
    }

    /* Search for medicine in array */
    for (i = 0; i < numMedicines; i++) {
        char lowerName[50];
        strcpy(lowerName, medicines[i].name);

        /* Convert medicine name to lowercase */
        int j;
        for (j = 0; j < strlen(lowerName); j++) {
            lowerName[j] = tolower(lowerName[j]);
        }

        /* Check if search name matches medicine name */
        if (strcmp(lowerName, searchName) == 0) {
            /* Delete medicine from array */
            int k;
            for (k = i; k < numMedicines - 1; k++) {
                medicines[k] = medicines[k+1];
            }
            numMedicines--;

            printf("\nMedicine deleted successfully!\n");
            found = 1;
            break;
        }
    }

    /* Display message if medicine not found */
    if (!found) {
        printf("Medicine not found!\n");
    }
}

/* Function to display all medicines in the store */
void displayMedicines() {
    int i;

    printf("\n==== List of Medicines ====\n");
    /* Display header */
    printf("%-25s %-15s %-20s %-10s %-10s\n", "Name", "Category", "Manufacturer", "Price", "Quantity");

    /* Display each medicine */
    for (i = 0; i < numMedicines; i++) {
        printf("%-25s %-15s %-20s %-10d %-10d\n", medicines[i].name, medicines[i].category, medicines[i].manufacturer, medicines[i].price, medicines[i].quantity);
    }
}