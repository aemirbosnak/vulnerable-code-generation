//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64
#define MAX_NUM_WORDS 1000

int main(int argc, char* argv[]) {
    FILE* fp;
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int num_words = 0;
    int num_chars = 0;
    int num_lines = 0;

    printf("Enter filename: ");
    scanf("%s", argv[1]);

    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        num_lines++;
        num_chars += strlen(line);

        char* p = line;
        while (*p!= '\0') {
            if (isalpha(*p)) {
                strncpy(word, p, MAX_WORD_LENGTH);
                word[sizeof(word) - 1] = '\0';
                printf("%s ", toupper(word));
            }
            p++;
        }
        printf("\n");
    }

    fclose(fp);

    printf("Number of lines: %d\n", num_lines);
    printf("Number of characters: %d\n", num_chars);
    printf("Number of words: %d\n", num_words);

    return 0;
}