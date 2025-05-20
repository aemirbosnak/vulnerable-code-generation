#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char symbol[3];
    char name[20];
    int atomicNumber;
} Element;

int main() {
    FILE *file = fopen("periodic_table.csv", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    Element elements[118]; // Assuming up to 118 elements in the periodic table
    int count = 0;

    while (fgets(elements[count].symbol, sizeof(elements[count].symbol), file)) {
        if (count >= 118) break; // Prevent buffer overflow
        elements[count].symbol[strcspn(elements[count].symbol, "\n")] = '\0'; // Remove newline character
        fscanf(file, "%[^,],%d\n", elements[count].name, &elements[count].atomicNumber);
        count++;
    }
    fclose(file);

    srand(time(NULL));
    int randomIndex = rand() % count;
    Element selectedElement = elements[randomIndex];

    printf("What is the element with symbol %s?\n", selectedElement.symbol);
    char answer[MAX_LINE_LENGTH];
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = '\0';

    if (strcmp(answer, selectedElement.name) == 0) {
        printf("Correct! The element is %s.\n", selectedElement.name);
    } else {
        printf("Incorrect. The correct answer is %s.\n", selectedElement.name);
    }

    return 0;
}
