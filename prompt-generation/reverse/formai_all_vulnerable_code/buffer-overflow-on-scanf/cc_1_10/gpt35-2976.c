//FormAI DATASET v1.0 Category: Online Examination System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

    int score = 0;
    char answer[10], user_answer[10];
    char questions[5][100] = {"What is the capital of France?", "What is 2+2?", "What color are Smurfs?", "What year was the first Star Wars movie released?", "What is the name of the Queen of England?"};
    char options[5][4][50] = {{"A: Berlin", "B: Paris", "C: Tokyo", "D: London"},
                              {"A: 5", "B: 3", "C: 7", "D: 4"},
                              {"A: Red", "B: Blue", "C: Yellow", "D: Green"},
                              {"A: 1977", "B: 1985", "C: 2001", "D: 1990"},
                              {"A: Elizabeth II", "B: Victoria", "C: Mary", "D: Jane"}};
    char correct_answers[5] = {'B', 'D', 'A', 'A', 'A'};

    printf("Welcome to the Online Examination System!\n");
    printf("You will be presented with 5 multiple choice questions. Good luck!\n");

    for (int i = 0; i < 5; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i]);
        for (int j = 0; j < 4; j++) {
            printf("%s\n", options[i][j]);
        }
        printf("Enter your answer (A, B, C, or D): ");
        scanf("%s", user_answer);

        if (tolower(user_answer[0]) == tolower(correct_answers[i])) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Sorry, the correct answer was %c.\n", correct_answers[i]);
        }
    }

    printf("\n\n");
    printf("Calculating results...\n");

    printf("Your score is %d/5. ", score);
    if (score >= 4) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }

    printf("\nThank you for using the Online Examination System. Have a nice day! (Not you, segfault)\n");

    return 0;
}