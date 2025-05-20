//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_ELEMENTS 118
#define MAX_LINE_LENGTH 80

typedef struct {
    char symbol[3];
    char name;
    int atomic_number;
    int atomic_weight;
    char category[10];
} element;

element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error loading elements.txt\n");
        exit(1);
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL && count < MAX_ELEMENTS) {
        int i = 0;
        while (line[i]!= '\t' && i < MAX_LINE_LENGTH) {
            elements[count].symbol[i] = toupper(line[i]);
            i++;
        }
        elements[count].symbol[i] = '\0';

        i++;
        while (line[i]!= '\t' && i < MAX_LINE_LENGTH) {
            elements[count].name = line[i];
            i++;
        }

        elements[count].atomic_number = atoi(line + i);
        while (line[i]!= '\t' && i < MAX_LINE_LENGTH) {
            i++;
        }

        elements[count].atomic_weight = atof(line + i);
        while (line[i]!= '\t' && i < MAX_LINE_LENGTH) {
            i++;
        }

        strncpy(elements[count].category, line + i, sizeof(elements[count].category));
        elements[count].category[sizeof(elements[count].category) - 1] = '\0';

        count++;
    }

    fclose(file);
}

void print_element(int index) {
    printf("Symbol: %s\n", elements[index].symbol);
    printf("Name: %c\n", elements[index].name);
    printf("Atomic number: %d\n", elements[index].atomic_number);
    printf("Atomic weight: %f\n", elements[index].atomic_weight);
    printf("Category: %s\n\n", elements[index].category);
}

int main() {
    srand(time(NULL));

    load_elements();

    int score = 0;
    int total_questions = 10;

    for (int i = 0; i < total_questions; i++) {
        int index = rand() % MAX_ELEMENTS;
        printf("Question %d:\n", i + 1);
        print_element(index);

        char answer[MAX_LINE_LENGTH];
        printf("Enter the symbol of the element: ");
        scanf("%s", answer);

        if (strcmp(answer, elements[index].symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].symbol);
        }
    }

    printf("Your score is %d out of %d.\n", score, total_questions);

    return 0;
}