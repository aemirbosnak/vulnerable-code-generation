//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int correct_answers = 0;
    int incorrect_answers = 0;
    int total_questions = 10;
    char periodic_table[10][3] = {
        {"H"},
        {"He"},
        {"Li"},
        {"Be"},
        {"B"},
        {"C"},
        {"N"},
        {"O"},
        {"F"},
        {"Ne"}
    };
    char answers[10][3];

    printf("*** Welcome to the Periodic Table Quiz! ***\n");
    printf("You will be given %d questions to answer.\n", total_questions);

    for (int i = 0; i < total_questions; i++) {
        int question_num = i + 1;
        int random_num = rand() % 10;
        char* element = periodic_table[random_num];

        printf("\nQuestion %d: What is the chemical symbol for %s?\n", question_num, element);

        scanf("%s", answers[i]);

        if (strcmp(answers[i], element) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element);
            incorrect_answers++;
        }
    }

    printf("\n*** Final Score ***\n");
    printf("Correct Answers: %d\n", correct_answers);
    printf("Incorrect Answers: %d\n", incorrect_answers);

    return 0;
}