//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions;
    int score = 0;
    int correct_answers = 0;
    int incorrect_answers = 0;
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
    int o;
    int p;
    int q;
    int r;
    int s;
    int t;
    int u;
    int v;
    int w;
    int x;
    int y;
    int z;
    char user_answer[10];
    char correct_answer[10];
    int random_number;
    srand(time(NULL));
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions do you want to answer? (1-20) ");
    scanf("%d", &num_questions);
    printf("You have selected %d questions.\n", num_questions);
    for (i = 0; i < num_questions; i++) {
        printf("Question %d:\n", i+1);
        random_number = rand() % 118;
        if (random_number < 10) {
            correct_answer[0] = '0' + random_number;
            correct_answer[1] = '\0';
        } else {
            correct_answer[0] = 'A' + random_number - 10;
            correct_answer[1] = '\0';
        }
        printf("What is the symbol for element %s?\n", correct_answer);
        scanf("%s", user_answer);
        if (strcmp(user_answer, correct_answer) == 0) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", correct_answer);
            incorrect_answers++;
        }
    }
    printf("You got %d out of %d correct.\n", correct_answers, num_questions);
    return 0;
}