//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of medicines in the store
#define MAX_MEDICINES 1000

// Define the structure of the medicine
typedef struct {
    char name[50];
    char company[50];
    int quantity;
    float price;
} Medicine;

// Define an array of medicines in the store
Medicine medicines[MAX_MEDICINES];

// Define the total number of medicines currently available in the store
int numMedicines = 0;

// Function to add a new medicine to the store
void addMedicine(char name[], char company[], int quantity, float price) {
    if (numMedicines < MAX_MEDICINES) {
        strcpy(medicines[numMedicines].name, name);
        strcpy(medicines[numMedicines].company, company);
        medicines[numMedicines].quantity = quantity;
        medicines[numMedicines].price = price;
        numMedicines++;
        printf("\nMedicine %s added successfully!\n\n", name);
    }
    else {
        printf("\nMedicine could not be added. Maximum capacity reached!\n\n");
    }
}

// Function to view all the medicines in the store
void viewMedicines() {
    printf("\n%-30s %-20s %-10s %-10s\n", "Medicine Name", "Company", "Quantity", "Price");
    for (int i = 0; i < numMedicines; i++) {
        printf("%-30s %-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].company,
            medicines[i].quantity, medicines[i].price);
    }
    printf("\n");
}

// Function to search for a medicine by its name
void searchMedicine(char name[]) {
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            printf("\n%-30s %-20s %-10s %-10s\n", "Medicine Name", "Company", "Quantity", "Price");
            printf("%-30s %-20s %-10d %-10.2f\n", medicines[i].name, medicines[i].company,
                medicines[i].quantity, medicines[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found!\n\n");
    }
}

// Function to buy a medicine from the store
void buyMedicine(char name[], int quantity) {
    int found = 0;
    for (int i = 0; i < numMedicines; i++) {
        if (strcmp(name, medicines[i].name) == 0) {
            if (medicines[i].quantity >= quantity) {
                float total = medicines[i].price * quantity;
                medicines[i].quantity -= quantity;
                printf("\nMedicine purchased successfully!\n");
                printf("Medicine Name: %s\n", medicines[i].name);
                printf("Quantity Purchased: %d\n", quantity);
                printf("Total Price: %.2f\n", total);
            }
            else {
                printf("\nInsufficient stock available!\n");
            }
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nMedicine not found!\n\n");
    }
}

int main() {
    int choice;
    char name[50];
    char company[50];
    int quantity;
    float price;

    do {
        printf("==== Medical Store Management System ====\n");
        printf("1. Add a new medicine\n");
        printf("2. View all medicines\n");
        printf("3. Search for a medicine\n");
        printf("4. Buy a medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter medicine name: ");
                fflush(stdin);
                gets(name);
                printf("Enter company name: ");
                gets(company);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                printf("Enter price: ");
                scanf("%f", &price);
                addMedicine(name, company, quantity, price);
                break;

            case 2:
                viewMedicines();
                break;

            case 3:
                printf("\nEnter medicine name: ");
                fflush(stdin);
                gets(name);
                searchMedicine(name);
                break;

            case 4:
                printf("\nEnter medicine name: ");
                fflush(stdin);
                gets(name);
                printf("Enter quantity to buy: ");
                scanf("%d", &quantity);
                buyMedicine(name, quantity);
                break;

            case 5:
                printf("\nThank you for using our system!\n\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n\n");
                break;
        }
    } while (choice != 5);

    return 0;
}