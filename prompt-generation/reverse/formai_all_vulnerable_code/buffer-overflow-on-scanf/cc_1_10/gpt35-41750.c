//FormAI DATASET v1.0 Category: Online Examination System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 10
#define PASSING_GRADE 70

int main() {
    int score = 0;
    char student_name[50];

    printf("Enter your name: ");
    scanf("%s", student_name);

    printf("Welcome, %s! You are about to embark on a post-apocalyptic journey through a virtual world.\n", student_name);
    printf("In this world, you will be tested on your knowledge of C programming.\n");
    printf("Answer each question to the best of your ability and survive! Let's begin:\n");

    srand(time(NULL));

    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Generate random question
        int num1 = rand() % 20 + 1;
        int num2 = rand() % 20 + 1;
        int answer = num1 + num2;

        printf("\nQuestion %d: What is %d + %d?\n", i+1, num1, num2);

        // Get answer from user
        int user_answer;
        scanf("%d", &user_answer);

        // Check answer
        if (user_answer == answer) {
            printf("Correct! You survived this round.\n");
            score += 10;
        } else {
            printf("Incorrect. You've been attacked by a zombie.\n");
            score -= 5;
        }
    }

    if (score >= PASSING_GRADE) {
        printf("\nCongratulations, %s! You passed the exam with a score of %d.\n", student_name, score);
        printf("You have successfully navigated through the post-apocalyptic virtual world of C programming.\n");
    } else {
        printf("\nSorry, %s. You failed the exam with a score of %d.\n", student_name, score);
        printf("You were unable to survive the harsh conditions of the post-apocalyptic virtual world of C programming.\n");
    }

    return 0;
}