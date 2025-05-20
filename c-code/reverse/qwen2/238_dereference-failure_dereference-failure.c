#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
} Element;

int load_elements(Element *elements, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return -1;
    }

    int count = 0;
    while (count < MAX_QUESTIONS && fscanf(file, "%s %s %d", elements[count].symbol, elements[count].name, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
    return count;
}

void run_quiz(const Element *elements, int num_elements) {
    srand(time(NULL));
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        int index = rand() % num_elements;
        printf("What is the element with symbol %s? ", elements[index].symbol);
        char answer[20];
        scanf("%s", answer);
        if (strcmp(answer, elements[index].name) == 0) {
            printf("Correct!\n");
        } else {
            printf("Wrong! The correct answer is %s.\n", elements[index].name);
        }
    }
}

int main() {
    Element elements[MAX_QUESTIONS];
    int num_elements = load_elements(elements, "periodic_table.txt");

    if (num_elements == -1) {
        return EXIT_FAILURE;
    }

    if (num_elements < MAX_QUESTIONS) {
        fprintf(stderr, "Warning: Not enough elements in the file. Only %d questions will be asked.\n", num_elements);
    }

    run_quiz(elements, num_elements);

    return EXIT_SUCCESS;
}
