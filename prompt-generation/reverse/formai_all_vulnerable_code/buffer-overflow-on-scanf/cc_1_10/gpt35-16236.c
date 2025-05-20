//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    //initialize variables
    int score = 0, question_count = 0;
    char answer[3], choice;

    //define array of questions and answers
    char questions[10][100] = {
        "What is the symbol for Carbon?",
        "How many protons does Nitrogen have?",
        "Which element is a halogen?",
        "What is the atomic number of Gold?",
        "What is the symbol for Lead?",
        "What is the atomic symbol for Oxygen?",
        "How many valence electrons does Silicon have?",
        "Which element is a noble gas?",
        "What is the atomic mass of Iron?",
        "What is the symbol for Sodium?"
    };
    char answers[10][3] = {
        "C",
        "7",
        "Fluorine",
        "79",
        "Pb",
        "O",
        "4",
        "Argon",
        "56",
        "Na"
    };

    //start quiz loop
    while (1)
    {
        //ask user if they want to start the quiz
        printf("\nDo you want to start the C Periodic Table Quiz? (Y/N) ");
        scanf("%c", &choice);
        fflush(stdin);

        //if user inputs N, exit program
        if (toupper(choice) == 'N')
        {
            printf("Thanks for playing!");
            return 0;
        }
        //if user inputs Y, start quiz
        else if (toupper(choice) == 'Y')
        {
            printf("\nWelcome to the C Periodic Table Quiz!\n");
            printf("*************************************\n");

            //loop through questions
            for (int i = 0; i < 10; i++)
            {
                question_count++;

                //print question
                printf("\nQuestion %d: %s ", i+1, questions[i]);
                printf("\nEnter your answer: ");
                scanf("%s", answer);

                //make answer uppercase for comparison
                for (int j = 0; j < 3; j++)
                {
                    answer[j] = toupper(answer[j]);
                }

                //compare answer to actual answer and adjust score
                if (strcmp(answer, answers[i]) == 0)
                {
                    score += 10;
                    printf("Correct!");
                }
                else
                {
                    printf("Incorrect. The answer is %s.", answers[i]);
                }
            }

            //print final score and thank user for playing
            printf("\n*************************************\n");
            printf("\nCongratulations! You have finished the quiz.\n");
            printf("Your final score is %d out of %d.", score, question_count * 10);
            printf("\nThanks for playing!");
            return 0;
        }
        //if user inputs anything other than Y or N, ask again
        else
        {
            printf("Invalid input. Please enter Y or N.");
        }
    }
    return 0;
}