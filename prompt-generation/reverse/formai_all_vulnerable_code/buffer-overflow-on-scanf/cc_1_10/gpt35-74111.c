//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LIMIT 100

// Structure for storing medicine details
typedef struct {
    char name[MAX_LIMIT];
    int quantity;
    float price;
} Medicine;

// Function prototypes
void displayMenu();
void addMedicine(Medicine *medicines, int *count);
void deleteMedicine(Medicine *medicines, int *count);
void searchMedicine(Medicine *medicines, int count);
void displayInventory(Medicine *medicines, int count);

int main() {
    int choice, count = 0;
    Medicine *medicines = (Medicine *)malloc(sizeof(Medicine));
    
    while(1) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addMedicine(medicines, &count);
                break;
            case 2:
                deleteMedicine(medicines, &count);
                break;
            case 3:
                searchMedicine(medicines, count);
                break;
            case 4:
                displayInventory(medicines, count);
                break;
            case 5:
                free(medicines);
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function to display menu options
void displayMenu() {
    printf("\n-------MEDICAL STORE MANAGEMENT SYSTEM-------\n\n");
    printf("1. Add Medicine\n");
    printf("2. Delete Medicine\n");
    printf("3. Search Medicine\n");
    printf("4. Display Inventory\n");
    printf("5. Exit\n");
}

// Function to add a medicine to inventory
void addMedicine(Medicine *medicines, int *count) {
    Medicine medicine;
    printf("\nEnter the name of medicine: ");
    scanf("%s", &medicine.name);
    printf("Enter the quantity of medicine: ");
    scanf("%d", &medicine.quantity);
    printf("Enter the price of medicine: ");
    scanf("%f", &medicine.price);
    *(medicines + *count) = medicine;
    *count += 1;
    printf("Medicine added successfully!\n");
}

// Function to delete medicine from inventory
void deleteMedicine(Medicine *medicines, int *count) {
    char name[MAX_LIMIT];
    printf("\nEnter the name of medicine to be deleted: ");
    scanf("%s", &name);
    
    for(int i=0; i<*count; i++) {
        if(strcmp((medicines+i)->name, name) == 0) {
            for(int j=i; j<(*count)-1; j++) {
                *(medicines+j) = *(medicines+j+1);
            }
            *count -= 1;
            printf("Medicine deleted successfully!\n");
            return;
        }
    }
    printf("Medicine not found!\n");
}

// Function to search medicine from inventory
void searchMedicine(Medicine *medicines, int count) {
    char name[MAX_LIMIT];
    printf("\nEnter the name of medicine to search: ");
    scanf("%s", &name);
    
    for(int i=0; i<count; i++) {
        if(strcmp((medicines+i)->name, name) == 0) {
            printf("\nName: %s\n", (medicines+i)->name);
            printf("Quantity: %d\n", (medicines+i)->quantity);
            printf("Price: Rs.%.2f\n", (medicines+i)->price);
            return;
        }
    }
    printf("Medicine not found!\n");
}

// Function to display inventory
void displayInventory(Medicine *medicines, int count) {
    if(count == 0) {
        printf("\nNo medicines in inventory!\n");
        return;
    }
    printf("\n------- INVENTORY -------\n");
    printf("%-20s %-20s %-20s\n", "Name", "Quantity", "Price");
    for(int i=0; i<count; i++) {
        printf("%-20s %-20d Rs.%.2f\n", (medicines+i)->name, (medicines+i)->quantity, (medicines+i)->price);
    }
}