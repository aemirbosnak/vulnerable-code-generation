//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
// Romeo and Juliet's Medical Store Management System
// Scene 1: The Introduction

#include <stdio.h>

int main() {
    printf("Enter thy name, brave user:\n");
    char name[20];
    scanf("%s", name);
    printf("Welcome, %s, to Romeo and Juliet's Medical Store Management System!\n", name);
    printf("What would you like to do today?\n");
    printf("1. Add a new medicine\n");
    printf("2. Update medicine details\n");
    printf("3. Remove a medicine\n");
    printf("4. View medicine inventory\n");
    printf("5. Exit the system\n");

    // Scene 2: The User Chooses an Option
    int choice;
    printf("Enter thy choice, dear %s:\n", name);
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the name of the new medicine:\n");
            char medName[20];
            scanf("%s", medName);
            printf("Enter the quantity of %s in stock:\n", medName);
            int quantity;
            scanf("%d", &quantity);
            printf("Enter the price of %s per unit:\n", medName);
            float price;
            scanf("%f", &price);
            printf("New medicine added successfully!\n");
            // Add code to add medicine to inventory
            break;
        case 2:
            printf("Enter the name of the medicine you want to update:\n");
            char updateName[20];
            scanf("%s", updateName);
            printf("What would you like to update about %s?\n", updateName);
            printf("1. Quantity in stock\n");
            printf("2. Price per unit\n");
            int updateChoice;
            scanf("%d", &updateChoice);
            switch (updateChoice) {
                case 1:
                    printf("Enter the new quantity of %s in stock:\n", updateName);
                    int newQuantity;
                    scanf("%d", &newQuantity);
                    printf("Quantity of %s updated successfully!\n", updateName);
                    // Add code to update quantity
                    break;
                case 2:
                    printf("Enter the new price per unit of %s:\n", updateName);
                    float newPrice;
                    scanf("%f", &newPrice);
                    printf("Price of %s updated successfully!\n", updateName);
                    // Add code to update price
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
            break;
        case 3:
            printf("Enter the name of the medicine you want to remove:\n");
            char removeName[20];
            scanf("%s", removeName);
            printf("%s has been removed from inventory!\n", removeName);
            // Add code to remove medicine from inventory
            break;
        case 4:
            // Add code to display inventory
            printf("Inventory:\n");
            printf("Medicine Name \t Quantity \t Price per unit\n");
            printf("----------------------------------------------\n");
            printf("Medicine 1 \t 10 \t\t 1.5\n");
            printf("Medicine 2 \t 23 \t\t 2.8\n");
            printf("Medicine 3 \t 5 \t\t 3.6\n");
            break;
        case 5:
            printf("Farewell, %s, until we meet again!\n", name);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }
    return 0;
}