//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 50
#define MAX_SYMBOL_LENGTH 3
#define MAX_ATOMIC_NUMBER_LENGTH 3

struct element {
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    int atomic_number;
};

void load_elements(struct element *elements) {
    FILE *fp = fopen("elements.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open elements file.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(fp, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number)!= EOF) {
        count++;
    }

    fclose(fp);
}

int main() {
    struct element elements[MAX_ELEMENTS];
    load_elements(elements);

    int num_questions = 10;
    int correct_answers = 0;

    for (int i = 0; i < num_questions; i++) {
        int random_index = rand() % MAX_ELEMENTS;
        struct element question_element = elements[random_index];

        char name_buffer[MAX_NAME_LENGTH];
        strcpy(name_buffer, question_element.name);
        char *name_buffer_ptr = name_buffer;
        while (*name_buffer_ptr!= '\0') {
            *name_buffer_ptr = tolower(*name_buffer_ptr);
            name_buffer_ptr++;
        }

        char symbol_buffer[MAX_SYMBOL_LENGTH];
        strcpy(symbol_buffer, question_element.symbol);
        char *symbol_buffer_ptr = symbol_buffer;
        while (*symbol_buffer_ptr!= '\0') {
            *symbol_buffer_ptr = tolower(*symbol_buffer_ptr);
            symbol_buffer_ptr++;
        }

        char atomic_number_buffer[MAX_ATOMIC_NUMBER_LENGTH];
        sprintf(atomic_number_buffer, "%d", question_element.atomic_number);

        printf("Question %d: What element has the symbol %s and atomic number %s?\n", i+1, symbol_buffer, atomic_number_buffer);

        char answer[MAX_NAME_LENGTH];
        scanf("%s", answer);

        if (strcmp(answer, name_buffer) == 0) {
            correct_answers++;
        }
    }

    printf("You got %d out of %d questions correct.\n", correct_answers, num_questions);

    return 0;
}