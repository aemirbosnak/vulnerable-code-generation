//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ELEMENTS 118

struct Element {
    char name[20];
    char symbol[3];
    int atomic_number;
    char category[20];
};

void print_element(struct Element element) {
    printf("Name: %s\n", element.name);
    printf("Symbol: %s\n", element.symbol);
    printf("Atomic Number: %d\n", element.atomic_number);
    printf("Category: %s\n\n", element.category);
}

int main() {
    struct Element elements[MAX_ELEMENTS];
    int num_elements = 0;
    FILE *fp;
    char line[100];

    // Read elements from file
    fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open elements file.\n");
        exit(1);
    }

    while (fgets(line, 100, fp)!= NULL) {
        sscanf(line, "%s %s %d %s", elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].atomic_number, elements[num_elements].category);
        num_elements++;
    }

    fclose(fp);

    // Shuffle elements
    srand(time(NULL));
    for (int i = 0; i < num_elements; i++) {
        int j = rand() % num_elements;
        struct Element temp = elements[i];
        elements[i] = elements[j];
        elements[j] = temp;
    }

    // Quiz
    int score = 0;
    int num_questions = 10;
    int correct_answers = 0;

    printf("Periodic Table Quiz\n");
    printf("--------------------\n");

    for (int i = 0; i < num_questions; i++) {
        int index = rand() % num_elements;
        print_element(elements[index]);

        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, elements[index].name) == 0 || strcmp(answer, elements[index].symbol) == 0) {
            correct_answers++;
        }

        score += correct_answers;
    }

    printf("\nYour score: %d out of %d\n", score, num_questions);

    return 0;
}