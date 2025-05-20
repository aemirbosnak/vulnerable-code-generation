#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char symbol[3];
    char name[20];
} Element;

int read_elements(Element *elements, int max_elements) {
    FILE *file = fopen("periodic_table.txt", "r");
    if (!file) {
        perror("Failed to open periodic_table.txt");
        return -1;
    }

    int count = 0;
    while (count < max_elements && fgets(elements[count].symbol, sizeof(elements[count].symbol), file)) {
        elements[count].symbol[strcspn(elements[count].symbol, "\n")] = '\0';
        if (fgets(elements[count].name, sizeof(elements[count].name), file)) {
            elements[count].name[strcspn(elements[count].name, "\n")] = '\0';
            count++;
        } else {
            break;
        }
    }

    fclose(file);
    return count;
}

void quiz_user(Element *elements, int num_elements) {
    srand(time(NULL));
    for (int i = 0; i < num_elements; i++) {
        int index = rand() % num_elements;
        printf("What is the element with the symbol %s? ", elements[index].symbol);
        char answer[MAX_LINE_LENGTH];
        if (fgets(answer, sizeof(answer), stdin)) {
            answer[strcspn(answer, "\n")] = '\0';
            if (strcmp(answer, elements[index].name) == 0) {
                printf("Correct!\n");
            } else {
                printf("Incorrect. The correct answer is %s.\n", elements[index].name);
            }
        } else {
            printf("Input error. Skipping this question.\n");
        }
    }
}

int main() {
    Element elements[100];
    int num_elements = read_elements(elements, 100);
    if (num_elements > 0) {
        quiz_user(elements, num_elements);
    }
    return 0;
}
