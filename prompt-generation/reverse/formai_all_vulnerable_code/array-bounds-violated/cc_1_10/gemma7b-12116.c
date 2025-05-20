//Gemma-7B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_tickets = 100;
    int sold_tickets = 0;
    char seat_chart[10][10] = {'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S',
                              'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S',
                              'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S', 'S',
                              'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O', 'O'};

    // Loop to sell tickets
    while (sold_tickets < num_tickets)
    {
        // Get the customer's name and seat preference
        char customer_name[20];
        int seat_preference;

        printf("Enter your name: ");
        scanf("%s", customer_name);

        printf("Enter your seat preference (1-10): ");
        scanf("%d", &seat_preference);

        // Check if the seat is available
        if (seat_chart[seat_preference - 1][seat_preference - 1] == 'S')
        {
            // Sell the ticket
            seat_chart[seat_preference - 1][seat_preference - 1] = 'O';
            sold_tickets++;

            // Confirm the ticket sale
            printf("Your ticket has been sold. Seat number: %d, Seat letter: %c\n", seat_preference, seat_preference - 1);
        }
        else
        {
            // Inform the customer that the seat is not available
            printf("Sorry, that seat is not available.\n");
        }
    }

    // Print the seat chart
    printf("Seat Chart:\n");
    for (int r = 0; r < 10; r++)
    {
        for (int c = 0; c < 10; c++)
        {
            printf("%c ", seat_chart[r][c]);
        }
        printf("\n");
    }

    // Thank the customer for using the ticket sales system
    printf("Thank you for using the ticket sales system. Have a nice day.\n");

    return 0;
}