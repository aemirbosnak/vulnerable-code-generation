//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char *name;
    int length;
} Word;

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: could not open file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    Word word = { NULL, 0 };
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        int i = 0;
        while (line[i]!= '\0') {
            if (isalpha(line[i])) {
                if (word.name == NULL) {
                    word.name = malloc(MAX_WORD_LENGTH);
                    memset(word.name, 0, MAX_WORD_LENGTH);
                    word.length = 0;
                }
                strncat(word.name, &line[i], 1);
                word.length++;
            } else if (word.name!= NULL) {
                break;
            }
            i++;
        }

        if (word.name!= NULL) {
            printf("Line %d: %s\n", line_number, word.name);
        }

        memset(word.name, 0, MAX_WORD_LENGTH);
        word.length = 0;
        line_number++;
    }

    fclose(file);
    return 0;
}