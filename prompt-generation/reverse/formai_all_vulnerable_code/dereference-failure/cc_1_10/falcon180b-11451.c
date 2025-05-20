//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char ch;
    int word_count = 0, char_count = 0, line_count = 0;
    char *word = NULL;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            if (word!= NULL) {
                word_count++;
                char_count += strlen(word);
                free(word);
                word = NULL;
            }
            line_count++;
        } else {
            if (word == NULL) {
                word = malloc(2 * sizeof(char));
                strcpy(word, "");
            }
            strcat(word, &ch);
        }
        char_count++;
    }

    if (word!= NULL) {
        word_count++;
        char_count += strlen(word);
        free(word);
        word = NULL;
    }
    line_count++;

    printf("Total words: %d\n", word_count);
    printf("Total characters: %d\n", char_count);
    printf("Total lines: %d\n", line_count);

    fclose(file);
    return 0;
}