//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

// This program generates a quiz to test user's knowledge about the periodic table.

// function prototypes
void handle_answers(char user_entry, char answers[], int correct[]);
void display_results(int correct[], int total_questions);

int main()
{
    char answers[10] = {'b', 'a', 'c', 'c', 'd', 'b', 'a', 'b', 'c', 'a'};
    char user_entry;
    int correct[10] = {0};
    int total_questions = 10;
    int i = 0, j = 0;
    char element[10][3] = {"H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne"};

    // Seed for random number generation
    srand(time(NULL));

    // Introduction to the quiz
    printf("\nWelcome to the Periodic Table Quiz!\n");
    printf("You will be presented with 10 questions, one at a time.\n");
    printf("Enter the letter corresponding to your answer choice.\n");
    printf("Good luck!\n\n");

    // loop through all the 10 questions
    for(i=0; i<total_questions; i++)
    {
        // pick a random element to display the question
        j = rand() % 10;

        printf("What is the atomic number of %s?\n", element[j]);
        printf("a) %d   b) %d   c) %d    d) %d\n", j+1, j+2, j+3, j+4);

        // read user's answer
        scanf(" %c", &user_entry);

        // handle the user's answer
        handle_answers(user_entry, answers, correct);

        printf("\n");
    }

    // display quiz results
    display_results(correct, total_questions);

    // Thank the user
    printf("\nThanks for taking the Periodic Table Quiz!\n");

    return 0;
}

// function to handle user's answer
void handle_answers(char user_entry, char answers[], int correct[])
{
    int i = 0;

    // check if the user's answer is correct
    if(user_entry == answers[i])
    {
        printf("Correct! Congrats!\n");
        correct[i] = 1; // mark this question as correct
    }
    else
    {
        printf("Sorry, that is incorrect.\n");
    }

    return;
}

// function to display quiz results
void display_results(int correct[], int total_questions)
{
    int i = 0, score = 0;

    printf("\nResults:\n");

    // check how many questions the user got correct
    for(i=0; i<total_questions; i++)
    {
        if(correct[i] == 1)
        {
            score++;
        }
    }

    printf("You answered %d out of %d questions correctly!\n", score, total_questions);

    return;
}