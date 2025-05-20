//FormAI DATASET v1.0 Category: Online Examination System ; Style: curious
#include<stdio.h>

int main() {
    // Welcome message
    printf("Welcome to the C Online Examination System!\n\n");

    // Questions
    printf("Q1. What is the output of the following code?\n\n");
    int i = 5;
    printf("%d", i++);

    // Answer verification
    int ans1;
    scanf("%d", &ans1);
    if(ans1 == 5) {
        printf("Correct Answer!\n\n");
    } else {
        printf("Sorry, Incorrect Answer!\n\n");
    }

    printf("Q2. What is the output of the following code?\n\n");
    int j = 10;
    printf("%d", ++j);

    // Answer verification
    int ans2;
    scanf("%d", &ans2);
    if(ans2 == 11) {
        printf("Correct Answer!\n\n");
    } else {
        printf("Sorry, Incorrect Answer!\n\n");
    }

    printf("Q3. What is the output of the following code?\n\n");
    int k = 5;
    printf("%d", k++ + ++k);

    // Answer verification
    int ans3;
    scanf("%d", &ans3);
    if(ans3 == 12) {
        printf("Correct Answer!\n\n");
    } else {
        printf("Sorry, Incorrect Answer!\n\n");
    }

    // Final score calculation
    int score = 0;
    if(ans1 == 5) {
        score++;
    }
    if(ans2 == 11) {
        score++;
    }
    if(ans3 == 12) {
        score++;
    }

    // Display final score
    printf("Your Final Score is %d out of 3.\n\n", score);

    // Thank you message
    printf("Thank you for using the C Online Examination System!\n\n");

    return 0;
}