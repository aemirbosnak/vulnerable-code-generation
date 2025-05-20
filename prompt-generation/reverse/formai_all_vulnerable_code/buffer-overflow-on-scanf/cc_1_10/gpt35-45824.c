//FormAI DATASET v1.0 Category: Digital Auction System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_menu()
{
    printf("Welcome to the Digital Auction system!\n");
    printf("----------------------------------------\n");
    printf("1. Register for auction\n");
    printf("2. Bid for item\n");
    printf("3. View current highest bid\n");
    printf("4. Exit system\n");
}

int main()
{
    int choice, bid, highest_bid = 0, registered = 0;
    char name[50];

    srand(time(NULL));

    while (1)
    {
        display_menu();
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (registered)
                {
                    printf("You are already registered!\n");
                }
                else
                {
                    printf("Please enter your name: ");
                    scanf("%s", name);
                    printf("Thank you for registering, %s!\n", name);
                    registered = 1;
                }
                break;
            case 2:
                if (!registered)
                {
                    printf("You must register first!\n");
                }
                else
                {
                    printf("Please enter your bid: ");
                    scanf("%d", &bid);

                    if (bid > highest_bid)
                    {
                        printf("Congratulations, you have the highest bid!\n");
                        highest_bid = bid;
                    }
                    else
                    {
                        printf("Sorry, your bid is not high enough.\n");
                    }
                }
                break;
            case 3:
                if (!registered)
                {
                    printf("You must register first!\n");
                }
                else
                {
                    printf("The current highest bid is %d.\n", highest_bid);
                }
                break;
            case 4:
                printf("Thank you for using the Digital Auction system!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}