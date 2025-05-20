//FormAI DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int marks = 0;
    int questions = 5;
    char answer;
    char correct_answers[5] = {'A', 'B', 'C', 'D', 'A'};
    char student_answers[5];

    printf("Welcome to the Mind-Bending C Online Examination System!\n\n");

    printf("Please answer the following %d questions:\n", questions);
    printf("Q1. What is the color of the sky?\n");
    printf("A. Blue\nB. Green\nC. Red\nD. Yellow\n");
    scanf(" %c", &answer);
    student_answers[0] = answer;

    printf("Q2. What is the largest organ in the human body?\n");
    printf("A. Brain\nB. Heart\nC. Lungs\nD. Skin\n");
    scanf(" %c", &answer);
    student_answers[1] = answer;

    printf("Q3. What is the capital city of Japan?\n");
    printf("A. Tokyo\nB. Beijing\nC. Seoul\nD. Hong Kong\n");
    scanf(" %c", &answer);
    student_answers[2] = answer;

    printf("Q4. What is the smallest planet in the solar system?\n");
    printf("A. Jupiter\nB. Saturn\nC. Mercury\nD. Earth\n");
    scanf(" %c", &answer);
    student_answers[3] = answer;

    printf("Q5. What is the only mammal that can fly?\n");
    printf("A. Bat\nB. Kangaroo\nC. Elephant\nD. Lion\n");
    scanf(" %c", &answer);
    student_answers[4] = answer;

    for(int i=0; i<questions; i++)
    {
        if(student_answers[i] == correct_answers[i])
        {
            marks++;
        }
    }

    printf("\nYour marks: %d out of %d\n\n", marks, questions);

    printf("Thank you for taking the Mind-Bending C Online Examination System!\n");

    return 0;
}