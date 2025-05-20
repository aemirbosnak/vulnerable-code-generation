//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int choice, quantity;
    float payment;
    char name[50];

    // Initializing the medicine inventory
    struct medicine inventory[5] = {
        {"Paracetamol", 100, 2.49},
        {"Ibuprofen", 75, 4.99},
        {"Aspirin", 50, 3.99},
        {"Loratadine", 60, 6.99},
        {"Amoxicillin", 40, 10.49}
    };

    printf("Welcome to the C Medical Store Management System\n\n");

    while(1) {
        printf("What would you like to do?\n1. View Inventory\n2. Purchase Medicine\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Display Inventory
                printf("Inventory:\nName\t\tQuantity\t\tPrice\n");
                for(int i=0; i<5; i++) {
                    printf("%s\t\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                printf("\n");
                break;

            case 2:
                // Purchase Medicine
                printf("Enter the name of the medicine you would like to purchase: ");
                scanf("%s", name);
                int found = 0;
                for(int i=0; i<5; i++) {
                    if(strcmp(inventory[i].name, name) == 0) {
                        printf("The price of %s is %.2f\n", name, inventory[i].price);
                        printf("How many would you like to purchase? ");
                        scanf("%d", &quantity);
                        if(quantity > inventory[i].quantity) {
                            printf("Sorry, we only have %d in stock.\n\n", inventory[i].quantity);
                        } else {
                            payment = quantity * inventory[i].price;
                            inventory[i].quantity -= quantity;
                            printf("You have purchased %d %s for %.2f\n\n", quantity, name, payment);
                        }
                        found = 1;
                        break;
                    }
                }
                if(!found) {
                    printf("%s is not available in the inventory.\n\n", name);
                }
                break;

            case 3:
                printf("Thank you for using C Medical Store Management System.");
                exit(0);

            default:
                printf("Invalid choice. Please enter a valid choice.\n\n");
        }
    }

    return 0;
}