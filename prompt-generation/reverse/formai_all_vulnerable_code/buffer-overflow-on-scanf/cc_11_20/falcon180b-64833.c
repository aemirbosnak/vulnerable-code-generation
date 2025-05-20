//Falcon-180B DATASET v1.0 Category: Educational ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_problems, num_correct, i;
    float percent_correct;
    char answer[100];
    char correct_answer[100];
    srand(time(NULL));

    printf("Welcome to the Math Quiz!\n");
    printf("How many problems would you like to solve? ");
    scanf("%d", &num_problems);

    for (i = 0; i < num_problems; i++) {
        int num1 = rand() % 50 + 1;
        int num2 = rand() % 50 + 1;
        int operation = rand() % 4;

        switch (operation) {
            case 0:
                sprintf(correct_answer, "%d", num1 + num2);
                break;
            case 1:
                sprintf(correct_answer, "%d", num1 - num2);
                break;
            case 2:
                sprintf(correct_answer, "%d", num1 * num2);
                break;
            case 3:
                if (num2 == 0) {
                    printf("Cannot divide by zero! Try again.\n");
                    i--;
                    continue;
                }
                sprintf(correct_answer, "%d", num1 / num2);
                break;
        }

        printf("Problem %d: %d %s %d = ", i + 1, num1, (operation == 0? "+" : (operation == 1? "-" : (operation == 2? "*" : "/"))), num2);
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if (strcmp(answer, correct_answer) == 0) {
            num_correct++;
        }
    }

    percent_correct = (float)num_correct / num_problems * 100;
    printf("\nYou got %d out of %d problems correct (%.2f%%).\n", num_correct, num_problems, percent_correct);

    return 0;
}