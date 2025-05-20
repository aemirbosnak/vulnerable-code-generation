//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold information about a medicine
typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function prototypes
void addMedicine(Medicine m[], int *count);
void viewMedicines(Medicine m[], int count);
void updateMedicine(Medicine m[], int count);
void deleteMedicine(Medicine m[], int *count);
void searchMedicine(Medicine m[], int count);
void menu();

// Main function
int main() {
    Medicine medicines[100];
    int count = 0;
    int choice;

    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                viewMedicines(medicines, count);
                break;
            case 3:
                updateMedicine(medicines, count);
                break;
            case 4:
                deleteMedicine(medicines, &count);
                break;
            case 5:
                searchMedicine(medicines, count);
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void menu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. View Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Search Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a medicine
void addMedicine(Medicine m[], int *count) {
    printf("Enter Medicine ID: ");
    scanf("%d", &m[*count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", m[*count].name);
    printf("Enter Medicine Price: ");
    scanf("%f", &m[*count].price);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &m[*count].quantity);
    (*count)++;
    printf("Medicine added successfully!\n");
}

// Function to view all medicines
void viewMedicines(Medicine m[], int count) {
    printf("\nMedicines in the store:\n");
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
    }
}

// Function to update a medicine
void updateMedicine(Medicine m[], int count) {
    int id, found = 0;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (m[i].id == id) {
            printf("Updating Medicine: %s\n", m[i].name);
            printf("Enter new Name: ");
            scanf("%s", m[i].name);
            printf("Enter new Price: ");
            scanf("%f", &m[i].price);
            printf("Enter new Quantity: ");
            scanf("%d", &m[i].quantity);
            found = 1;
            printf("Medicine updated successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}

// Function to delete a medicine
void deleteMedicine(Medicine m[], int *count) {
    int id, found = 0;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (m[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                m[j] = m[j + 1];
            }
            (*count)--;
            found = 1;
            printf("Medicine deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Medicine with ID %d not found!\n", id);
    }
}

// Function to search for a medicine by name
void searchMedicine(Medicine m[], int count) {
    char name[50];
    int found = 0;
    printf("Enter Medicine Name to search: ");
    scanf("%s", name);

    printf("\nMedicines matching '%s':\n", name);
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        if (strstr(m[i].name, name) != NULL) {
            printf("%d\t%s\t%.2f\t%d\n", m[i].id, m[i].name, m[i].price, m[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("No medicines found matching '%s'.\n", name);
    }
}