//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STR_LENGTH 100 //maximum string length for input values

//structure to store details of a medicine
typedef struct {
    char name[MAX_STR_LENGTH];
    int quantity;
    float price;
} Medicine;

//function to add a medicine to the inventory
void addMedicine(Medicine* inventory, int* numMedicines) {
    printf("Enter name of the medicine: ");
    scanf("%s", inventory[*numMedicines].name);
    printf("Enter quantity of the medicine: ");
    scanf("%d", &inventory[*numMedicines].quantity);
    printf("Enter price of the medicine: ");
    scanf("%f", &inventory[*numMedicines].price);
    (*numMedicines)++;
    printf("Medicine added successfully!\n");
}

//function to update quantity of an existing medicine in the inventory
void updateQuantity(Medicine* inventory, int numMedicines) {
    char name[MAX_STR_LENGTH];
    int found = 0;
    printf("Enter name of the medicine to update quantity: ");
    scanf("%s", name);
    for(int i=0;i<numMedicines;i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            found = 1;
            int quantity;
            printf("Enter new quantity of the medicine: ");
            scanf("%d", &quantity);
            inventory[i].quantity = quantity;
            printf("Quantity updated successfully!\n");
            break;
        }
    }
    if(!found) {
        printf("Medicine not found in inventory!\n");
    }
}

//function to display details of all medicines in the inventory
void displayInventory(Medicine* inventory, int numMedicines) {
    printf("Inventory Details:\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    for(int i=0;i<numMedicines;i++) {
        printf("%-20s %-10d %-10.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int choice, numMedicines = 0;
    Medicine inventory[100];
    while(1) {
        printf("\n1. Add Medicine\n2. Update Quantity\n3. Display Inventory\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addMedicine(inventory, &numMedicines);
                break;
            case 2:
                updateQuantity(inventory, numMedicines);
                break;
            case 3:
                displayInventory(inventory, numMedicines);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}