//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_ART_FILE "ascii_art.txt"

typedef struct {
    char *text;
    int width;
    int height;
} ascii_art_t;

ascii_art_t generate_ascii_art(int width, int height) {
    ascii_art_t ascii_art;
    FILE *file;
    char line[MAX_WIDTH];

    // Open the ASCII art file
    file = fopen(ASCII_ART_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open ASCII art file.\n");
        exit(1);
    }

    // Generate the ASCII art
    ascii_art.text = malloc(height * MAX_WIDTH);
    if (ascii_art.text == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for ASCII art.\n");
        exit(1);
    }
    ascii_art.width = width;
    ascii_art.height = height;

    for (int y = 0; y < height; y++) {
        fgets(line, MAX_WIDTH, file);
        strncpy(ascii_art.text + y * MAX_WIDTH, line, MAX_WIDTH);
    }

    fclose(file);
    return ascii_art;
}

void print_ascii_art(const ascii_art_t *ascii_art) {
    for (int y = 0; y < ascii_art->height; y++) {
        printf("%s", ascii_art->text + y * MAX_WIDTH);
    }
}

int main() {
    srand(time(NULL));
    int width = rand() % MAX_WIDTH + 1;
    int height = rand() % MAX_HEIGHT + 1;

    ascii_art_t ascii_art = generate_ascii_art(width, height);
    print_ascii_art(&ascii_art);

    free(ascii_art.text);
    return 0;
}