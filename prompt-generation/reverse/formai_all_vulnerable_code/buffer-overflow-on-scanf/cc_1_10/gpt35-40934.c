//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

void displayMedicine(struct Medicine m) {
    printf("%d\t%s\t%d\t%.2f\n", m.id, m.name, m.quantity, m.price);
}

void displayMenu() {
    printf("\n==== MEDICAL STORE MANAGEMENT SYSTEM ====\n");
    printf("1. Add Medicine\n");
    printf("2. Display All Medicines\n");
    printf("3. Search Medicine by Name\n");
    printf("4. Update Medicine Quantity\n");
    printf("5. Delete Medicine\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void addMedicine(struct Medicine *medicines, int *count) {
    struct Medicine m;
    printf("\nEnter details of medicine:\n");
    printf("ID: ");
    scanf("%d", &m.id);
    printf("Name: ");
    scanf("%s", m.name);
    printf("Quantity: ");
    scanf("%d", &m.quantity);
    printf("Price: ");
    scanf("%f", &m.price);
    
    medicines[*count] = m;
    *count += 1;
    
    printf("\nMedicine added successfully!\n");
}

void displayAllMedicines(struct Medicine *medicines, int count) {
    printf("\n==== ALL MEDICINES ====\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        displayMedicine(medicines[i]);
    }
}

void searchMedicineByName(struct Medicine *medicines, int count) {
    char name[50];
    printf("\nEnter name of medicine to search: ");
    scanf("%s", name);
    printf("\n==== SEARCHED MEDICINES ====\n");
    printf("ID\tName\tQuantity\tPrice\n");
    for(int i=0; i<count; i++) {
        if(strcmp(medicines[i].name, name) == 0) {
            displayMedicine(medicines[i]);
            return;
        }
    }
    printf("Sorry, medicine with name '%s' not found.\n", name);
}

void updateMedicineQuantity(struct Medicine *medicines, int count) {
    int id, quantity;
    printf("\nEnter ID of medicine to update quantity: ");
    scanf("%d", &id);
    for(int i=0; i<count; i++) {
        if(medicines[i].id == id) {
            printf("Enter new quantity: ");
            scanf("%d", &quantity);
            medicines[i].quantity = quantity;
            printf("\nQuantity updated successfully!\n");
            return;
        }
    }
    printf("Sorry, medicine with ID '%d' not found.\n", id);
}

void deleteMedicine(struct Medicine *medicines, int *count) {
    int id;
    printf("\nEnter ID of medicine to delete: ");
    scanf("%d", &id);
    for(int i=0; i<*count; i++) {
        if(medicines[i].id == id) {
            for(int j=i; j<*count-1; j++) {
                medicines[j] = medicines[j+1];
            }
            *count -= 1;
            printf("\nMedicine deleted successfully!\n");
            return;
        }
    }
    printf("Sorry, medicine with ID '%d' not found.\n", id);
}

int main() {
    struct Medicine medicines[100];
    int count = 0;
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                displayAllMedicines(medicines, count);
                break;
            case 3:
                searchMedicineByName(medicines, count);
                break;
            case 4:
                updateMedicineQuantity(medicines, count);
                break;
            case 5:
                deleteMedicine(medicines, &count);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
        
    } while(choice != 6);
    
    return 0;
}