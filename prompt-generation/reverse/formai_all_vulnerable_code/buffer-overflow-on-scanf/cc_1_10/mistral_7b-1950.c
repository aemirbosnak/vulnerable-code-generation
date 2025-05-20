//MISTRAL-7B DATASET v1.0 Category: Text to ASCII art generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 10
#define CHARS " .:!*oe%$#@"

typedef struct {
    double frequency;
    char symbol;
} Character;

void generate_ascii_art(char text[100], char ascii[WIDTH][HEIGHT]) {
    int text_length = strlen(text);
    Character characters[128];
    int num_chars = 0;

    for (int i = 0; i < 128; i++) {
        characters[i].symbol = (char)i;
        if (i >= 97 && i <= 122) { // lowercase letters
            characters[i].frequency = 1.0 / (text_length * 26.0);
        } else if (i >= 65 && i <= 90) { // uppercase letters
            characters[i].frequency = 1.0 / (text_length * 26.0);
        } else if (strchr(CHARS, (char)i)) { // special characters
            characters[i].frequency = 1.0 / (text_length * 11.0);
        } else {
            continue;
        }
        num_chars++;
    }

    for (int i = 0; i < text_length; i++) {
        int char_index = (int)floor(characters[text[i] - 32].frequency * HEIGHT * WIDTH);
        int row = char_index / WIDTH;
        int col = char_index % WIDTH;
        ascii[row][col] = text[i];
        ascii[row][col] += (char)(rand() % 3) * (row % 2 == 0 ? 1 : -1);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (ascii[i][j] != text[i % text_length]) {
                ascii[i][j] = CHARS[(int)(random() % 12)];
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(ascii[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    srand(time(NULL));
    char text[100];
    scanf("%s", text);
    char ascii[WIDTH][HEIGHT];
    generate_ascii_art(text, ascii);
    return 0;
}