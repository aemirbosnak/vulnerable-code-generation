//FormAI DATASET v1.0 Category: Word Count Tool ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Counts the number of occurrences of a specified word in a text file */

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [word] [input_file]\n", argv[0]);
        return 0;
    }

    char *word = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 0;
    }

    char buffer[256];
    int word_count = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        int i, j;
        int match = 0;
        for (i = 0; buffer[i] != '\0'; i++) {
            if (!isalpha(buffer[i])) {
                continue;
            }

            for (j = 0; word[j] != '\0'; j++) {
                if (tolower(buffer[i + j]) != tolower(word[j])) {
                    break;
                }
            }

            if (word[j] == '\0') {
                match = 1;
                break;
            }
        }

        if (match) {
            word_count++;
        }
    }

    printf("%s occurs %d times in %s\n", word, word_count, filename);
    fclose(file);

    return 0;
}