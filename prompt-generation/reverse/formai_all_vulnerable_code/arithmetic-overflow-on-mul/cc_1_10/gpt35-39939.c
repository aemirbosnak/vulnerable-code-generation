//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Declare global variables
int coffeeCost = 30;
int teaCost = 20;
int cakeCost = 40;
int totalCost = 0;
int numOfCoffees = 0;
int numOfTeas = 0;
int numOfCakes = 0;
char orderSelection = ' ';
char orderConfirmation = ' ';

int main() {
    // Welcome message
    printf("Welcome to the Shape-Shifting Cafe Billing System!\n\n");
    printf("We have the following items on our menu:\n");
    printf("Coffee - $%d\n", coffeeCost);
    printf("Tea - $%d\n", teaCost);
    printf("Cake - $%d\n\n", cakeCost);

    // loop to take orders
    do {
        // take order selection from user
        printf("Please select an item from the menu ('C' for coffee, 'T' for tea, 'K' for cake): ");
        scanf(" %c", &orderSelection);

        // process user's order selection
        switch (orderSelection) {
            case 'C':
                printf("\nYou have ordered coffee. How many cups would you like? ");
                scanf("%d", &numOfCoffees);
                totalCost += (numOfCoffees * coffeeCost);
                break;
            case 'T':
                printf("\nYou have ordered tea. How many cups would you like? ");
                scanf("%d", &numOfTeas);
                totalCost += (numOfTeas * teaCost);
                break;
            case 'K':
                printf("\nYou have ordered cake. How many slices would you like? ");
                scanf("%d", &numOfCakes);
                totalCost += (numOfCakes * cakeCost);
                break;
            default:
                printf("\nInvalid selection.\n");
        }

        // check if user wants to order anything else
        printf("\nWould you like to order anything else? ('Y' for yes, 'N' for no): ");
        scanf(" %c", &orderConfirmation);

    } while (orderConfirmation == 'Y' || orderConfirmation == 'y');

    // display total cost to user
    printf("\nYour total cost is: $%d. Thank you for your business!\n\n", totalCost);

    return 0;
}