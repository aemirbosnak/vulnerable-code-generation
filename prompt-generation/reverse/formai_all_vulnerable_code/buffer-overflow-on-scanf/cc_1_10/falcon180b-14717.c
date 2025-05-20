//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void read_words(FILE *fp) {
    char word[MAX_WORD_LENGTH];
    int i = 0;

    while (fscanf(fp, "%s", word)!= EOF) {
        if (i >= MAX_WORDS) {
            printf("Error: Too many words in input.\n");
            exit(1);
        }
        strcpy(words[i], word);
        i++;
    }
    num_words = i;
}

int main() {
    FILE *fp;
    char filename[100];

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    read_words(fp);
    fclose(fp);

    printf("Enter the desired date format (e.g. MM/DD/YYYY): ");
    scanf("%s", filename);

    fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: Could not create output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        char *word = words[i];
        int len = strlen(word);

        if (isdigit(word[len - 1])) {
            // Last character is a number, assume it's a date
            char *date_str = word;
            char *month_str = word;
            char *day_str = word + 3;
            char *year_str = word + 6;

            fprintf(fp, "%s %s, %s\n", month_str, day_str, year_str);
        } else {
            // Not a date, write as is
            fprintf(fp, "%s\n", word);
        }
    }

    fclose(fp);

    printf("Done.\n");
    return 0;
}