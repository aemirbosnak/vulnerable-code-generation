//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine store[MAX_MEDICINES];
int count = 0;

void addMedicine() {
    if (count >= MAX_MEDICINES) {
        printf("Store is full! Cannot add more medicines.\n");
        return;
    }
    printf("Enter medicine name: ");
    scanf("%s", store[count].name);
    printf("Enter quantity: ");
    scanf("%d", &store[count].quantity);
    printf("Enter price: ");
    scanf("%f", &store[count].price);
    count++;
    printf("Medicine added successfully.\n");
}

void displayMedicines() {
    if (count == 0) {
        printf("No medicines available in the store.\n");
        return;
    }
    printf("\nMedicines in store:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Quantity: %d, Price: %.2f\n", 
               i + 1, store[i].name, store[i].quantity, store[i].price);
    }
}

void updateMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            printf("Current quantity: %d. Enter new quantity: ", store[i].quantity);
            scanf("%d", &store[i].quantity);
            printf("Updated successfully.\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[NAME_LENGTH];
    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(store[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                store[j] = store[j + 1];
            }
            count--;
            printf("Medicine deleted successfully.\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

void displayMenu() {
    printf("\nMedical Store Management System\n");
    printf("1. Add Medicine\n");
    printf("2. Display Medicines\n");
    printf("3. Update Medicine\n");
    printf("4. Delete Medicine\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: 
                addMedicine(); 
                break;
            case 2: 
                displayMedicines(); 
                break;
            case 3: 
                updateMedicine(); 
                break;
            case 4: 
                deleteMedicine(); 
                break;
            case 5: 
                printf("Exiting the program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}