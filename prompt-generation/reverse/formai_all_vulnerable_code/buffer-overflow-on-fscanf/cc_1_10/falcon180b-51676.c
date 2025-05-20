//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

typedef struct {
    char name[10];
    char symbol[3];
    int atomic_number;
    double atomic_weight;
    int group;
    int period;
} element;

void load_elements(element *table, int size) {
    FILE *file = fopen("elements.txt", "r");
    if (!file) {
        printf("Error loading elements.\n");
        exit(1);
    }
    int count = 0;
    while (fscanf(file, "%s %s %d %lf %d %d\n", table[count].name, table[count].symbol, &table[count].atomic_number, &table[count].atomic_weight, &table[count].group, &table[count].period) == 6 && count < size) {
        count++;
    }
    fclose(file);
}

int main() {
    srand(time(NULL));
    int size = 118;
    element table[size];
    load_elements(table, size);
    int score = 0;
    int questions = 10;
    int correct_answers = 0;
    while (questions > 0) {
        int index = rand() % size;
        printf("Question %d: What is the symbol for element %s?\n", questions, table[index].name);
        char answer[3];
        scanf("%s", answer);
        if (strcmp(answer, table[index].symbol) == 0) {
            correct_answers++;
        }
        score += correct_answers;
        questions--;
    }
    printf("You scored %d out of %d.\n", score, questions);
    return 0;
}