//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_NUM 100

int main() {
    int num1, num2, result;
    char operation;
    int i, j, k;
    int total_operations = 10;
    int correct_answers = 0;
    int wrong_answers = 0;
    int choice;
    int difficulty = 1;
    int user_answer[MAX_NUM];
    int correct_answer[MAX_NUM];

    srand(time(NULL));

    printf("Welcome to the Math Surprise!\n");
    printf("You will be presented with %d math problems.\n", total_operations);
    printf("Choose a difficulty level (1-3): ");
    scanf("%d", &difficulty);

    for (i = 0; i < total_operations; i++) {
        num1 = rand() % MAX_NUM + 1;
        num2 = rand() % MAX_NUM + 1;

        switch (difficulty) {
            case 1:
                operation = '+';
                break;
            case 2:
                operation = '-';
                break;
            case 3:
                operation = '*';
                break;
            default:
                operation = '+';
                break;
        }

        correct_answer[i] = num1 + num2;

        printf("Problem %d: %d %c %d = ", i+1, num1, operation, num2);
        scanf("%d", &user_answer[i]);

        if (user_answer[i] == correct_answer[i]) {
            correct_answers++;
        } else {
            wrong_answers++;
        }
    }

    printf("\nYou got %d out of %d correct!\n", correct_answers, total_operations);

    return 0;
}