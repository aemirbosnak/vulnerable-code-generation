//Gemma-7B DATASET v1.0 Category: Email Client ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG_SIZE 1024

void print_menu(void)
{
    printf("\n");
    printf("   __           __\n");
    printf(" |\\_/)__       /|_\n");
    printf(" | \__) \__| | \__)\n");
    printf(" |__) |__) |__)\n");
    printf("   \__) |__) \__)\n");
    printf("\n");
    printf("Enter '1' to view inbox, '2' to compose, '3' to search, '4' to quit: ");
}

int main(void)
{
    char msg_buffer[MAX_MSG_SIZE];
    char sender[MAX_MSG_SIZE];
    char subject[MAX_MSG_SIZE];
    int msg_num = 0;

    print_menu();

    scanf(" %d ", &msg_num);

    switch (msg_num)
    {
        case 1:
            printf("Your inbox:\n");
            // Display inbox messages
            break;
        case 2:
            printf("Compose a new message:\n");
            // Get message details and write message
            break;
        case 3:
            printf("Search for a message:\n");
            // Search for messages based on criteria
            break;
        case 4:
            printf("Thank you for using the email client. Goodbye.\n");
            exit(0);
        default:
            printf("Invalid input. Please try again.\n");
            break;
    }

    return 0;
}