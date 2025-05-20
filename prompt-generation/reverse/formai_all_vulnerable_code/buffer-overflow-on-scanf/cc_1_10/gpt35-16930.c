//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char question[200];
    int num;

    printf("Welcome to the Automated Fortune Teller!\nAsk me your question and I will provide a peaceful answer.\n");

    srand(time(NULL)); // Initialize random seed

    // Loop until user wants to stop
    while(1)
    {
        printf("\nEnter your question (or type 'quit' to exit):\n");
        scanf("%[^\n]", question); // Get the user's question
        getchar(); // Consume the newline character

        if(strcmp(question, "quit") == 0) // Check if user wants to quit
        {
            printf("\nThank you for consulting the Automated Fortune Teller. Goodbye!\n");
            break;
        }

        num = rand() % 5; // Generate a random number from 0 to 4

        // Switch statement to provide a peaceful answer
        switch(num)
        {
            case 0:
                printf("\nEverything will work out for you in the end. Trust in the universe.\n");
                break;

            case 1:
                printf("\nTake a deep breath and remember that you have the strength to overcome any challenge.\n");
                break;

            case 2:
                printf("\nFocus on your inner peace and all will fall into place.\n");
                break;

            case 3:
                printf("\nAllow yourself to let go of your worries and find harmony in the present moment.\n");
                break;

            case 4:
                printf("\nBelieve in yourself and know that you are capable of achieving your dreams.\n");
                break;

            default:
                printf("\nError: Something went wrong with the Automated Fortune Teller.\n");
                break;
        }
    }

    return 0;
}