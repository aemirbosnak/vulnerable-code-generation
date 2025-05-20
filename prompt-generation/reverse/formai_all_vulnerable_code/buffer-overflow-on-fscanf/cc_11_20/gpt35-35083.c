//FormAI DATASET v1.0 Category: Spell checking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 50
#define MAX_SIZE 1000

int main () {

    char doc[MAX_SIZE];
    char words[MAX_SIZE][MAX_WORD], buffer[MAX_WORD], ch;
    int i = 0, j = 0, k = 0, index = 0;

    FILE *filePointer;

    if ((filePointer = fopen("document.txt", "r")) == NULL) {
        printf("Error! opening the file");
        exit(1);
    }

    while ((ch = fgetc(filePointer)) != EOF) {
        if (isalpha(ch)) {
            buffer[j++] = tolower(ch);
        }
        else if (ch == ' ' || ch == '\n') {
            buffer[j] = '\0';
            j = 0;

            if (strlen(buffer) > 0) {
                strcpy(words[i], buffer);
                i++;
            }
        }
    }

    fclose(filePointer);
    index = i;

    if ((filePointer = fopen("dictionary.txt", "r")) == NULL) {
        printf("Error! opening the file");
        exit(1);
    }

    printf("\nMisspelled Word(s): \n");
    for (i = 0; i < index; i++) {
        for (j = 0; j < MAX_WORD; j++) {
            if (words[i][j] == '\0') {
                break;
            }
            words[i][j] = tolower(words[i][j]);
        }

        rewind(filePointer);

        while (fscanf(filePointer, "%s", buffer) != EOF) {
            if (strcmp(words[i], buffer) == 0) {
                break;
            }
        }

        if (strcmp(words[i], buffer) != 0) {
            printf("%s\n", words[i]);
        }
    }

    fclose(filePointer);

    return 0;
}