//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

int main()
{
    // Create a student's answer sheet
    char answerSheet[MAX_QUESTIONS][20] = {0};

    // Load the question bank
    char questions[MAX_QUESTIONS][100] = {
        "What is the meaning of the word 'entrepreneur'?",
        "Explain the concept of polymorphism in OOP.",
        "Describe the different types of inheritance in C.",
        "Write a function to calculate the factorial of a number.",
        "What is the difference between static and dynamic memory allocation?",
        "What are the advantages of using pointers over arrays?",
        "Explain the concept of encapsulation in object-oriented programming.",
        "What are the different types of data abstraction?",
        "Define the term 'software engineering' and its importance.",
        "Describe the different phases of software development life cycle."
    };

    // Display the questions
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("%s\n", questions[i]);
    }

    // Get the student's answers
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%s", answerSheet[i]);
    }

    // Check the student's answers
    int score = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        if (strcmp(answerSheet[i], "correct") == 0)
        {
            score++;
        }
    }

    // Display the student's score
    printf("Your score: %d out of %d\n", score, MAX_QUESTIONS);

    return 0;
}