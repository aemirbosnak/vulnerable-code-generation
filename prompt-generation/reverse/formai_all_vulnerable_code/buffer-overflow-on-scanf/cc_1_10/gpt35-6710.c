//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include<stdio.h>

void main() {

    int choice, quantity, total = 0; //declaring required variables.
    char c, item[10]; //declaring char array to store item names.

    printf("Welcome to our Cafe!\n");

    do { 
        printf("Please select an item:\n1.Coffee\n2.Tea\n3.Cake\n");
        scanf("%d", &choice); //Asking user for item selection.

        switch(choice) {
            case 1:
                printf("Enter the quantity for Coffee:");
                scanf("%d", &quantity); //Asking user for quantity of Coffee.
                total += (quantity * 50); //Adding the price of Coffee to the total.
                strcpy(item, "Coffee"); //Storing the item name in the char array.
                break;
            case 2:
                printf("Enter the quantity for Tea:");
                scanf("%d", &quantity); //Asking user for quantity of Tea.
                total += (quantity * 30); //Adding the price of Tea to the total.
                strcpy(item, "Tea"); //Storing the item name in the char array.
                break;
            case 3:
                printf("Enter the quantity for Cake:");
                scanf("%d", &quantity); //Asking user for quantity of Cake.
                total += (quantity * 150); //Adding the price of Cake to the total.
                strcpy(item, "Cake"); //Storing the item name in the char array.
                break;
            default:
                printf("Invalid choice, please try again!\n");
                break;
        }

        printf("Do you want to add more items? (y/n):");  
        scanf(" %c", &c); //Asking user if they want to add more items.

    } while(c == 'y' || c == 'Y');
    
    //Printing the final bill.
    printf("\n\n");
    printf("**********Cafe Bill**********\n");
    printf("\nItem\t\tQuantity\tPrice\n");
    printf("%s\t\t%d\t\tRs%d\n", item, quantity, total);
    printf("\nTotal Amount: Rs%d/-\n", total);
    printf("\nThank you for visiting our Cafe! :)\n");   
}