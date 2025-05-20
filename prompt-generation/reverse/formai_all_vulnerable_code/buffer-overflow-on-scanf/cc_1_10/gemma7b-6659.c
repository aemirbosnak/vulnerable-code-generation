//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
    int score = 0;
    char command;

    printf("Welcome to the Enchanted Forest!\n");
    printf("You are on a quest to save the princess.\n");

    // Loop until the user enters a command
    while (1)
    {
        printf("Please enter a command: ");
        scanf("%c", &command);

        // Check if the user entered a valid command
        if (command == 'f' || command == 'b' || command == 'a' || command == 'r')
        {
            // Execute the command
            switch (command)
            {
                case 'f':
                    printf("You fought a dragon and won!\n");
                    score++;
                    break;
                case 'b':
                    printf("You went back to the beginning.\n");
                    score = 0;
                    break;
                case 'a':
                    printf("You attacked the princess and won!\n");
                    score++;
                    break;
                case 'r':
                    printf("You rode a unicorn and flew to the moon.\n");
                    score++;
                    break;
            }

            // Print the user's score
            printf("Your score is: %d\n", score);
        }
        else
        {
            printf("Invalid command. Please try again.\n");
        }
    }

    return 0;
}