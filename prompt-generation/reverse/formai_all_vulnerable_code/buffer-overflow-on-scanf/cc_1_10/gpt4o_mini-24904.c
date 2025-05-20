//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold medication information
typedef struct {
    int id;
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} Medication;

// Function prototypes
void addMedication(Medication *meds, int *count);
void viewMedications(Medication *meds, int count);
void searchMedication(Medication *meds, int count);

int main() {
    Medication *medications = malloc(100 * sizeof(Medication));
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medication\n");
        printf("2. View All Medications\n");
        printf("3. Search Medication\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedication(medications, &count);
                break;
            case 2:
                viewMedications(medications, count);
                break;
            case 3:
                searchMedication(medications, count);
                break;
            case 4:
                free(medications);
                printf("Exiting the medical store management system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Kindly try again.\n");
        }
    }
}

void addMedication(Medication *meds, int *count) {
    printf("Enter Medication ID: ");
    scanf("%d", &meds[*count].id);
    printf("Enter Medication Name: ");
    scanf("%s", meds[*count].name);
    printf("Enter Manufacturer: ");
    scanf("%s", meds[*count].manufacturer);
    printf("Enter Price: ");
    scanf("%f", &meds[*count].price);
    printf("Enter Quantity: ");
    scanf("%d", &meds[*count].quantity);
    (*count)++;
    printf("Medication added successfully!\n");
}

void viewMedications(Medication *meds, int count) {
    if (count == 0) {
        printf("No medications available.\n");
        return;
    }
    printf("\n--- List of Medications ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
               meds[i].id, meds[i].name, meds[i].manufacturer, meds[i].price, meds[i].quantity);
    }
}

void searchMedication(Medication *meds, int count) {
    char name[50];
    printf("Enter Medication Name to Search: ");
    scanf("%s", name);
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(meds[i].name, name) == 0) {
            printf("Medication found: ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n",
                   meds[i].id, meds[i].name, meds[i].manufacturer, meds[i].price, meds[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Medication not found.\n");
    }
}