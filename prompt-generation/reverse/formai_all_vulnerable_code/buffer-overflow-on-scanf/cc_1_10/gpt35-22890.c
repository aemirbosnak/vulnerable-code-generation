//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Structure for storing medicine details
struct medicine {
    char name[MAX_SIZE];
    int quantity;
    float price;
};

// Declaring global variables
struct medicine stock[MAX_SIZE];
int count = 0;

// Function for adding medicine to stock
void addMedicine() {
    printf("Enter details of medicine:\n");

    // Input medicine name
    printf("Enter medicine name: ");
    scanf("%s", stock[count].name);

    // Input medicine quantity
    printf("Enter medicine quantity: ");
    scanf("%d", &stock[count].quantity);

    // Input medicine price
    printf("Enter medicine price: ");
    scanf("%f", &stock[count].price);

    count++;
}

// Function for searching medicine by name
void searchMedicine() {
    char searchName[MAX_SIZE];

    printf("Enter medicine name to search: ");
    scanf("%s", searchName);

    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(searchName, stock[i].name) == 0) {
            printf("%s \t %d \t %f\n", stock[i].name, stock[i].quantity, stock[i].price);
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("Medicine not found!\n");
    }
}

// Function for selling medicine
void sellMedicine() {
    char sellName[MAX_SIZE];
    int sellQuantity;

    printf("Enter medicine name to sell: ");
    scanf("%s", sellName);

    int found = 0;
    for(int i=0; i<count; i++) {
        if(strcmp(sellName, stock[i].name) == 0) {
            printf("Medicine found!\n");

            printf("Enter quantity to sell: ");
            scanf("%d", &sellQuantity);

            if(sellQuantity <= stock[i].quantity) {
                printf("Total price: %f\n", sellQuantity * stock[i].price);
                stock[i].quantity -= sellQuantity;
                found = 1;
                break;
            } else {
                printf("Insufficient stock!\n");
                found = 1;
                break;
            }
        }
    }

    if(!found) {
        printf("Medicine not found!\n");
    }
}

// Function for displaying all medicine in stock
void displayStock() {
    printf("Name \t Quantity \t Price\n");

    for(int i=0; i<count; i++) {
        printf("%s \t %d \t %f\n", stock[i].name, stock[i].quantity, stock[i].price);
    }
}

// Main function
int main() {
    int choice;

    do {
        printf("\n------------- Medical Store Management System -------------\n");
        printf("\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Display Stock\n");
        printf("5. Exit\n");
        printf("\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addMedicine();
                break;

            case 2:
                searchMedicine();
                break;

            case 3:
                sellMedicine();
                break;

            case 4:
                displayStock();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while(choice != 5);

    return 0;
}