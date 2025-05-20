//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 80
#define MAX_TEXT_LEN 2000
#define ASCII_ART_WIDTH 50

void print_ascii_art(char *text) {
    int len = strlen(text);
    int i, j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < ASCII_ART_WIDTH; j++) {
            char c = tolower(text[i]);
            if (isalpha(c)) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char text[MAX_TEXT_LEN];
    strcpy(text, argv[1]);

    int len = strlen(text);
    if (len > MAX_TEXT_LEN) {
        printf("Input text is too long.\n");
        return 1;
    }

    char line[MAX_LINE_LEN];
    int line_len = 0;
    int i;
    for (i = 0; i < len; i++) {
        if (text[i] == '\n') {
            line[line_len] = '\0';
            print_ascii_art(line);
            line_len = 0;
        } else {
            line[line_len++] = text[i];
        }
    }

    line[line_len] = '\0';
    print_ascii_art(line);

    return 0;
}