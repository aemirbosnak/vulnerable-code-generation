//Falcon2-11B DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NUM_OF_QUESTIONS 10
#define MAX_NUM_OF_RESPONSES 100

int main()
{
    // Initialize variables
    int num_of_questions = 0;
    int num_of_responses = 0;
    int choice;
    char response[MAX_NUM_OF_RESPONSES];
    char question[MAX_NUM_OF_QUESTIONS];

    // Print welcome message
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Ask me anything and I will answer with a random response!\n");

    // Loop until user wants to exit
    while (1)
    {
        // Get user input
        printf("Question: ");
        scanf("%s", question);
        if (strcmp(question, "exit") == 0)
        {
            break;
        }

        // Generate random response
        srand(time(NULL));
        choice = rand() % 100;
        if (choice <= 50)
        {
            strcpy(response, "Yes");
        }
        else
        {
            strcpy(response, "No");
        }

        // Print response
        printf("Response: %s\n", response);

        // Increment counters
        num_of_questions++;
        num_of_responses++;
    }

    // Print summary
    printf("You asked %d questions and got %d responses.\n", num_of_questions, num_of_responses);

    return 0;
}