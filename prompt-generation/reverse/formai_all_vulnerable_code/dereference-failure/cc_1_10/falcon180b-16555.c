//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

char *text_to_ascii_art(char *text) {
    int length = strlen(text);
    char *ascii_art = malloc(length * MAX_HEIGHT + 1);

    int i, j;
    for (i = 0; i < length; i++) {
        char c = text[i];
        if (c == '\n') {
            ascii_art[i] = '\0';
            continue;
        }

        int width = 0;
        for (j = 0; j < 6; j++) {
            int x = (c >> (5 - j)) & 1;
            if (x == 1) {
                width++;
            }
        }

        int height = (MAX_HEIGHT - width) / 2;
        int offset = (MAX_HEIGHT - height) / 2;

        int k;
        for (k = 0; k < height; k++) {
            int row = (i * MAX_HEIGHT) + k + offset;
            int bit = 0x80;
            while (bit > 0) {
                int x = (c >> (5 - j)) & 1;
                if (x == 1) {
                    ascii_art[row] |= bit;
                }
                bit >>= 1;
                j++;
            }
        }

        i += 5;
    }

    ascii_art[length * MAX_HEIGHT] = '\0';

    return ascii_art;
}

int main() {
    char input[1024];
    printf("Enter some text: ");
    fgets(input, 1024, stdin);

    char *ascii_art = text_to_ascii_art(input);

    int i;
    for (i = 0; i < strlen(ascii_art); i++) {
        printf("%c", ascii_art[i]);
    }

    return 0;
}