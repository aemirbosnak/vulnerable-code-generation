//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX_ELEMENTS 118

typedef struct {
    char name[3];
    char symbol;
    int atomic_number;
    int atomic_weight;
} element;

element periodic_table[MAX_ELEMENTS];

void load_periodic_table() {
    FILE *file = fopen("periodic_table.txt", "r");
    int i = 0;
    while (fscanf(file, "%s%c%d%d", periodic_table[i].name, &periodic_table[i].symbol, &periodic_table[i].atomic_number, &periodic_table[i].atomic_weight)!= EOF) {
        i++;
    }
    fclose(file);
}

void quiz() {
    int score = 0;
    char user_answer[4];
    int user_answer_length;
    int correct_answers = 0;
    int total_questions = 10;

    printf("Welcome to the Periodic Table Quiz!\n");

    for (int i = 0; i < total_questions; i++) {
        int random_index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for element %s?\n", i+1, periodic_table[random_index].name);
        scanf(" %[^\n]", user_answer);
        user_answer_length = strlen(user_answer);
        if (user_answer_length == 1 && toupper(user_answer[0]) == periodic_table[random_index].symbol) {
            printf("Correct!\n");
            correct_answers++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", periodic_table[random_index].symbol);
        }
    }

    printf("You got %d out of %d correct!\n", correct_answers, total_questions);
}

int main() {
    load_periodic_table();
    quiz();
    return 0;
}