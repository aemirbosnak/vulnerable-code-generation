//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_ELEMENTS 118

typedef struct {
    char name[30];
    int atomic_number;
    int group_number;
    int periodic_number;
} Element;

Element elements[NUM_ELEMENTS];

void load_data() {
    FILE *file;
    int i;

    file = fopen("elements.txt", "r");

    if (file == NULL) {
        printf("Error: Unable to open elements.txt file.\n");
        exit(1);
    }

    for (i = 0; i < NUM_ELEMENTS; i++) {
        fscanf(file, "%s%d%d%d", elements[i].name, &elements[i].atomic_number, &elements[i].group_number, &elements[i].periodic_number);
    }

    fclose(file);
}

void print_header() {
    printf("\n--------------------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s | %-10s |\n", "Element Name", "Atomic Number", "Group Number", "Periodic Number");
    printf("--------------------------------------------------------------------------------------------------\n");
}

void print_elements() {
    int i;

    for (i = 0; i < NUM_ELEMENTS; i++) {
        printf("| %-20s | %-10d | %-10d | %-10d |\n", elements[i].name, elements[i].atomic_number, elements[i].group_number, elements[i].periodic_number);
    }
}

void quiz_question(Element question_element) {
    char answer[30];
    int correct_answer_index;

    printf("\nWhat is the name of the element with atomic number %d?\n", question_element.atomic_number);

    scanf("%s", answer);

    for (int i = 0; i < NUM_ELEMENTS; i++) {
        if (strcmp(elements[i].name, answer) == 0 && elements[i].atomic_number == question_element.atomic_number) {
            correct_answer_index = i;
            break;
        }
    }

    printf("Correct answer: %s\n", elements[correct_answer_index].name);
}

int main() {
    int i, random_index;
    Element question_element;

    srand(time(NULL));

    load_data();

    print_header();
    print_elements();

    print_header();
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("| Question | Element Name | Atomic Number |\n");
    printf("--------------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 10; i++) {
        random_index = rand() % NUM_ELEMENTS;
        question_element = elements[random_index];

        print_header();
        printf("| %2d | ", i + 1);
        printf("%-20s | ", question_element.name);
        printf("%-15d |\n", question_element.atomic_number);

        quiz_question(question_element);
    }

    printf("\nQuiz complete. Press Enter to exit...");
    getchar();

    return 0;
}