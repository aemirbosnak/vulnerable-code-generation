//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char name[30];
    int atomic_number;
    char symbol[3];
    int group_number;
} Element;

Element elements[118];

void load_data() {
    FILE *file = fopen("periodic_table.txt", "r");
    char line[100];
    int i = 0;

    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%d%s%d", elements[i].name, &elements[i].atomic_number, elements[i].symbol, &elements[i].group_number);
        i++;
    }

    fclose(file);
}

void print_table() {
    int i, j;
    printf("\n%-20s %-10s %-10s %-10s\n", "Element Name", "Symbol", "Group Number", "Atomic Number");
    printf("--------------------------------------------------------\n");

    for (i = 0; i < 118; i++) {
        printf("%-20s %-10s %-10d %-10d\n", elements[i].name, elements[i].symbol, elements[i].group_number, elements[i].atomic_number);
    }
}

void quiz(int num_questions) {
    int i, j, answer, correct_answer;
    srand(time(NULL));

    for (i = 0; i < num_questions; i++) {
        j = rand() % 118;
        correct_answer = elements[j].group_number;
        printf("Question %d: Which group number does %s belong to?\n", i + 1, elements[j].name);
        scanf("%d", &answer);

        if (answer == correct_answer) {
            printf("Correct! Nice job.\n");
        } else {
            printf("Sorry, that's incorrect. The correct answer is %d.\n", correct_answer);
        }
    }

    printf("Quiz completed. Have a peaceful day!\n");
}

int main() {
    int num_questions;

    load_data();
    print_table();
    printf("\nHow many questions would you like to answer in the quiz?\n");
    scanf("%d", &num_questions);

    quiz(num_questions);

    return 0;
}