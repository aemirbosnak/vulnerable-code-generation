//FormAI DATASET v1.0 Category: Online Examination System ; Style: calm
#include<stdio.h>

int main()
{
    int ques1, ques2, ques3, ques4, ques5;
    int marks = 0;

    printf("Welcome to the Online Examination System\n");

    printf("\nQuestion 1: What is the capital of France?\n");
    printf("1. London\t2. Paris\n");
    printf("3. Rome\t\t4. Berlin\n");
    printf("Enter your answer: ");
    scanf("%d", &ques1);

    if (ques1 == 2)
    {
        printf("Your answer is correct.\n");
        marks++;
    }
    else
        printf("Your answer is wrong.\n");

    printf("\nQuestion 2: Who invented the telephone?\n");
    printf("1. Alexander Graham Bell\t2. Thomas Edison\n");
    printf("3. Nikola Tesla\t\t4. Benjamin Franklin\n");
    printf("Enter your answer: ");
    scanf("%d", &ques2);

    if (ques2 == 1)
    {
        printf("Your answer is correct.\n");
        marks++;
    }
    else
        printf("Your answer is wrong.\n");

    printf("\nQuestion 3: Which is the largest continent in the world?\n");
    printf("1. Asia\t\t2. Europe\n");
    printf("3. Africa\t4. South America\n");
    printf("Enter your answer: ");
    scanf("%d", &ques3);

    if (ques3 == 1)
    {
        printf("Your answer is correct.\n");
        marks++;
    }
    else
        printf("Your answer is wrong.\n");

    printf("\nQuestion 4: When was the first computer invented?\n");
    printf("1. 1880\t\t2. 1945\n");
    printf("3. 1980\t\t4. 1955\n");
    printf("Enter your answer: ");
    scanf("%d", &ques4);

    if (ques4 == 2)
    {
        printf("Your answer is correct.\n");
        marks++;
    }
    else
        printf("Your answer is wrong.\n");

    printf("\nQuestion 5: What is the smallest country in the world?\n");
    printf("1. Monaco\t2. Vatican City\n");
    printf("3. Liechtenstein\t4. San Marino\n");
    printf("Enter your answer: ");
    scanf("%d", &ques5);

    if (ques5 == 2)
    {
        printf("Your answer is correct.\n");
        marks++;
    }
    else
        printf("Your answer is wrong.\n");

    printf("\nYou have answered %d questions correctly.\n", marks);
    printf("Your score is %d out of 5.\n", marks);

    return 0;
}