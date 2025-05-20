//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int score = 0;
    int num_questions = 20;
    int correct_answers = 0;
    int user_answer;
    char name[20];

    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\n%s, are you ready to test your knowledge on the periodic table?\n", name);
    printf("There will be %d questions.\n\n", num_questions);

    for (int i = 0; i < num_questions; i++) {
        int element_num = rand() % 118;
        char element_name[20];
        sprintf(element_name, "Element %d", element_num + 1);

        printf("\nQuestion %d:\n", i + 1);
        printf("What is the symbol for element %s?\n", element_name);

        char symbols[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
        int correct_index = rand() % 7;
        char correct_symbol = symbols[correct_index];

        for (int j = 0; j < 7; j++) {
            if (j == correct_index) {
                printf("%c) %c\n", j + 1, correct_symbol);
            } else {
                printf("%c) %c\n", j + 1, symbols[j]);
            }
        }

        scanf("%d", &user_answer);

        if (user_answer == correct_index + 1) {
            printf("\nCorrect!\n");
            correct_answers++;
        } else {
            printf("\nIncorrect. The correct answer is %c.\n", correct_symbol);
        }
    }

    printf("\n\n%s, you got %d out of %d questions correct.\n", name, correct_answers, num_questions);

    return 0;
}