//Falcon-180B DATASET v1.0 Category: Periodic Table Quiz ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 10
#define MAX_SYMBOL_LENGTH 3

typedef struct {
    char name[MAX_NAME_LENGTH+1];
    char symbol[MAX_SYMBOL_LENGTH+1];
    int atomic_number;
} Element;

Element elements[MAX_ELEMENTS];

void load_elements() {
    FILE *file = fopen("elements.txt", "r");
    if (file == NULL) {
        printf("Error: elements.txt not found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s %d", elements[count].name, elements[count].symbol, &elements[count].atomic_number) == 3) {
        count++;
    }

    fclose(file);
}

int main() {
    load_elements();

    int score = 0;
    int total_questions = 0;

    char input[MAX_NAME_LENGTH+1];

    while (1) {
        printf("Enter the name or symbol of an element: ");
        fgets(input, MAX_NAME_LENGTH+1, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) == 0) {
            printf("Invalid input.\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < MAX_ELEMENTS; i++) {
            if (strcmp(input, elements[i].name) == 0 || strcmp(input, elements[i].symbol) == 0) {
                found = 1;
                printf("Element found: %s (%s)\n", elements[i].name, elements[i].symbol);
                printf("Atomic number: %d\n", elements[i].atomic_number);
                printf("Score: %d/%d\n", score, total_questions);
                break;
            }
        }

        if (!found) {
            printf("Element not found.\n");
        }
    }

    return 0;
}