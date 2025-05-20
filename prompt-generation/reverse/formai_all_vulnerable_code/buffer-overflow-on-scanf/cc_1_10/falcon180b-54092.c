//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score = 0;
    int num_questions = 10;
    int correct_answers = 0;
    int question_number = 1;
    int user_answer;
    char answer_letter;
    char correct_answer_letter;

    srand(time(NULL));

    printf("Welcome to the Post-Apocalyptic Periodic Table Quiz!\n");
    printf("In this world, knowledge is power, and power is survival.\n");
    printf("Answer %d out of %d questions correctly to prove your worth.\n", num_questions, num_questions);
    printf("Good luck!\n");

    for (int i = 0; i < num_questions; i++) {
        int random_element = rand() % 118 + 1;
        printf("Question %d: What is the symbol for element %d?\n", question_number, random_element);
        correct_answer_letter = (char) ('A' + random_element - 1);

        while (1) {
            scanf("%c", &answer_letter);

            if (answer_letter == correct_answer_letter || answer_letter == 'a' + random_element - 1) {
                correct_answers++;
                printf("Correct!\n");
                break;
            } else if (answer_letter == 'q') {
                printf("You have chosen to quit the quiz.\n");
                return 0;
            } else {
                printf("Incorrect. The correct answer is %c.\n", correct_answer_letter);
            }
        }

        question_number++;
    }

    if (correct_answers == num_questions) {
        printf("Congratulations! You have proven your worth in this post-apocalyptic world.\n");
    } else {
        printf("Sorry, you did not answer enough questions correctly.\n");
    }

    return 0;
}