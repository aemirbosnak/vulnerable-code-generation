//Falcon-180B DATASET v1.0 Category: Text processing ; Style: calm
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

int main() {
    FILE *input_file;
    char filename[100], line[1000], word[MAX_WORD_LENGTH];
    int word_count = 0;
    input_file = fopen("input.txt", "r");

    if (input_file == NULL) {
        printf("Error opening input file\n");
        return 1;
    }

    while (fgets(line, 1000, input_file)!= NULL) {
        int i, j;
        for (i = 0; i < strlen(line); i++) {
            if (isspace(line[i])) {
                line[i] = '\0';
            }
        }
        strcpy(filename, line);
        input_file = fopen(filename, "r");

        if (input_file == NULL) {
            printf("Error opening file %s\n", filename);
            return 1;
        }

        while (fgets(line, 1000, input_file)!= NULL) {
            for (j = 0; j < strlen(line); j++) {
                if (isspace(line[j])) {
                    line[j] = '\0';
                }
            }
            strcpy(word, line);
            if (strlen(word) > 0) {
                if (word_count >= MAX_WORDS) {
                    printf("Error: Maximum number of words exceeded\n");
                    return 1;
                }
                strcpy(line, word);
            }
        }
        fclose(input_file);
        word_count++;
    }

    printf("Total number of words: %d\n", word_count);
    return 0;
}