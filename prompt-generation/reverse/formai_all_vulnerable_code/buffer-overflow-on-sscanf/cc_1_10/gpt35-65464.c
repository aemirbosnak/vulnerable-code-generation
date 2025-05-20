//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program is a quiz game based on the Periodic Table of Elements.
 * It will read in a list of element names and their corresponding symbols
 * from a text file, and then prompt the user with questions about the symbols
 * and names. The user will score points for each correct answer.
 */

#define MAX_ELEMENTS 118
#define BUFFER_SIZE 100

// Struct for holding an element's name and symbol
typedef struct
{
    char name[BUFFER_SIZE];
    char symbol[BUFFER_SIZE];
} Element;

int main()
{
    Element elements[MAX_ELEMENTS];
    int num_elements = 0;
    char buffer[BUFFER_SIZE];
    FILE *input_file;

    // Open the input file and read in the elements
    input_file = fopen("elements.txt", "r");

    if (input_file == NULL)
    {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    while (fgets(buffer, BUFFER_SIZE, input_file))
    {
        sscanf(buffer, "%s %s", elements[num_elements].name, elements[num_elements].symbol);
        num_elements++;
    }

    if (num_elements == 0)
    {
        printf("Error: No elements found in input file.\n");
        return 1;
    }

    fclose(input_file);

    // Define variables for the quiz
    int choice;
    int score = 0;
    char answer[BUFFER_SIZE];

    // Print the introduction and instructions
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be prompted with questions about the symbols and names of the elements.\n");
    printf("Enter the number of your choice and press Enter to submit your answer.\n\n");

    // Main quiz loop
    while (1)
    {
        // Choose a random element for the question
        int index = rand() % num_elements;
        int question_type = rand() % 2;

        if (question_type == 0)
        {
            // Ask for the symbol given the name
            printf("What is the symbol for %s?\n", elements[index].name);
            scanf("%s", answer);

            if (strcmp(answer, elements[index].symbol) == 0)
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
            }
        }
        else
        {
            // Ask for the name given the symbol
            printf("What is the name for %s?\n", elements[index].symbol);
            scanf("%s", answer);

            if (strcmp(answer, elements[index].name) == 0)
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Incorrect. The correct answer is %s.\n", elements[index].name);
            }
        }

        // Prompt for another question or quit
        printf("Your score is %d. Press 1 to continue, or 2 to quit.\n", score);
        scanf("%d", &choice);

        if (choice == 2)
        {
            break;
        }

        printf("\n");
    }

    printf("Thanks for playing! Your final score is %d.\n", score);

    return 0;
}