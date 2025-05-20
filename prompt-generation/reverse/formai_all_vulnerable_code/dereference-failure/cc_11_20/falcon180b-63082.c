//Falcon-180B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions;
    int correct_answers = 0;
    int total_questions = 0;
    int question_index = 0;
    int user_answer;
    int correct_answer;
    int score = 0;
    char choice;
    struct tm *t;
    time_t now;

    srand(time(NULL));
    now = time(NULL);
    t = localtime(&now);
    printf("Welcome to the quiz program!\n");
    printf("Today's date is: %d/%d/%d\n", t->tm_mday, t->tm_mon+1, t->tm_year+1900);
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);
    printf("Great, let's start!\n");

    while (question_index < num_questions) {
        total_questions++;
        question_index++;
        correct_answer = rand() % 4;
        switch(correct_answer) {
            case 0:
                printf("Question %d: What is the capital of France?\n", total_questions);
                printf("A. London\nB. Paris\nC. Berlin\nD. Madrid\n");
                scanf("%d", &user_answer);
                if (user_answer == 2) {
                    correct_answers++;
                }
                break;
            case 1:
                printf("Question %d: What is the largest ocean in the world?\n", total_questions);
                printf("A. Atlantic Ocean\nB. Pacific Ocean\nC. Indian Ocean\nD. Arctic Ocean\n");
                scanf("%d", &user_answer);
                if (user_answer == 1) {
                    correct_answers++;
                }
                break;
            case 2:
                printf("Question %d: What is the tallest animal in the world?\n", total_questions);
                printf("A. Blue Whale\nB. Giraffe\nC. Elephant\nD. Camel\n");
                scanf("%d", &user_answer);
                if (user_answer == 0) {
                    correct_answers++;
                }
                break;
            case 3:
                printf("Question %d: What is the smallest country in the world?\n", total_questions);
                printf("A. Vatican City\nB. Monaco\nC. San Marino\nD. Nauru\n");
                scanf("%d", &user_answer);
                if (user_answer == 0) {
                    correct_answers++;
                }
                break;
            default:
                printf("Invalid question!\n");
        }
    }

    score = (float) correct_answers / num_questions * 100;
    printf("\nYou answered %d out of %d questions correctly.\n", correct_answers, num_questions);
    printf("Your score is %.2f%%\n", score);

    printf("Do you want to try again? (Y/N) ");
    scanf(" %c", &choice);
    if (choice == 'Y' || choice == 'y') {
        main();
    } else {
        printf("Thanks for playing!\n");
    }

    return 0;
}