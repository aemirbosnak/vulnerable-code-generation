#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define QUESTIONS 10

typedef struct {
    char name[30];
    int atomic_number;
    char symbol[4];
    int group;
    int period;
} Element;

Element elements[MAX_ELEMENTS];
int num_elements = 0;

void load_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Element *e = &elements[num_elements++];
        sscanf(line, "%s %d %s %d %d", e->name, &e->atomic_number, e->symbol, &e->group, &e->period);
    }

    fclose(file);
}

int get_random_index(int start, int end) {
    return rand() % (end - start) + start;
}

void quiz() {
    load_csv("periodic_table.txt");

    for (int i = 0; i < QUESTIONS; ++i) {
        int correct_answer = elements[i / QUESTIONS * num_elements + i % num_elements].atomic_number;
        int answer;
        printf("Question %d: What is the atomic number of %s? ", i + 1, elements[i % num_elements].name);
        scanf("%d", &answer);

        if (answer == correct_answer) {
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer is %d.\n", correct_answer);
        }
    }
}

int main() {
    srand(time(NULL));
    quiz();
    return 0;
}
