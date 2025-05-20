//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ELEMENTS 118
#define NUM_QUESTIONS 10

typedef struct {
    int number;
    char symbol[3];
    char name[20];
    float atomic_mass;
} Element;

int random_int(int min, int max);
Element* create_element_array();
void print_array(Element *arr);
void shuffle_array(Element *arr);
int quiz_user(Element *arr, int num_questions);

int main() {
    srand(time(NULL));

    printf("Welcome to the Periodic Table Quiz!\n\n");

    Element *elements = create_element_array();
    shuffle_array(elements);
    int score = quiz_user(elements, NUM_QUESTIONS);

    printf("\n\nQuiz Complete! Your score: %d/%d\n\n", score, NUM_QUESTIONS);

    free(elements);

    return 0;
}

int random_int(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

Element* create_element_array() {
    FILE *fp = fopen("periodic-table.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open CSV file.\n");
        exit(1);
    }

    Element *elements = malloc(sizeof(Element) * NUM_ELEMENTS);
    if (elements == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    char line[100];
    int i = 0;

    while (fgets(line, 100, fp) != NULL && i < NUM_ELEMENTS) {
        sscanf(line, "%d, %[^,], %[^,], %f", &elements[i].number, elements[i].symbol, elements[i].name, &elements[i].atomic_mass);
        i++;
    }

    fclose(fp);

    return elements;
}

void print_array(Element *arr) {
    for (int i = 0; i < NUM_ELEMENTS; i++) {
        printf("%d. %s (%s) - %f\n", arr[i].number, arr[i].symbol, arr[i].name, arr[i].atomic_mass);
    }
}

void shuffle_array(Element *arr) {
    for (int i = NUM_ELEMENTS - 1; i > 0; i--) {
        int j = random_int(0, i);
        Element temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int quiz_user(Element *arr, int num_questions) {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        Element element = arr[i];

        printf("Question %d: What is the symbol for %s (element number %d)?\n", i+1, element.name, element.number);

        char answer[3];
        scanf("%s", answer);

        if (strcmp(answer, element.symbol) == 0) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", element.symbol);
        }
    }

    return score;
}