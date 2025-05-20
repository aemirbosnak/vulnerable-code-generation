//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_ELEMENT_NAME_LENGTH 20
#define MAX_ELEMENT_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char symbol[MAX_ELEMENT_SYMBOL_LENGTH];
} element_t;

element_t elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s", elements[count].name, elements[count].symbol)!= EOF) {
        count++;
    }

    fclose(file);
}

void shuffle_elements() {
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        int j = rand() % MAX_ELEMENTS;
        element_t temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }
}

int main() {
    srand(time(NULL));
    load_elements();
    shuffle_elements();

    int score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d: What is the symbol for %s?\n", i+1, elements[index].name);
        char answer[MAX_ELEMENT_SYMBOL_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            score++;
        }
    }

    printf("Your score is %d out of %d.\n", score, total_questions);

    return 0;
}