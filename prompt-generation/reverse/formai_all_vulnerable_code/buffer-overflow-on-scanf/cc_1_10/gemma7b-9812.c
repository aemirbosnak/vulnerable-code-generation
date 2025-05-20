//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

void displayMenu()
{
    printf("\nWelcome to the C Cafe!\n");
    printf("Please select an option:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Smoothie\n");
    printf("5. Dessert\n");
    printf("6. Exit\n");
}

int main()
{
    int choice;
    float total = 0.0f;
    char name[20];

    printf("Enter your name: ");
    scanf("%s", name);

    displayMenu();

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            total += 5.0f;
            printf("You ordered a coffee.\n");
            break;
        case 2:
            total += 3.5f;
            printf("You ordered a tea.\n");
            break;
        case 3:
            total += 2.0f;
            printf("You ordered a juice.\n");
            break;
        case 4:
            total += 4.0f;
            printf("You ordered a smoothie.\n");
            break;
        case 5:
            total += 2.5f;
            printf("You ordered a dessert.\n");
            break;
        case 6:
            printf("Thank you for visiting the C Cafe, %s. See you next time!", name);
            exit(0);
            break;
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    printf("Your total bill is $%.2f. Please pay the cashier.\n", total);

    return 0;
}