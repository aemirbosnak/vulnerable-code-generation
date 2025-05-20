//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions;
    int num_correct;
    int score;
    int i, j;
    char answer[50];
    char correct_answer[50];
    struct element {
        char symbol[50];
        char name[100];
        int atomic_number;
        int group;
        int period;
        char category[50];
    };
    struct element elements[118];
    FILE *fp;
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (i = 0; i < 118; i++) {
        fscanf(fp, "%s %s %d %d %d %s", elements[i].symbol, elements[i].name, &elements[i].atomic_number, &elements[i].group, &elements[i].period, elements[i].category);
    }
    fclose(fp);
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("How many questions would you like to answer? ");
    scanf("%d", &num_questions);
    srand(time(NULL));
    for (i = 0; i < num_questions; i++) {
        j = rand() % 118;
        printf("Question %d:\n", i + 1);
        printf("What is the symbol for element %s?\n", elements[j].name);
        scanf("%s", answer);
        if (strcmp(answer, elements[j].symbol) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[j].symbol);
        }
    }
    score = num_correct * 100 / num_questions;
    printf("You scored %d%% on the quiz.\n", score);
    return 0;
}