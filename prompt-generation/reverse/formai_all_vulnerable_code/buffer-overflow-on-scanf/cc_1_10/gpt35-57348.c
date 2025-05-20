//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: scientific
#include <stdio.h>
#include <string.h>

int main()
{
    char username[20];
    char answer1[10], answer2[10], answer3[10];
    int score = 0;

    printf("Welcome to the Scientific Adventure Game!\n");
    printf("Please enter your name: ");
    scanf("%s", username);

    printf("\n%s, you are about to embark on a journey into the unknown. Are you ready to begin?\n", username);
    printf("Please answer 'yes' or 'no': ");
    scanf("%s", answer1);

    if (strcmp(answer1, "yes") == 0)
    {
        printf("\nGreat! The first question is:\n");
        printf("What is the name of the largest ocean on Earth?\n");
        printf("Please type your answer: ");
        scanf("%s", answer2);

        if (strcmp(answer2, "Pacific") == 0 || strcmp(answer2, "pacific") == 0)
        {
            printf("\nCorrect! You have earned 1 point.\n");
            score++;
        }
        else
        {
            printf("\nIncorrect. The correct answer is 'Pacific'.\n");
        }

        printf("\nThe second question is:\n");
        printf("Who first proposed the theory of relativity?\n");
        printf("Please type your answer: ");
        scanf("%s", answer3);

        if (strcmp(answer3, "Einstein") == 0 || strcmp(answer3, "einstein") == 0)
        {
            printf("\nCorrect! You have earned 1 point.\n");
            score++;
        }
        else
        {
            printf("\nIncorrect. The correct answer is 'Einstein'.\n");
        }

        printf("\nCongratulations, %s! You have completed the Scientific Adventure Game.\n", username);
        printf("Your final score is %d out of 2.\n", score);
    }
    else if (strcmp(answer1, "no") == 0)
    {
        printf("\nGoodbye, %s. Come back when you are ready to begin your adventure!\n", username);
    }
    else
    {
        printf("\nI'm sorry, I didn't understand your answer. Please start again and try to answer with 'yes' or 'no'.\n");
    }

    return 0;
}