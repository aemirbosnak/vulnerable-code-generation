//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 20
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+-=[]{}|;:,.<>?"
#define MAX_CHARS 63

struct pixel {
    char value;
    int red;
    int green;
    int blue;
};

void generate_ascii_art(char* text, struct pixel* pixels) {
    int len = strlen(text);
    int i = 0;
    while (i < len) {
        int j = 0;
        while (j < MAX_WIDTH && i < len) {
            char c = tolower(text[i]);
            if (c >= 'a' && c <= 'z') {
                pixels[i * MAX_WIDTH + j].value = CHAR_SET[c - 'a'];
                pixels[i * MAX_WIDTH + j].red = rand() % 256;
                pixels[i * MAX_WIDTH + j].green = rand() % 256;
                pixels[i * MAX_WIDTH + j].blue = rand() % 256;
            }
            j++;
            i++;
        }
    }
}

void print_ascii_art(struct pixel* pixels, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", pixels[(i * width) + j].value);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    char text[MAX_WIDTH * MAX_HEIGHT];
    scanf("%s", text);
    struct pixel pixels[MAX_WIDTH * MAX_HEIGHT];
    generate_ascii_art(text, pixels);
    print_ascii_art(pixels, MAX_WIDTH, MAX_HEIGHT);
    return 0;
}