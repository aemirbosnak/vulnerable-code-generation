//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <string.h>

int main() {
    // Declare and initialize variables
    char name[50];
    int tableNo, numOfItems;
    float total = 0;

    // Display welcome message and prompt for customer name and table number
    printf("Welcome to C Cafe!\n");
    printf("May I know your name? ");
    scanf("%s", name);
    printf("Hello %s, what is your table number? ", name);
    scanf("%d", &tableNo);

    // Display menu and prompt for number of items to be ordered
    printf("\nMenu:\n");
    printf("1. Coffee - $2.50\n");
    printf("2. Tea - $2.00\n");
    printf("3. Cakes - $3.50\n");
    printf("4. Sandwiches - $5.00\n");
    printf("5. Salad - $4.50\n");
    printf("How many items would you like to order? ");
    scanf("%d", &numOfItems);

    // Loop through each item and add up the total
    for (int i = 0; i < numOfItems; i++) {
        printf("\nEnter item number %d: ", i+1);
        int itemNo;
        scanf("%d", &itemNo);
        switch(itemNo) {
            case 1:
                total += 2.50;
                break;
            case 2:
                total += 2.00;
                break;
            case 3:
                total += 3.50;
                break;
            case 4:
                total += 5.00;
                break;
            case 5:
                total += 4.50;
                break;
            default:
                printf("Invalid item number.\n");
        }

        // Display running total after each item
        printf("Your current total is $%.2f.\n", total);
    }

    // Display final bill and thank customer for their visit
    printf("\nYour final bill is $%.2f.\n", total);
    printf("Thank you for visiting C Cafe and please come again!\n");

    return 0;
}