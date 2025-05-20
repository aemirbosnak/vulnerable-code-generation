//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char user_answer[4];
    int score = 0;
    int num_questions = 10;
    int correct_answers = 0;
    int i;
    int random_element;
    int random_question;
    int user_choice;
    int option1, option2, option3;

    srand(time(0));

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? (1-20) ");
    scanf("%d", &num_questions);

    printf("Question %d: What element has the symbol Fe and atomic number 26?\n", 1);
    printf("A) Iron\n");
    printf("B) Gold\n");
    printf("C) Silver\n");
    printf("D) Copper\n");
    scanf(" %c", &user_answer[0]);

    if (user_answer[0] == 'A' || user_answer[0] == 'a') {
        printf("Correct!\n");
        correct_answers++;
    } else {
        printf("Incorrect.\n");
    }

    printf("Question %d: What element has the symbol H and atomic number 1?\n", 2);
    printf("A) Hydrogen\n");
    printf("B) Helium\n");
    printf("C) Lithium\n");
    printf("D) Carbon\n");
    scanf(" %c", &user_answer[0]);

    if (user_answer[0] == 'A' || user_answer[0] == 'a') {
        printf("Correct!\n");
        correct_answers++;
    } else {
        printf("Incorrect.\n");
    }

    // Add more questions here

    printf("\nYou got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}