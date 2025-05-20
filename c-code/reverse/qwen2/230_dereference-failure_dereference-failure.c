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

void loadElements(Element elements[], int *numElements) {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fscanf(file, "%s %d", elements[*numElements].name, &elements[*numElements].atomicNumber) != EOF) {
        (*numElements)++;
    }
    fclose(file);
}

int main() {
    Element elements[MAX_ELEMENTS];
    int numElements = 0;
    loadElements(elements, &numElements);

    for (int i = 0; i < numElements; i++) {
        printf("What is the element with atomic number %d?\n", elements[i].atomicNumber);
        char answer[50];
        scanf("%s", answer);
        if (strcmp(answer, elements[i].name) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[i].name);
        }
    }

    return 0;
}
