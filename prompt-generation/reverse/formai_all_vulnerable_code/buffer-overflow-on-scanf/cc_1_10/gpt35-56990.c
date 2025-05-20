//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_MED 100 // Maximum number of Medicines
#define MAX_NAME 100 // Maximum length of Medicine Name
#define MAX_COMPANY 100 // Maximum length of Company Name

// Medicine Structure
typedef struct {
    char name[MAX_NAME];
    char company[MAX_COMPANY];
    float price;
    int quantity;
} Medicine;

// Global Variables
Medicine medicines[MAX_MED];
int numMedicines = 0;

// Function Declaration
void addMedicine();
void displayMedicines();
void buyMedicine();

int main() {
    printf("\n===================C Medical Store Management System===================\n\n");
    int i, choice = 0;
    while(choice != 4) {
        printf("\n1. Add a Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Buy a Medicine\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: addMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: buyMedicine(); break;
            case 4: break;
            default: printf("\nInvalid Choice! Try Again.");
        }
    }
    printf("\nExiting.\n\n");
    return 0;
}

// Function to Add a Medicine
void addMedicine() {
    if(numMedicines == MAX_MED) {
        printf("\nSorry, the Maximum Limit has been reached.");
        return;
    }

    printf("\nEnter the Medicine Name: ");
    scanf("%s", medicines[numMedicines].name);

    printf("\nEnter the Company Name: ");
    scanf("%s", medicines[numMedicines].company);

    printf("\nEnter the Medicine Price: ");
    scanf("%f", &medicines[numMedicines].price);

    printf("\nEnter the Quantity: ");
    scanf("%d", &medicines[numMedicines].quantity);

    numMedicines++; // Increment the Number of Medicines Count
    printf("\nMedicine Added Successfully!");
}

// Function to Display all Medicines
void displayMedicines() {
    printf("\n==========Medicines Available:==========\n");
    printf("\n%-30s   %-20s   %10s   %10s\n", "Name", "Company", "Price", "Quantity");
    int i;
    for(i = 0; i < numMedicines; i++)
        printf("\n%-30s   %-20s   %10.2f   %10d", medicines[i].name, medicines[i].company, medicines[i].price, medicines[i].quantity);
}

// Function to Buy a Medicine
void buyMedicine() {
    char medicineName[MAX_NAME];
    printf("\nEnter the Medicine Name to Buy: ");
    scanf("%s", medicineName);

    int i, found = 0;
    for(i = 0; i < numMedicines; i++) {
        if(strcmp(medicineName, medicines[i].name) == 0) {
            found = 1;
            break;
        }
    }

    if(found) {
        int quantity;
        printf("\nEnter the Required Quantity: ");
        scanf("%d", &quantity);

        if(quantity <= medicines[i].quantity) {
            printf("\nTotal Price: %.2f", medicines[i].price * quantity);
            medicines[i].quantity -= quantity;
            printf("\nMedicine Purchased Successfully!");
        }
        else {
            printf("\nRequired Quantity is not Available.");
        }
    }
    else {
        printf("\nMedicine not Available.");
    }
}