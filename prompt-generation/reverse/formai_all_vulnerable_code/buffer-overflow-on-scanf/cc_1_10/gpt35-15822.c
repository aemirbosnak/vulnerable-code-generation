//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// This function takes a word as argument and returns the frequency of the word in the given file
int getFrequency(char word[], char filename[]) {
    FILE *fp;
    char ch, str[50];
    int i = 0, frequency = 0, len;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("\nError opening file %s\n", filename);
        exit(1);
    }

    len = strlen(word);

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            str[i++] = tolower(ch); //Convert uppercase letters to lowercase
            if (i == len) {
                str[i] = '\0';
                if (strcmp(str, word) == 0) {
                    frequency++;
                }
                i = 0;
            }
        } else {
            i = 0;
        }
    }
    fclose(fp);
    return frequency;
}

int main() {
    char filename[50], word[20];
    int i, freq;

    printf("\nEnter the filename: ");
    scanf("%s", filename);

    printf("\nEnter the word to get the frequency: ");
    scanf("%s", word);

    freq = getFrequency(word, filename);

    printf("\nThe frequency of the word '%s' in file '%s' is %d\n", word, filename, freq);
    return 0;
}