#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 20

int main() {
    char filename[100];
    FILE *file;
    char word[MAX_WORD_LENGTH + 1];
    int word_count = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while (fscanf(file, "%s", word) != EOF) {
        word_count++;
    }

    fclose(file);
    printf("Word count: %d\n", word_count);

    // Intentionally write beyond the allocated bounds
    strcpy(word, "This is an intentional buffer overflow");

    return EXIT_SUCCESS;
}
