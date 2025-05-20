//Gemma-7B DATASET v1.0 Category: Banking Record System ; Style: Cryptic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    system("/bin/clear");
    printf("Enter your secret PIN: ");
    char pin[4] = "";
    scanf("%s", pin);

    if (strcmp(pin, "1234") == 0)
    {
        printf("Greetings, esteemed customer. Please choose an action:**\n");
        printf("1. View account balance\n");
        printf("2. Transfer funds\n");
        printf("3. Pay bills\n");
        printf("4. Quit\n");

        int choice = 0;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Your current account balance is $10,000.00\n");
                break;
            case 2:
                printf("Enter the recipient's account number: ");
                char account_number[10] = "";
                scanf("%s", account_number);

                printf("Enter the transfer amount: $");
                double amount = 0.0;
                scanf("%lf", &amount);

                if (amount > 1000)
                {
                    printf("Error: transfer amount too high.\n");
                }
                else
                {
                    printf("Transfer successful. Your new account balance is $10,000.00\n");
                }
                break;
            case 3:
                printf("Enter the bill type: ");
                char bill_type[20] = "";
                scanf("%s", bill_type);

                printf("Enter the bill amount: $");
                double bill_amount = 0.0;
                scanf("%lf", &bill_amount);

                if (bill_amount > 500)
                {
                    printf("Error: bill amount too high.\n");
                }
                else
                {
                    printf("Bill payment successful. Your new account balance is $10,000.00\n");
                }
                break;
            case 4:
                printf("Thank you for using the C Banking Record System. Goodbye.\n");
                break;
            default:
                printf("Invalid selection.\n");
                break;
        }
    }
    else
    {
        printf("Incorrect PIN. Please try again.\n");
    }

    return 0;
}