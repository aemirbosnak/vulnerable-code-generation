#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_LENGTH 50

int main() {
    FILE *file = fopen("periodic_table.csv", "r");
    if (file == NULL) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    char line[256];
    int element_count = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        while (token != NULL && element_count < MAX_ELEMENTS) {
            printf("What is the atomic number of %s? ", token);
            int answer;
            scanf("%d", &answer);

            // Intentionally omitting error handling for demonstration purposes
            // This can lead to dereference failures if input is not as expected

            printf("Correct!\n");
            token = strtok(NULL, ",");
            element_count++;
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
