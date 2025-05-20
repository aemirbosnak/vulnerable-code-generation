#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 4

typedef struct {
    char symbol[MAX_SYMBOL_LENGTH + 1];
    char name[MAX_NAME_LENGTH + 1];
} Element;

int main() {
    FILE *file = fopen("elements.txt", "r");
    Element elements[MAX_ELEMENTS];
    int num_elements = 0;

    while (num_elements < MAX_ELEMENTS && fscanf(file, "%s%s", elements[num_elements].symbol, elements[num_elements].name) == 2) {
        num_elements++;
    }

    fclose(file);

    char user_input[MAX_SYMBOL_LENGTH + 1];
    for (int i = 0; i < num_elements; i++) {
        printf("%s (%s)\n", elements[i].symbol, elements[i].name);
    }

    printf("\nEnter the symbol of an element: ");
    scanf("%s", user_input);

    int correct_answer = -1;
    for (int i = 0; i < num_elements; i++) {
        if (strcmp(user_input, elements[i].symbol) == 0) {
            correct_answer = i;
            break;
        }
    }

    if (correct_answer != -1) {
        printf("Correct! The element is %s.\n", elements[correct_answer].name);
    } else {
        printf("Incorrect. The element you entered was not found.\n");
    }

    return 0;
}
