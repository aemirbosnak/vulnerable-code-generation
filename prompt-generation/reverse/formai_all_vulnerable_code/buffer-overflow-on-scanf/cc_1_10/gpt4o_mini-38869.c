//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100

// Structure to represent a medicine
typedef struct {
    char name[50];
    char company[50];
    int quantity;
    float price;
} Medicine;

// Function prototypes
void addMedicine(Medicine medicines[], int *count);
void displayMedicines(Medicine medicines[], int count);
void searchMedicine(Medicine medicines[], int count);
void updateMedicine(Medicine medicines[], int count);
void deleteMedicine(Medicine medicines[], int *count);

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    while (1) {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayMedicines(medicines, count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                updateMedicine(medicines, count);
                break;
            case 5:
                deleteMedicine(medicines, &count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addMedicine(Medicine medicines[], int *count) {
    if (*count >= MAX_MEDICINES) {
        printf("Cannot add more medicines. Storage full!\n");
        return;
    }
    
    Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter company name: ");
    scanf("%s", newMedicine.company);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine.price);

    medicines[*count] = newMedicine;
    (*count)++;
    printf("Medicine added successfully!\n");
}

void displayMedicines(Medicine medicines[], int count) {
    if (count == 0) {
        printf("No medicines to display.\n");
        return;
    }
    
    printf("\nList of Medicines:\n");
    printf("%-20s %-20s %-10s %-10s\n", "Name", "Company", "Quantity", "Price");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-20s %-10d %-10.2f\n", 
                medicines[i].name, medicines[i].company, 
                medicines[i].quantity, medicines[i].price);
    }
}

void searchMedicine(Medicine medicines[], int count) {
    char searchName[50];
    int found = 0;
    printf("Enter medicine name to search: ");
    scanf("%s", searchName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, searchName) == 0) {
            printf("Medicine found: %s from %s, Quantity: %d, Price: %.2f\n", 
                   medicines[i].name, medicines[i].company, 
                   medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine(Medicine medicines[], int count) {
    char updateName[50];
    printf("Enter medicine name to update: ");
    scanf("%s", updateName);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, updateName) == 0) {
            printf("Updating medicine: %s\n", medicines[i].name);
            printf("Enter new quantity: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine updated successfully!\n");
            return;
        }
    }
    printf("Medicine not found for update!\n");
}

void deleteMedicine(Medicine medicines[], int *count) {
    char deleteName[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", deleteName);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, deleteName) == 0) {
            for (int j = i; j < *count - 1; j++) {
                medicines[j] = medicines[j + 1];
            }
            (*count)--;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found for deletion!\n");
}