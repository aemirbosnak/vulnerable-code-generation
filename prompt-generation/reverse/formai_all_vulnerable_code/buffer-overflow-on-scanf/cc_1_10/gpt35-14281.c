//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to hold medicine information
struct medicine {
    char name[50];
    int quantity;
    float price;
};

// function to display all the medicines in the stock
void displayMedicines(struct medicine medArr[], int size) {
    printf("********************\n");
    printf("Medicine Name\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t\t%d\t\t%.2f\n", medArr[i].name, medArr[i].quantity, medArr[i].price);
    }
    printf("********************\n");
}

// function to add new medicine to the stock
void addMedicine(struct medicine medArr[], int *size) {
    char name[50];
    int quantity;
    float price;

    printf("Enter the name of the medicine: ");
    scanf("%s", name);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);
    printf("Enter the price: ");
    scanf("%f", &price);

    // create a new medicine structure with the entered information
    struct medicine newMed = {name, quantity, price};

    // add the new medicine to the stock
    medArr[*size] = newMed;

    printf("Medicine added successfully!\n");
    (*size)++;
}

// function to search for a medicine in the stock
void searchMedicine(struct medicine medArr[], int size) {
    char name[50];
    int found = 0;

    printf("Enter the name of the medicine to search: ");
    scanf("%s", name);

    for (int i = 0; i < size; i++) {
        if (strcmp(name, medArr[i].name) == 0) {
            found = 1;
            printf("Medicine Name\tQuantity\tPrice\n");
            printf("%s\t\t%d\t\t%.2f\n", medArr[i].name, medArr[i].quantity, medArr[i].price);
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the stock!\n");
    }
}

// function to sell a medicine
void sellMedicine(struct medicine medArr[], int size) {
    char name[50];
    int quantity;
    int found = 0;

    printf("Enter the name of the medicine to sell: ");
    scanf("%s", name);
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    for (int i = 0; i < size; i++) {
        if (strcmp(name, medArr[i].name) == 0) {
            found = 1;
            if (medArr[i].quantity >= quantity) {
                medArr[i].quantity -= quantity;
                printf("%d %s(s) sold successfully!\n", quantity, medArr[i].name);
            } else {
                printf("Not enough %s in stock!\n", medArr[i].name);
            }
            break;
        }
    }

    if (!found) {
        printf("Medicine not found in the stock!\n");
    }
}

int main() {
    struct medicine stock[50];
    int size = 0;
    int choice;

    // display the menu and get the user's choice until they choose to exit
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("********************************\n");
        printf("1. Display All Medicines\n");
        printf("2. Add Medicine to Stock\n");
        printf("3. Search for a Medicine\n");
        printf("4. Sell a Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayMedicines(stock, size);
                break;
            case 2:
                addMedicine(stock, &size);
                break;
            case 3:
                searchMedicine(stock, size);
                break;
            case 4:
                sellMedicine(stock, size);
                break;
            case 5:
                printf("Thank you for using our system!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}