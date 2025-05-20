//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_TEXT_LENGTH 10000

char text[MAX_TEXT_LENGTH];
int text_length;
int line_length;

void read_text() {
    printf("Enter text to convert to ASCII art: ");
    fgets(text, MAX_TEXT_LENGTH, stdin);
    text_length = strlen(text);
}

void set_line_length() {
    printf("Enter line length (max %d): ", MAX_LINE_LENGTH);
    scanf("%d", &line_length);
    if (line_length > MAX_LINE_LENGTH) {
        line_length = MAX_LINE_LENGTH;
    }
}

void generate_art() {
    int i, j;
    char ascii_text[MAX_LINE_LENGTH];
    for (i = 0; i < text_length; i++) {
        if (isalnum(text[i])) {
            ascii_text[0] = text[i];
            ascii_text[1] = '\0';
            for (j = 0; j < line_length - strlen(ascii_text); j++) {
                printf(" ");
            }
            printf("%s", ascii_text);
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    read_text();
    set_line_length();
    generate_art();
    return 0;
}