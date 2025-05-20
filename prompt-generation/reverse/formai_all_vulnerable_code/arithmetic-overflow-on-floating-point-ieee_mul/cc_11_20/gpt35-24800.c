//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the Structure for the Medical Store
struct medstore {
    char medname[40];
    int quantity;
    float price;
    char expirydate[15];
};

// Main Function
int main() {

    // Declaring Variables
    int choice, i = 0, j, k, totalmeds = 0;
    char temp[40];
    float totalprice = 0;
    struct medstore stock[100];

    // Main loop for the program
    do {

        // Printing the Main Menu
        printf("\n\nMedical Store Management System \n");
        printf("1. Add Medicine to Stock\n");
        printf("2. Search Medicine by Name\n");
        printf("3. Show Stock\n");
        printf("4. Delete Medicine from Stock\n");
        printf("5. Exit the Program\n\n");

        // Asking for User Choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Switch Case for User Choice
        switch (choice) {

            // If User chooses to Add Medicine to Stock
            case 1:
                printf("\nAdding Medicine to Stock\n");

                // Asking for Medicine Details
                printf("Enter Name of the Medicine: ");
                scanf("%s", stock[i].medname);

                printf("Enter Quantity of the Medicine: ");
                scanf("%d", &stock[i].quantity);

                printf("Enter Price of the Medicine: ");
                scanf("%f", &stock[i].price);

                printf("Enter Expiry Date of the Medicine (dd/mm/yyyy): ");
                scanf("%s", stock[i].expirydate);

                // Updating the Total Number of Medicines in Stock
                totalmeds += stock[i].quantity;

                // Updating the Total Price of Medicines in Stock
                totalprice += (stock[i].price * stock[i].quantity);

                // Incrementing the Medicines Index
                i++;

                break;

            // If User chooses to Search Medicine by Name
            case 2:
                printf("\nSearching Medicine by Name\n");

                // Asking for Medicine Name to Search
                printf("Enter Name of the Medicine to Search: ");
                scanf("%s", temp);

                // Looping through the Stock to find the Medicine
                for (j = 0; j < i; j++) {
                    if (strcmp(temp, stock[j].medname) == 0) {
                        printf("\nMedicine found in Stock!\n");

                        // Displaying Medicine Details
                        printf("Name: %s\n", stock[j].medname);
                        printf("Quantity: %d\n", stock[j].quantity);
                        printf("Price: %.2f\n", stock[j].price);
                        printf("Expiry Date: %s\n", stock[j].expirydate);
                    }
                }

                break;

            // If User chooses to Show Stock
            case 3:
                printf("\nShowing Stock\n");

                // Looping through the Stock to Display Medicines
                for (j = 0; j < i; j++) {
                    printf("\nMedicine %d:\n", j+1);

                    // Displaying Medicine Details
                    printf("Name: %s\n", stock[j].medname);
                    printf("Quantity: %d\n", stock[j].quantity);
                    printf("Price: %.2f\n", stock[j].price);
                    printf("Expiry Date: %s\n", stock[j].expirydate);
                }

                break;

            // If User chooses to Delete Medicine from Stock
            case 4:
                printf("\nDeleting Medicine from Stock\n");

                // Asking for Medicine Name to Delete
                printf("Enter Name of the Medicine to Delete: ");
                scanf("%s", temp);

                // Looping through the Stock to find the Medicine to Delete
                for (j = 0; j < i; j++) {
                    if (strcmp(temp, stock[j].medname) == 0) {
                        printf("\nMedicine found in Stock and Deleted!\n");

                        // Updating the Total Number of Medicines in Stock
                        totalmeds -= stock[j].quantity;

                        // Updating the Total Price of Medicines in Stock
                        totalprice -= (stock[j].price * stock[j].quantity);

                        // Removing the Medicine from Stock
                        for (k = j; k < i-1; k++) {
                            strcpy(stock[k].medname, stock[k+1].medname);
                            stock[k].quantity = stock[k+1].quantity;
                            stock[k].price = stock[k+1].price;
                            strcpy(stock[k].expirydate, stock[k+1].expirydate);
                        }
                        i--;
                        break;
                    }
                }

                break;

            // If User chooses to Exit the Program
            case 5:
                printf("\nExiting the Program\n");
                break;

            // If User enters an Invalid Choice
            default:
                printf("\nInvalid Choice. Please Try Again!\n");
                break;
        }

    } while (choice != 5);

    // Displaying the Total Number of Medicines in Stock
    printf("\nTotal Medicines in Stock: %d\n", totalmeds);

    // Displaying the Total Price of Medicines in Stock
    printf("Total Price of Medicines in Stock: %.2f\n", totalprice);

    return 0;
}