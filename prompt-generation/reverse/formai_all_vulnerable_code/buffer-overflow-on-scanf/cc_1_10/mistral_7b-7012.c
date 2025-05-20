//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 128
#define WIDTH 30
#define HEIGHT 10

void print_ascii_char(int ascii) {
    if (ascii >= 33 && ascii <= 126) {
        printf("%c", ascii);
    } else {
        printf("_");
    }
}

void print_ascii_char_pattern(int ascii, int width) {
    int i;
    for (i = 0; i < width; i++) {
        print_ascii_char(ascii);
    }
    printf("\n");
}

void text_to_ascii(char *text, int *ascii_arr, int width) {
    int text_len = strlen(text), i, j;
    for (i = 0; i < text_len; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            ascii_arr[i] = text[i] - 'A' + 65;
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            ascii_arr[i] = text[i] - 'a' + 97;
        } else if (text[i] == ' ') {
            ascii_arr[i] = 32;
        } else {
            ascii_arr[i] = -1;
        }
    }

    for (i = 0; i < text_len; i++) {
        if (ascii_arr[i] != -1) {
            for (j = 0; j < HEIGHT; j++) {
                print_ascii_char_pattern(ascii_arr[i], width);
            }
            printf("\n");
        }
    }
}

int main() {
    char text[MAX_CHAR];
    int ascii_arr[MAX_CHAR];

    printf("Enter the text: ");
    scanf("%s", text);

    text_to_ascii(text, ascii_arr, WIDTH);

    return 0;
}