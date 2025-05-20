//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TEXT_LENGTH 1024*10
#define MAX_ASCII_ART_LENGTH 1024*20

char *text = NULL;
char *ascii_art = NULL;

void generate_ascii_art(char *text) {
    int i, j, k, line_length = 0;
    char *line = strtok(text, "\n");
    ascii_art = malloc(MAX_ASCII_ART_LENGTH);
    strcpy(ascii_art, "");

    while(line!= NULL) {
        int word_count = 0;
        char *word = strtok(line, " ");
        char *ascii_word = malloc(MAX_LINE_LENGTH);
        strcpy(ascii_word, "");

        while(word!= NULL) {
            if(isalpha(word[0])) {
                strcat(ascii_word, "*");
            } else {
                strcat(ascii_word, word);
            }
            strcat(ascii_word, " ");
            word = strtok(NULL, " ");
            word_count++;
        }

        if(line_length + strlen(ascii_word) > MAX_LINE_LENGTH) {
            strcat(ascii_art, "\n");
            line_length = 0;
        }

        strcat(ascii_art, ascii_word);
        strcat(ascii_art, " ");
        line_length += strlen(ascii_word) + 1;
        free(ascii_word);
        line = strtok(NULL, "\n");
    }

    if(line_length > 0) {
        strcat(ascii_art, "\n");
    }
}

int main(int argc, char *argv[]) {
    if(argc!= 2) {
        printf("Usage: %s <text_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    text = malloc(file_length + 1);
    if(text == NULL) {
        printf("Memory error.\n");
        fclose(file);
        return 1;
    }

    fread(text, file_length, 1, file);
    fclose(file);

    generate_ascii_art(text);

    printf("%s", ascii_art);

    free(text);
    free(ascii_art);

    return 0;
}