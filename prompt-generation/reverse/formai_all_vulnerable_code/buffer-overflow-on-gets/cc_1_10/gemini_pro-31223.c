//GEMINI-pro DATASET v1.0 Category: Text to ASCII art generator ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

char* ascii_art_chars = " .:-=+*#%@";

int main() {
    char text[256];
    int text_length;
    int i, j, k;
    int char_index;
    float char_width;
    int char_height;
    int pixel_width;
    int pixel_height;
    int pixel_index;
    char pixel_char;
    int pixel_intensity;
    float intensity_factor;

    printf("Enter text to convert to ASCII art: ");
    gets(text);

    text_length = strlen(text);

    char_width = (float)WIDTH / text_length;
    char_height = HEIGHT;

    for (i = 0; i < text_length; i++) {
        char_index = text[i] - ' ';

        for (j = 0; j < char_width; j++) {
            for (k = 0; k < char_height; k++) {
                pixel_width = j * (1.0 / char_width) * char_width;
                pixel_height = k * (1.0 / char_height) * char_height;
                pixel_index = pixel_width + pixel_height * WIDTH;
                pixel_char = ascii_art_chars[pixel_index];
                intensity_factor = (j / char_width) * (k / char_height);
                pixel_intensity = (int)(intensity_factor * 10);
                pixel_char = ascii_art_chars[pixel_intensity];
                printf("%c", pixel_char);
            }
        }
    }

    printf("\n");

    return 0;
}