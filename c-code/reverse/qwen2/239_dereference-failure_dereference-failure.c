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
    int atomic_number;
} Element;

int main() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        perror("Failed to open periodic_table.txt");
        return EXIT_FAILURE;
    }

    Element elements[118]; // Maximum number of elements in the periodic table
    int count = 0;

    while (fgets(elements[count].symbol, sizeof(elements[count].symbol), file)) {
        if (count >= 118) break; // Prevent buffer overflow
        elements[count].symbol[strcspn(elements[count].symbol, "\n")] = '\0';
        fscanf(file, "%s %d", elements[count].name, &elements[count].atomic_number);
        count++;
    }

    fclose(file);

    srand(time(NULL));
    for (int i = 0; i < 10; i++) { // Quiz user with 10 questions
        int index = rand() % count;
        printf("What is the element with symbol %s? ", elements[index].symbol);
        char answer[MAX_LINE_LENGTH];
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = '\0';

        if (strcmp(answer, elements[index].name) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", elements[index].name);
        }
    }

    return EXIT_SUCCESS;
}
