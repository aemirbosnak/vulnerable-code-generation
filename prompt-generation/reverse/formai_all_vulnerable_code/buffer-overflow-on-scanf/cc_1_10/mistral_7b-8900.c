//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 50
#define LINE_SIZE 1000

void reverse_word(char *word) {
    int i = 0, j = strlen(word) - 1;
    char temp;

    while (i < j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

int main() {
    FILE *fp;
    char filename[100], line[LINE_SIZE], word[WORD_SIZE], *token;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    printf("\n'Twas brillig, and the slithy toves\n");
    printf("Did gyre and gimble in the wabe;\n");

    while (fgets(line, LINE_SIZE, fp) != NULL) {
        token = strtok(line, " \t\n\r.");
        while (token != NULL) {
            strcpy(word, token);
            reverse_word(word);
            printf("%s", word);
            token = strtok(NULL, " \t\n\r.");
            if (token != NULL)
                printf(" %s", token);
            else
                printf("\n");
        }
    }

    fclose(fp);
    return 0;
}