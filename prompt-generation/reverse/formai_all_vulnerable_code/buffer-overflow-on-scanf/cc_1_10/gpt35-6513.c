//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for medicines
struct Medicine {
    char name[50];
    char manufacturer[50];
    int quantity;
    float price;
};

// Declare global variables
struct Medicine medicines[100];
int count = 0;

// Function to add a new medicine
void addMedicine() {
    printf("Enter medicine name: ");
    scanf("%s", medicines[count].name);
    
    printf("Enter manufacturer name: ");
    scanf("%s", medicines[count].manufacturer);
    
    printf("Enter quantity: ");
    scanf("%d", &medicines[count].quantity);
    
    printf("Enter price: ");
    scanf("%f", &medicines[count].price);
    
    count++;
}

// Function to display all medicines
void viewAllMedicines() {
    if (count == 0) {
        printf("No medicines in stock\n");
        return;
    }
    
    printf("Medicine\t\tManufacturer\t\tQuantity\t\tPrice\n");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t\t\t%d\t\t\t%.2f\n", medicines[i].name, medicines[i].manufacturer, medicines[i].quantity, medicines[i].price);
    }
}

// Function to search for a medicine
void searchMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine details\n");
            printf("Name: %s\n", medicines[i].name);
            printf("Manufacturer: %s\n", medicines[i].manufacturer);
            printf("Quantity: %d\n", medicines[i].quantity);
            printf("Price: %.2f\n", medicines[i].price);
            return;
        }
    }
    
    printf("Medicine not found\n");
}

// Function to update medicine details
void updateMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf("%s", name);
    
    for (int i = 0; i < count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Enter quantity: ");
            scanf("%d", &medicines[i].quantity);
    
            printf("Enter price: ");
            scanf("%f", &medicines[i].price);
            printf("Medicine details updated\n");
            return;
        }
    }
    
    printf("Medicine not found\n");
}

// Driver function
int main() {
    int choice;
    
    while (1) {
        printf("Enter your choice\n");
        printf("1. Add medicine\n");
        printf("2. View all medicines\n");
        printf("3. Search for medicine\n");
        printf("4. Update medicine details\n");
        printf("5. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                viewAllMedicines();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}