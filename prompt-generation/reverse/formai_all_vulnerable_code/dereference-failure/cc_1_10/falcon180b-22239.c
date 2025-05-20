//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 20
#define CHAR_SET ".,-+*0123456789ABCDEF"

char *text_to_ascii(char *text) {
    int len = strlen(text);
    char *result = malloc(len * 2 + 1);
    int i, j;

    for (i = 0, j = 0; i < len; i++) {
        result[j++] = CHAR_SET[text[i] / 16];
        result[j++] = CHAR_SET[text[i] % 16];
    }

    result[j] = '\0';
    return result;
}

void print_ascii(char *ascii) {
    int len = strlen(ascii);
    int rows = len / WIDTH + (len % WIDTH? 1 : 0);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j < len && ascii[i * WIDTH + j]!= '\0') {
                printf("%c", ascii[i * WIDTH + j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    char *input;
    printf("Enter some text: ");
    scanf("%s", input);

    char *ascii = text_to_ascii(input);
    printf("\nASCII art:\n");
    print_ascii(ascii);

    free(ascii);
    return 0;
}