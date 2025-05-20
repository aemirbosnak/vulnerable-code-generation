//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements;
    int num_questions;
    int score = 0;
    int i, j, k;
    char element[5];
    char correct_ans[5];
    char user_ans[5];
    int correct_ans_index;
    int user_ans_index;
    int valid_ans = 0;

    srand(time(NULL));
    num_elements = rand() % 118 + 1;
    num_questions = rand() % 10 + 1;

    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("You will be asked %d questions about the elements in the periodic table.\n", num_questions);
    printf("Each question will have 4 possible answers, but only one of them is correct.\n");
    printf("Your score will be based on how many questions you answer correctly.\n\n");

    for (i = 0; i < num_elements; i++) {
        printf("Element %d: ", i+1);
        scanf("%s", element);
        correct_ans_index = rand() % 4;
        strcpy(correct_ans, "A");
        for (j = 0; j < 4; j++) {
            if (j == correct_ans_index) {
                strcpy(element, "A");
            } else {
                strcpy(element, "B");
            }
            printf("%s. %s\n", element, element);
        }
        valid_ans = 0;
        while (!valid_ans) {
            scanf("%s", user_ans);
            for (k = 0; k < 4; k++) {
                if (strcmp(user_ans, correct_ans) == 0) {
                    valid_ans = 1;
                    score++;
                }
            }
            if (!valid_ans) {
                printf("Incorrect. The correct answer is %s.\n", correct_ans);
            }
        }
    }

    printf("\nThank you for playing the C Periodic Table Quiz!\n");
    printf("Your final score is %d out of %d.\n", score, num_questions);

    return 0;
}