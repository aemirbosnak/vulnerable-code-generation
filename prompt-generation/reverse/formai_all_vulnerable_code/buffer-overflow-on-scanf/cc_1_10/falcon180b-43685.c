//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

int main(int argc, char *argv[]) {
    FILE *file;
    char filename[MAX_WORD_LENGTH];
    char word[MAX_WORD_LENGTH];
    char ch;
    int count = 0;
    int i = 0;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[i++] = tolower(ch);
        } else if (i > 0) {
            word[i] = '\0';
            count += word_count(word);
            i = 0;
        }
    }

    if (i > 0) {
        word[i] = '\0';
        count += word_count(word);
    }

    printf("Total word count: %d\n", count);

    fclose(file);

    return 0;
}

int word_count(char *word) {
    int count = 0;

    while (*word) {
        if (isalpha(*word)) {
            count++;
        }
        word++;
    }

    return count;
}