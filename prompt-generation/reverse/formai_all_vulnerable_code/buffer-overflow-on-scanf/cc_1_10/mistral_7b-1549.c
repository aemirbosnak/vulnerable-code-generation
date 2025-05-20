//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 50

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
    FILE *file;
    char filename[WORD_SIZE], line[WORD_SIZE], *token;
    char reversed_line[WORD_SIZE];

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        char *token_start = line;
        char *token_end;

        // Read words until end of line
        while ((token_end = strchr(token_start, ' '))) {
            int length = token_end - token_start;
            strncpy(reversed_line, token_start, length);
            reverse_word(reversed_line);
            reversed_line[length] = '\0';
            strcat(reversed_line, " ");
            strcat(reversed_line, token_end + 1);
            token_start = token_end + 1;
        }

        // Reverse the last word on the line
        int length = strlen(token_start);
        strncpy(reversed_line, token_start, length);
        reverse_word(reversed_line);
        reversed_line[length] = '\0';
        strcat(reversed_line, "\n");

        // Print the reversed line
        printf("%s", reversed_line);
    }

    fclose(file);
    return 0;
}