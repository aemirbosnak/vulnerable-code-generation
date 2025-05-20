//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 1000
#define MAX_NAME_LENGTH 50

/* A struct to store information about a single medicine */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

/* A struct to store information about all medicines in stock */
typedef struct {
    int numMedicines;
    Medicine medicines[MAX_MEDICINES];
} Inventory;

/* Function prototypes */
void addMedicine(Inventory *inv);
void removeMedicine(Inventory *inv);
void displayInventory(Inventory inv);

int main() {
    Inventory inv; /* Create an empty inventory */
    inv.numMedicines = 0; /* Initialize number of medicines to zero */

    char choice;
    do {
        printf("\n---- MEDICAL STORE MANAGEMENT SYSTEM MENU ----\n");
        printf("1. Add new medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addMedicine(&inv);
                break;
            case '2':
                removeMedicine(&inv);
                break;
            case '3':
                displayInventory(inv);
                break;
            case '4':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);

    return 0;
}

/* This function adds a new medicine to the inventory */
void addMedicine(Inventory *inv) {
    /* Check if inventory is already full */
    if(inv->numMedicines == MAX_MEDICINES) {
        printf("Cannot add more medicines. Maximum limit reached.\n");
        return;
    }

    /* Get details of new medicine from user */
    Medicine m;
    printf("Enter name of medicine: ");
    scanf(" %[^\n]", m.name);

    printf("Enter quantity: ");
    scanf(" %d", &m.quantity);

    printf("Enter price: ");
    scanf(" %f", &m.price);

    /* Add the new medicine to the inventory */
    inv->medicines[inv->numMedicines++] = m;

    printf("Medicine added successfully.\n");
}

/* This function removes a medicine from the inventory */
void removeMedicine(Inventory *inv) {
    /* Check if inventory is empty */
    if(inv->numMedicines == 0) {
        printf("Cannot remove medicine. Inventory is empty.\n");
        return;
    }

    /* Get name of medicine to be removed from user */
    char name[MAX_NAME_LENGTH];
    printf("Enter name of medicine to be removed: ");
    scanf(" %[^\n]", name);

    /* Find the medicine in the inventory */
    int found = 0;
    for(int i=0; i<inv->numMedicines; i++) {
        if(strcmp(name, inv->medicines[i].name) == 0) {
            /* Move all medicines after this medicine one position to the left */
            for(int j=i+1; j<inv->numMedicines; j++) {
                inv->medicines[j-1] = inv->medicines[j];
            }

            inv->numMedicines--;
            printf("Medicine removed successfully.\n");
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Medicine not found in inventory.\n");
    }
}

/* This function displays the current inventory */
void displayInventory(Inventory inv) {
    /* Check if inventory is empty */
    if(inv.numMedicines == 0) {
        printf("Inventory is empty.\n");
    } else {
        /* Print the header */
        printf("\n%-20s %-10s %-10s\n", "NAME", "QUANTITY", "PRICE");
        printf("-----------------------------------------------\n");

        /* Print details of all medicines */
        for(int i=0; i<inv.numMedicines; i++) {
            printf("%-20s %-10d %-10.2f\n", inv.medicines[i].name, inv.medicines[i].quantity, inv.medicines[i].price);
        }
    }
}