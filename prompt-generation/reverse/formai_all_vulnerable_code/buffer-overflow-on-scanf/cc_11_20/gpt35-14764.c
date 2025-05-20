//FormAI DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("Welcome to the C Online Examination System!\n");
    int score = 0;
    char name[20];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!\n", name);
    printf("Let's begin the exam!\n");

    // Generate 10 random questions
    int i;
    srand(time(NULL));
    for (i = 0; i < 10; i++)
    {
        int a = rand() % 100;
        int b = rand() % 100;
        int op = rand() % 3;

        if (op == 0)
        {
            printf("%d + %d = ?\n", a, b);
            int ans;
            scanf("%d", &ans);
            if (ans == (a + b))
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Incorrect. The answer is %d\n", (a + b));
            }
        }
        else if (op == 1)
        {
            printf("%d - %d = ?\n", a, b);
            int ans;
            scanf("%d", &ans);
            if (ans == (a - b))
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Incorrect. The answer is %d\n", (a - b));
            }
        }
        else
        {
            printf("%d * %d = ?\n", a, b);
            int ans;
            scanf("%d", &ans);
            if (ans == (a * b))
            {
                printf("Correct!\n");
                score++;
            }
            else
            {
                printf("Incorrect. The answer is %d\n", (a * b));
            }
        }
    }

    // Display final score
    printf("Congratulations, %s! You have completed the exam.\n", name);
    printf("Your final score is %d out of 10.\n", score);

    // Grade System    
    char grade;

    if (score <=10 && score >=8)
    {
        grade = 'A';
        printf("Excellent work! Your grade is %c", grade);
    }
    else if (score <=7 && score >=5)
    {
        grade = 'B';
        printf("Great job! Your grade is %c", grade);
    }
    else if (score <= 4 && score >=1)
    {
        grade = 'C';
        printf("Not bad! Your grade is %c", grade);
    }
    else
    {
        grade = 'F';
        printf("Sorry! You test again. Your grade is %c", grade);
    }

    return 0;
}