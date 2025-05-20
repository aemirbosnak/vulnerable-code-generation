//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for questions
struct question 
{
    char question[100];
    char optionA[50];
    char optionB[50];
    char optionC[50];
    char optionD[50];
    char correct_option;
};

// Function to display questions and take input from user
void display_questions(struct question questions[], int num_questions)
{
    int score = 0;
    char answer;
    int i;
    for (i = 0; i < num_questions; i++) 
    {
        printf("\n\n%s\n", questions[i].question);
        printf("A. %s\n", questions[i].optionA);
        printf("B. %s\n", questions[i].optionB);
        printf("C. %s\n", questions[i].optionC);
        printf("D. %s\n", questions[i].optionD);
        printf("Choose an option (A/B/C/D): ");
        scanf(" %c", &answer);
        if (answer == questions[i].correct_option) 
        {
            printf("Correct Answer!\n");
            score++;
        }
        else 
        {
            printf("Wrong Answer!\n");
        }
    }
    printf("\nFinal Score: %d/%d\n", score, num_questions);
}

// Function to add questions to the question pool
int add_question(struct question questions[], int num_questions)
{
    char input[100];
    printf("\nEnter the question: ");
    scanf(" %[^\n]s", input);
    strcpy(questions[num_questions].question, input);
    printf("Enter option A: ");
    scanf(" %[^\n]s", input);
    strcpy(questions[num_questions].optionA, input);
    printf("Enter option B: ");
    scanf(" %[^\n]s", input);
    strcpy(questions[num_questions].optionB, input);
    printf("Enter option C: ");
    scanf(" %[^\n]s", input);
    strcpy(questions[num_questions].optionC, input);
    printf("Enter option D: ");
    scanf(" %[^\n]s", input);
    strcpy(questions[num_questions].optionD, input);
    printf("Enter the correct option (A/B/C/D): ");
    scanf(" %c", &questions[num_questions].correct_option);
    num_questions++;
    return num_questions;
}

// Main function
int main()
{
    int num_questions = 0; // Initialize number of questions in question pool
    struct question questions[100]; // Define question pool with maximum 100 questions
    int choice;
    do 
    {
        printf("\n\nC Online Examination System\n");
        printf("1. Add question\n");
        printf("2. Display questions\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                num_questions = add_question(questions, num_questions);
                break;
            case 2:
                display_questions(questions, num_questions);
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 3);
    return 0;
}