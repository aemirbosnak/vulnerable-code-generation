//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[30];
    int atomic_number;
    char symbol;
} Element;

void print_element(Element e) {
    printf("%-20s %2d %c\n", e.name, e.atomic_number, e.symbol);
}

int main() {
    int i, j, num_elements, num_questions, score;
    Element elements[118];
    FILE *file;

    file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d", &num_elements);
    for (i = 0; i < num_elements; i++) {
        fscanf(file, "%s %d %c", elements[i].name, &elements[i].atomic_number, &elements[i].symbol);
    }

    fclose(file);

    printf("\nWelcome to the C Periodic Table Quiz!\n");
    printf("-------------------------------------\n");

    srand(time(NULL));

    scanf("%d", &num_questions);
    for (i = 0; i < num_questions; i++) {
        int a, b;
        Element e1, e2;

        do {
            a = rand() % num_elements;
            e1 = elements[a];
        } while (elements[rand() % num_elements].atomic_number < e1.atomic_number);

        do {
            b = rand() % num_elements;
        } while (b == a);

        e2 = elements[b];

        printf("\nQuestion %d:\n", i + 1);
        printf("%s has atomic number:\n", elements[rand() % num_elements].name);
        printf("%s) %d\n", e1.name, e1.atomic_number);
        printf("%s) %d\n", e2.name, e2.atomic_number);
        scanf("%d", &j);

        if (j == e1.atomic_number) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer was %d.\n", e1.atomic_number);
        }
    }

    printf("\nQuiz completed. Your score is %d out of %d.\n", score, num_questions);

    return 0;
}