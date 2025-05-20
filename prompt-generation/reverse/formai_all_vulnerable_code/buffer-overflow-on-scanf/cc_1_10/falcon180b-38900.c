//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_questions;
    int score = 0;
    int i;

    printf("Welcome to the Funky Online Exam System!\n");
    printf("Please enter the number of questions in the exam: ");
    scanf("%d", &num_questions);

    for(i=1; i<=num_questions; i++) {
        int correct_answer;
        int user_answer;
        char question[100];
        char choice1[50];
        char choice2[50];
        char choice3[50];
        char choice4[50];
        int j;

        printf("Question %d:\n", i);
        printf("---------------------\n");
        printf("Question: ");
        scanf("%s", question);

        correct_answer = rand() % 4 + 1; // generate random correct answer

        printf("Choice 1: ");
        scanf("%s", choice1);
        printf("Choice 2: ");
        scanf("%s", choice2);
        printf("Choice 3: ");
        scanf("%s", choice3);
        printf("Choice 4: ");
        scanf("%s", choice4);

        printf("\n");
        for(j=1; j<=4; j++) {
            printf("%d. %s\n", j, (j==correct_answer)? "*" : " ");
            printf("  %s\n", (j==1)? choice1 : (j==2)? choice2 : (j==3)? choice3 : choice4);
        }

        printf("\nEnter your answer (1-4): ");
        scanf("%d", &user_answer);

        if(user_answer == correct_answer) {
            printf("\nCorrect! You get 1 point.\n");
            score++;
        } else {
            printf("\nSorry, wrong answer. The correct answer is %d.\n", correct_answer);
        }
    }

    printf("\n\nExam is over. Your score is: %d out of %d.\n", score, num_questions);

    return 0;
}