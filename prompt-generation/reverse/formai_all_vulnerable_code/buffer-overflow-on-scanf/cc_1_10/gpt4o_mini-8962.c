//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50
#define EXPIRY_LENGTH 11

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
    char expiryDate[EXPIRY_LENGTH];
} Medicine;

void addMedicine(Medicine *medicines, int *count);
void displayMedicines(Medicine *medicines, int count);
void deleteMedicine(Medicine *medicines, int *count);
void searchMedicine(Medicine *medicines, int count);
void displayMenu();

int main() {
    Medicine medicines[MAX_MEDICINES];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: 
                addMedicine(medicines, &count);
                break;
            case 2: 
                displayMedicines(medicines, count);
                break;
            case 3:
                deleteMedicine(medicines, &count);
                break;
            case 4:
                searchMedicine(medicines, count);
                break;
            case 5:
                printf("Exiting the program. Have a great day!\n");
                break;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}

void displayMenu() {
    printf("\n-------- Medical Store Management --------\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Delete Medicine\n");
    printf("4. Search Medicine\n");
    printf("5. Exit\n");
    printf("-------------------------------------------\n");
}

void addMedicine(Medicine *medicines, int *count) {
    if (*count < MAX_MEDICINES) {
        Medicine newMedicine;
        printf("Enter the name of the medicine: ");
        scanf("%s", newMedicine.name);
        printf("Enter the quantity: ");
        scanf("%d", &newMedicine.quantity);
        printf("Enter the price: ");
        scanf("%f", &newMedicine.price);
        printf("Enter the expiry date (YYYY-MM-DD): ");
        scanf("%s", newMedicine.expiryDate);
        
        medicines[*count] = newMedicine;
        (*count)++;
        printf("Medicine added successfully!\n");
    } else {
        printf("Cannot add more medicines. Limit reached!\n");
    }
}

void displayMedicines(Medicine *medicines, int count) {
    if (count == 0) {
        printf("No medicines to display.\n");
        return;
    }
    printf("\n           Medicines in Stock           \n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s | Quantity: %d | Price: %.2f | Expiry Date: %s\n",
               medicines[i].name, medicines[i].quantity, medicines[i].price, medicines[i].expiryDate);
    }
    printf("-------------------------------------------------\n");
}

void deleteMedicine(Medicine *medicines, int *count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < *count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            medicines[i] = medicines[--(*count)];
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void searchMedicine(Medicine *medicines, int count) {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Found! Name: %s | Quantity: %d | Price: %.2f | Expiry Date: %s\n",
                   medicines[i].name, medicines[i].quantity, medicines[i].price, medicines[i].expiryDate);
            return;
        }
    }
    printf("Medicine not found!\n");
}