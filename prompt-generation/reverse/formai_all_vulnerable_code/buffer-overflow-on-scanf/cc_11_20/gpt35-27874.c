//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_of_medicines = 0;
    printf("Welcome to Happy Medical Store Management System! Let's get started.\n");

    printf("How many medicines do you want to add to the inventory?\n");
    scanf("%d", &num_of_medicines);

    char medicine_names[num_of_medicines][20];
    float medicine_prices[num_of_medicines];
    int medicine_quantities[num_of_medicines];
    int i;

    for(i = 0; i < num_of_medicines; i++) {
        printf("\nEnter details for medicine number %d:\n", i+1);

        printf("Enter the medicine name: ");
        scanf("%s", medicine_names[i]);

        printf("Enter the medicine price: ");
        scanf("%f", &medicine_prices[i]);

        printf("Enter the quantity of medicine: ");
        scanf("%d", &medicine_quantities[i]);
    }

    printf("\nThe inventory has been updated with the following medicines:\n");
    printf("Name\t\tPrice\t\tQuantity\n");
    for(i = 0; i < num_of_medicines; i++) {
        printf("%s\t\t%.2f\t\t%d\n", medicine_names[i], medicine_prices[i], medicine_quantities[i]);
    }

    float total_sales = 0;
    int choice = 0, quantity = 0;
    char continue_shopping = 'Y';

    while(continue_shopping == 'Y') {
        printf("\nWhat would you like to do?\n");
        printf("1. Buy medicine\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        if(choice == 1) {
            printf("\nEnter the name of the medicine you want to buy: ");
            char medicine_name[20];
            scanf("%s", medicine_name);

            int medicine_index = -1;
            for(i = 0; i < num_of_medicines; i++) {
                if(strcmp(medicine_names[i], medicine_name) == 0) {
                    medicine_index = i;
                    break;
                }
            }

            if(medicine_index == -1) {
                printf("Sorry, the medicine you are looking for is not available in our inventory.\n");
            }
            else {
                printf("\nEnter the quantity you want to buy: ");
                scanf("%d", &quantity);

                if(quantity > medicine_quantities[medicine_index]) {
                    printf("Sorry, we only have %d units of %s available.\n", medicine_quantities[medicine_index], medicine_names[medicine_index]);
                }
                else {
                    float total_price = quantity * medicine_prices[medicine_index];
                    printf("Thank you for purchasing %d unit(s) of %s for Rs. %.2f\n", quantity, medicine_names[medicine_index], total_price);
                    total_sales += total_price;
                    medicine_quantities[medicine_index] -= quantity;
                    printf("Would you like to continue shopping? (Y/N)\n");
                    scanf(" %c", &continue_shopping);
                }
            }
        }
        else if(choice == 2) {
            printf("Thank you for visiting Happy Medical Store!\n");
            continue_shopping = 'N';
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("Total sales for the day: Rs. %.2f\n", total_sales);
    printf("Inventory has been updated with the following quantities:\n");
    printf("Name\t\tQuantity\n");
    for(i = 0; i < num_of_medicines; i++) {
        printf("%s\t\t%d\n", medicine_names[i], medicine_quantities[i]);
    }

    return 0;
}