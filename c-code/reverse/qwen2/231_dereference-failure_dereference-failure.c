#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char symbol[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
} Element;

int main() {
    FILE *file = fopen("elements.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    Element elements[MAX_ELEMENTS];
    int count = 0;

    while (fscanf(file, "%s %s", elements[count].symbol, elements[count].name) != EOF && count < MAX_ELEMENTS) {
        count++;
    }

    fclose(file);

    printf("Welcome to the Periodic Table Quiz!\n");

    for (int i = 0; i < count; i++) {
        char guess[MAX_NAME_LENGTH];
        printf("What is the name of the element with symbol %s? ", elements[i].symbol);
        scanf("%s", guess);

        if (strcmp(guess, elements[i].name) == 0) {
            printf("Correct! The name of the element with symbol %s is %s.\n", elements[i].symbol, elements[i].name);
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].name);
        }
    }

    return EXIT_SUCCESS;
}
