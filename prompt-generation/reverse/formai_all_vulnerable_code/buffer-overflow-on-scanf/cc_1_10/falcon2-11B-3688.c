//Falcon2-11B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[50];
    FILE *fp;
    char line[100];
    int line_count = 0, word_count = 0, char_count = 0;

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        line_count++;
        word_count += count_words(line);
        char_count += count_chars(line);
    }

    printf("File: %s\n", filename);
    printf("Line count: %d\n", line_count);
    printf("Word count: %d\n", word_count);
    printf("Character count: %d\n", char_count);

    fclose(fp);
    return 0;
}

int count_words(char *str) {
    int count = 0;
    char *token = strtok(str, " \t\n");
    while (token!= NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

int count_chars(char *str) {
    int count = 0;
    for (int i = 0; str[i]!= '\0'; i++) {
        count++;
    }
    return count;
}