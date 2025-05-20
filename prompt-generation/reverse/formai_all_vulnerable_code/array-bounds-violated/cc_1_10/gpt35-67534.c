//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants for the ASCII Art Width and Height
#define ART_WIDTH 80
#define ART_HEIGHT 30

// ASCII Art Character Encoding
const char ASCII_ART_CHARS[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

// Generate ASCII Art Character from Pixel Intensity
char get_ascii_char(int intensity) {
    // Determine ASCII Art Character Index based on Pixel Intensity
    int char_index = (intensity / 25.5) + 0.5;
    char ascii_char;
    // Check if Character Index within ASCII Art Encoding Range
    if (char_index > 9) {
        char_index = 9;
    }
    // Set ASCII Art Character based on Character Encoding
    ascii_char = ASCII_ART_CHARS[char_index];
    return ascii_char;
}

int main() {
    // Create Buffer to Store Pixel Intensities
    int pixel_intensity[ART_WIDTH * ART_HEIGHT];
    // Open File for Reading Pixel Intensities
    FILE *intensity_file = fopen("intensity_data.txt", "r");
    // Read Pixel Intensities from File into Buffer
    fread(pixel_intensity, sizeof(int), ART_WIDTH * ART_HEIGHT, intensity_file);
    fclose(intensity_file);
    // Create Buffer to Store ASCII Art Characters
    char ascii_art[ART_WIDTH * ART_HEIGHT + ART_HEIGHT];
    int i, j, intensity_index, ascii_index;
    ascii_index = 0;
    // Convert Pixel Intensities to ASCII Art Characters
    for (i = 0; i < ART_HEIGHT; i++) {
        for (j = 0; j < ART_WIDTH; j++) {
            intensity_index = i * ART_WIDTH + j;
            ascii_art[ascii_index] = get_ascii_char(pixel_intensity[intensity_index]);
            ascii_index++;
        }
        ascii_art[ascii_index] = '\n';
        ascii_index++;
    }
    ascii_art[ascii_index] = '\0';
    // Save ASCII Art to File
    FILE *ascii_art_file = fopen("ascii_art.txt", "w");
    fwrite(ascii_art, sizeof(char), ART_WIDTH * ART_HEIGHT + ART_HEIGHT, ascii_art_file);
    fclose(ascii_art_file);
    printf("ASCII Art Generated Successfully!\n");
    return 0;
}