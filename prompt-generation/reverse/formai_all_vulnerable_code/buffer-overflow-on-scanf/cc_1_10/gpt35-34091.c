//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCK 1000 // maximum stock capacity
#define MAX_NAME_LENGTH 50 // maximum length of medicine name

// declare a structure to hold medicine information
struct Medicine {
    int id;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

// declare an array to hold medicines in stock
struct Medicine stock[MAX_STOCK];

// declare a variable to hold the number of medicines in stock
int numMedicines = 0;

// function to add a new medicine to stock
void addMedicine() {
    // check if stock is already full
    if (numMedicines == MAX_STOCK) {
        printf("Medicine stock is full. Cannot add more medicines.\n");
        return;
    }
    
    // prompt user to enter medicine information
    struct Medicine newMedicine;
    printf("Enter medicine name: ");
    scanf("%s", newMedicine.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &newMedicine.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &newMedicine.price);
    
    // assign unique id to medicine
    newMedicine.id = numMedicines + 1;
    
    // add medicine to stock
    stock[numMedicines++] = newMedicine;
    
    printf("Medicine added successfully!\n");
}

// function to search for a medicine by name
int searchMedicine(char *name) {
    // iterate through medicines in stock
    for (int i = 0; i < numMedicines; i++) {
        // compare medicine name with search query
        if (strcmp(stock[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // medicine not found
}

// function to remove a medicine from stock
void removeMedicine(char *name) {
    // search for medicine in stock
    int index = searchMedicine(name);
    if (index == -1) {
        printf("Medicine not found in stock.\n");
        return;
    }
    
    // remove medicine from stock by shifting all subsequent items to the left
    for (int i = index; i < numMedicines - 1; i++) {
        stock[i] = stock[i+1];
    }
    numMedicines--;
    
    printf("Medicine removed from stock successfully!\n");
}

// function to update the quantity of a medicine in stock
void updateQuantity(char *name, int quantity) {
    // search for medicine in stock
    int index = searchMedicine(name);
    if (index == -1) {
        printf("Medicine not found in stock.\n");
        return;
    }
    
    // update quantity of medicine
    stock[index].quantity = quantity;
    
    printf("Medicine quantity updated successfully!\n");
}

// function to update the price of a medicine in stock
void updatePrice(char *name, float price) {
    // search for medicine in stock
    int index = searchMedicine(name);
    if (index == -1) {
        printf("Medicine not found in stock.\n");
        return;
    }
    
    // update price of medicine
    stock[index].price = price;
    
    printf("Medicine price updated successfully!\n");
}

// function to display all medicines in stock
void displayStock() {
    printf("%-10s%-20s%-10s%-10s\n", "ID", "NAME", "QUANTITY", "PRICE");
    for (int i = 0; i < numMedicines; i++) {
        struct Medicine med = stock[i];
        printf("%-10d%-20s%-10d%-10.2f\n", med.id, med.name, med.quantity, med.price);
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
    
    do {
        // display menu
        printf("\nMEDICINE STORE MANAGEMENT SYSTEM\n");
        printf("1. Add new medicine to stock\n");
        printf("2. Remove medicine from stock\n");
        printf("3. Update medicine quantity in stock\n");
        printf("4. Update medicine price in stock\n");
        printf("5. Display all medicines in stock\n");
        printf("6. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine();
                break;
                
            case 2:
                printf("Enter medicine name to remove: ");
                scanf("%s", name);
                removeMedicine(name);
                break;
                
            case 3:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                updateQuantity(name, quantity);
                break;
                
            case 4:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                updatePrice(name, price);
                break;
                
            case 5:
                displayStock();
                break;
                
            case 6:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);
    
    return 0;
}