//FormAI DATASET v1.0 Category: Online Examination System ; Style: shape shifting
/* Shape-Shifting Online Examination System */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); // Seed for random number generation

    int num_questions = 0;
    char difficulty = ' ';
    int score = 0;

    printf("Welcome to the Shape-Shifting Online Examination System!\n");

    // Ask for number of questions
    printf("\nEnter number of questions you want to attempt (between 5-20): ");
    scanf("%d", &num_questions);

    if(num_questions < 5 || num_questions > 20)
    {
        printf("\nInvalid number of questions. Please enter a number between 5-20.\n");
        return 0; // Exit program
    }

    // Ask for difficulty level
    printf("Enter difficulty level (Easy/E/M/H/Hard): ");
    scanf(" %c", &difficulty);

    // Convert difficulty to uppercase
    if(difficulty >= 'a' && difficulty <= 'z')
    {
        difficulty = difficulty - 32;
    }

    // Generate random questions based on difficulty and display them
    switch(difficulty)
    {
        case 'E':
            printf("\nEasy Questions:\n\n");
            for(int i=0; i<num_questions; i++)
            {
                int answer = 0;
                int num1 = rand() % 10 + 1;
                int num2 = rand() % 10 + 1;

                printf("%d) What is %d + %d? ", i+1, num1, num2);
                scanf("%d", &answer);

                if(answer == (num1 + num2))
                {
                    score++;
                }
            }
            break;

        case 'M':
            printf("\nMedium Questions:\n\n");
            for(int i=0; i<num_questions; i++)
            {
                int answer = 0;
                int num1 = rand() % 50 + 1;
                int num2 = rand() % 50 + 1;

                printf("%d) What is %d - %d? ", i+1, num1, num2);
                scanf("%d", &answer);

                if(answer == (num1 - num2))
                {
                    score++;
                }
            }
            break;

        case 'H':
            printf("\nHard Questions:\n\n");
            for(int i=0; i<num_questions; i++)
            {
                int answer = 0;
                int num1 = rand() % 100 + 1;
                int num2 = rand() % 100 + 1;

                printf("%d) What is %d * %d? ", i+1, num1, num2);
                scanf("%d", &answer);

                if(answer == (num1 * num2))
                {
                    score++;
                }
            }
            break;

        case 'HARD':
            printf("\nVery Hard Questions:\n\n");
            for(int i=0; i<num_questions; i++)
            {
                int answer = 0;
                int num1 = rand() % 1000 + 1;
                int num2 = rand() % 1000 + 1;

                printf("%d) What is %d / %d? ", i+1, num1, num2);
                scanf("%d", &answer);

                if(answer == (num1 / num2))
                {
                    score++;
                }
            }
            break;

        default:
            printf("\nInvalid difficulty level. Please enter either Easy, Medium, Hard or Very Hard.\n");
            return 0; // Exit program
    }

    // Display score based on number of correct answers
    printf("\nYou scored %d out of %d.\n", score, num_questions);

    return 0;
}