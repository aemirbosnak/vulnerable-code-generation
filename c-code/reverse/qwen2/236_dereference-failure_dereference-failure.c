#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

typedef struct {
    char name[50];
    int atomicNumber;
} Element;

int main() {
    FILE *file = fopen("periodic_table.csv", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Element elements[MAX_ELEMENTS];
    int count = 0;

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        if (token && count < MAX_ELEMENTS) {
            strcpy(elements[count].name, token);
            token = strtok(NULL, ",");
            if (token) {
                elements[count].atomicNumber = atoi(token);
                count++;
            }
        }
    }

    fclose(file);

    for (int i = 0; i < count; i++) {
        printf("Element %d: %s\n", i + 1, elements[i].name);
        printf("Atomic Number: %d\n", elements[i].atomicNumber);
        printf("Guess the element's atomic number: ");
        int guess;
        scanf("%d", &guess);
        if (guess == elements[i].atomicNumber) {
            printf("Correct!\n");
        } else {
            printf("Incorrect! The correct answer was %d.\n", elements[i].atomicNumber);
        }
    }

    return EXIT_SUCCESS;
}
