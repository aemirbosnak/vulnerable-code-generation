//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    // Create a character to hold the student's name
    char student_name[20];

    // Get the student's name
    printf("Enter your name: ");
    scanf("%s", student_name);

    // Create a list of questions
    char questions[10][200] = {
        "In the year of our Lord 1492, what was the name of the King of England?",
        "What was the significance of the Black Death?",
        "Who was the first president of the United States?",
        "What is the capital of France?",
        "Who was the author of the Harry Potter series?",
        "What is the meaning of the word 'entrepreneur'?",
        "What is the most common color of hair in the world?",
        "What is the chemical symbol for gold?",
        "What is the sound of one hand clapping?",
        "What is the meaning of the word 'entrepreneur'"
    };

    // Display the questions
    printf("Here are your questions:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d. %s\n", i + 1, questions[i]);
    }

    // Get the student's answer for each question
    char answers[10][200];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answers[i]);
    }

    // Check if the student's answer is correct
    int score = 0;

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(answers[i], questions[i]) == 0)
        {
            score++;
        }
    }

    // Calculate the student's grade
    char grade = 'F';

    if (score >= 9)
    {
        grade = 'A';
    }
    else if (score >= 8)
    {
        grade = 'B';
    }
    else if (score >= 7)
    {
        grade = 'C';
    }
    else if (score >= 6)
    {
        grade = 'D';
    }

    // Display the student's grade
    printf("Your grade is: %c\n", grade);

    // Thank the student
    printf("Thank you for taking the exam, %s.\n", student_name);
}