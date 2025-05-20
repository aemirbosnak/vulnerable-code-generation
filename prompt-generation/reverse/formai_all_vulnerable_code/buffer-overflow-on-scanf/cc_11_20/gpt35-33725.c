//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char name[20]; // variable to store user's name
    int age; // variable to store user's age
    int lucky_num; // variable to store user's lucky number
    char q1_ans[20]; // variable to store user's answer to question 1
    char q2_ans[20]; // variable to store user's answer to question 2
    char q3_ans[20]; // variable to store user's answer to question 3

    printf("Hello! I am the Automated Fortune Teller. Let's get started.\n");

    printf("What is your name?\n");
    scanf("%s", &name);

    printf("Nice to meet you, %s. How old are you?\n", name);
    scanf("%d", &age);

    printf("What is your lucky number?\n");
    scanf("%d", &lucky_num);

    printf("Great! Now answer the following three questions with either 'Yes' or 'No'.\n");

    printf("Question 1: Are you feeling lucky today?\n");
    scanf("%s", &q1_ans);

    printf("Question 2: Do you believe that everything happens for a reason?\n");
    scanf("%s", &q2_ans);

    printf("Question 3: Have you been kind to others lately?\n");
    scanf("%s", &q3_ans);

    // generate random number between 1 and 10
    srand(time(NULL));
    int fortune_num = rand() % 10 + 1;

    // calculate fortune based on user input and random number generated
    if (age <= 30 && lucky_num >= 7 && (q1_ans == "Yes" || q2_ans == "Yes" || q3_ans == "Yes") && fortune_num >= 5) {
        printf("Congratulations, %s! You will have great success in the near future.\n", name);
    } else if (age > 30 && lucky_num < 5 && (q1_ans == "No" || q2_ans == "No" || q3_ans == "No") && fortune_num < 5) {
        printf("Sorry, %s. You will face some challenges in the next few weeks.\n", name);
    } else {
        printf("Your fortune is unclear right now, %s. Try again later!\n", name);
    }

    return 0;
}