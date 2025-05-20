//FormAI DATASET v1.0 Category: Online Examination System ; Style: immersive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int correct_count = 0, incorrect_count = 0;
    float score;
    char name[20];
    time_t start_time, end_time;
    int total_time;
    int num1, num2, ans, user_ans;
    int i;

    printf("Welcome to the C Online Examination System!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hello %s! The exam is about to begin. You will have 5 minutes to answer 10 questions. Press enter to start the exam.\n", name);
    getchar(); // to consume the newline character after entering the name
    getchar(); // to wait for the user to press enter

    start_time = time(NULL);

    for(i = 1; i <= 10; i++)
    {
        srand(time(NULL)); // to generate a new random number every time

        num1 = rand() % 100;
        num2 = rand() % 100;

        printf("%d. What is %d + %d? ", i, num1, num2);
        scanf("%d", &user_ans);
        ans = num1 + num2;

        if(user_ans == ans)
        {
            printf("Correct!\n");
            correct_count++;
        }
        else
        {
            printf("Incorrect! The correct answer is %d.\n", ans);
            incorrect_count++;
        }
    }

    end_time = time(NULL);
    total_time = difftime(end_time, start_time);

    score = (float)correct_count / 10.0 * 100.0;

    printf("Thank you for taking the exam %s!\n", name);
    printf("You got %d out of 10 questions correct!\n", correct_count);
    printf("You got %d out of 10 questions incorrect.\n", incorrect_count);
    printf("Your score is %.2f\n", score);
    printf("You took %d seconds to complete the exam.\n", total_time);

    return 0;
}