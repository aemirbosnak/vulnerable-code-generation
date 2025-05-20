//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

int main() {
    FILE *fp;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    int word_count = 0;
    int char_count = 0;
    int line_count = 0;

    printf("Enter the name of the file to read: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        line_count++;
        char_count += strlen(line);

        int word_index = 0;
        char *token = strtok(line, " \t\n\r\f\v,.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            word_count++;
            word_index++;

            if (word_index == MAX_WORD_LENGTH) {
                printf("Error: word is too long.\n");
                exit(1);
            }

            token = strtok(NULL, " \t\n\r\f\v,.?!;:");
        }
    }

    fclose(fp);

    printf("Total number of lines: %d\n", line_count);
    printf("Total number of characters: %d\n", char_count);
    printf("Total number of words: %d\n", word_count);

    return 0;
}