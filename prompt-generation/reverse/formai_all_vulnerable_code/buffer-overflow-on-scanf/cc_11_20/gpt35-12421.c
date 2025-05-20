//FormAI DATASET v1.0 Category: Online Examination System ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    printf("\t\t\tC Online Examination System\n");
    printf("******************************************************************************\n");

    int score = 0;

    char ques1[100] = "What is the keyword used for declaring a variable? ";
    char ans1[50] = "int";
    char user_ans1[50];

    char ques2[100] = "What is a pointer variable? ";
    char ans2[50] = "variable that stores address";
    char user_ans2[50];

    char ques3[100] = "What is the operator used for accessing a structure member? ";
    char ans3[50] = ".";
    char user_ans3[50];

    char ques4[100] = "What is the value of sizeof(int)? ";
    char ans4[50] = "4";
    char user_ans4[50];

    char ques5[100] = "What is the keyword used for defining a function? ";
    char ans5[50] = "void";
    char user_ans5[50];

    srand(time(NULL));

    int random_num = rand() % 5 + 1;

    if(random_num == 1)
    {
        printf("%s\n", ques1);
        scanf("%s", user_ans1);

        if(strcmp(user_ans1, ans1) == 0)
        {
            printf("Correct!\n");
            score++;
        }

        else
            printf("Wrong answer!\n");
    }

    if(random_num == 2)
    {
        printf("%s\n", ques2);
        scanf("%s", user_ans2);

        if(strcmp(user_ans2, ans2) == 0)
        {
            printf("Correct!\n");
            score++;
        }

        else
            printf("Wrong answer!\n");
    }

    if(random_num == 3)
    {
        printf("%s\n", ques3);
        scanf("%s", user_ans3);

        if(strcmp(user_ans3, ans3) == 0)
        {
            printf("Correct!\n");
            score++;
        }

        else
            printf("Wrong answer!\n");
    }

    if(random_num == 4)
    {
        printf("%s\n", ques4);
        scanf("%s", user_ans4);

        if(strcmp(user_ans4, ans4) == 0)
        {
            printf("Correct!\n");
            score++;
        }

        else
            printf("Wrong answer!\n");
    }

    if(random_num == 5)
    {
        printf("%s\n", ques5);
        scanf("%s", user_ans5);

        if(strcmp(user_ans5, ans5) == 0)
        {
            printf("Correct!\n");
            score++;
        }

        else
            printf("Wrong answer!\n");
    }

    printf("Your score is: %d\n", score);

    return 0;
}