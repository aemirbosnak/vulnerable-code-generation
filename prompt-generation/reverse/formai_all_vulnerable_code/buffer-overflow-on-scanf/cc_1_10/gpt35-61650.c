//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold medicine information
typedef struct medicine {
    char name[50];
    float price;
    int quantity;
} Medicine;

// Function declaration
void addMedicine(Medicine m, int n);
void sellMedicine(Medicine m[], int n);
void displayDetails(Medicine m[], int n);

// Global array of medicine
Medicine meds[100];

int main() {
    int ch, n = 0;
    Medicine m;

    printf("-------------\n");
    printf("| Welcome to |\n");
    printf("|   C Meds   |\n");
    printf("-------------\n\n");

    do {
        printf("Select an option:\n");
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Display all medicine details\n");
        printf("4. Exit\n");

        scanf("%d", &ch);
        switch(ch) {
            case 1: // Add medicine
                printf("Enter medicine name: ");
                scanf("%s", m.name);
                printf("Enter medicine price: ");
                scanf("%f", &m.price);
                printf("Enter medicine quantity: ");
                scanf("%d", &m.quantity);
                addMedicine(m, n);
                n++;
                break;

            case 2: //Sell medicine
                sellMedicine(meds, n);
                break;

            case 3: // Display all medicine details
                displayDetails(meds, n);
                break;

            case 4: // Exit
                printf("Thank you for using C Meds.\n");
                exit(0);

            default: // Invalid input
                printf("Invalid input.\n");
        }
        printf("\n");
    } while(ch != 4);

    return 0;
}

// Function to add medicine to global array
void addMedicine(Medicine m, int n) {
    meds[n] = m;
    printf("%s added to inventory.\n", meds[n].name);
}

// Function to sell medicine
void sellMedicine(Medicine m[], int n) {
    char name[50];
    int qty;

    printf("Enter name of medicine to sell: ");
    scanf("%s", name);

    for(int i = 0; i < n ; i++) {
        if(strcmp(name, m[i].name) == 0) {
            printf("Enter quantity to sell: ");
            scanf("%d", &qty);
            if(qty <= m[i].quantity) {
                m[i].quantity -= qty;
                printf("%d %s sold for total of $%.2f.\n", qty, m[i].name, m[i].price * qty);
            }
            else {
                printf("Insufficient quantity of %s.\n", m[i].name);
            }
            return;
        }
    }
    printf("%s not found.\n", name);
}

// Function to display all medicine details
void displayDetails(Medicine m[], int n) {
    if(n == 0) {
        printf("Medicine inventory is empty.\n");
    }
    else {
        printf("%-20s%-10s%-10s\n", "Medicine Name", "Price", "Quantity");
        for(int i = 0 ; i < n ; i++) {
            printf("%-20s%-10.2f%-10d\n", m[i].name, m[i].price, m[i].quantity);
        }
    }
}