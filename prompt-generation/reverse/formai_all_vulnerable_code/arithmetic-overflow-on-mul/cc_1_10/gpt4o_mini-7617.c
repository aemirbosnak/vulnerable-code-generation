//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <jpeglib.h>

// Function to convert a pixel to an ASCII character
char pixelToASCII(int r, int g, int b) {
    int brightness = (r + g + b) / 3; // Calculate average brightness
    if (brightness > 200) return ' ';
    else if (brightness > 150) return '.';
    else if (brightness > 100) return '*';
    else if (brightness > 50) return 'o';
    else return '#';
}

// Function to load the JPEG image
unsigned char* loadJPEG(const char* filename, int* width, int* height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE* infile = fopen(filename, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Can't open %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int numChannels = cinfo.output_components;

    unsigned char* imageBuffer = (unsigned char*)malloc(*width * *height * numChannels);
    unsigned char* rowPointer;

    while (cinfo.output_scanline < cinfo.output_height) {
        rowPointer = imageBuffer + (cinfo.output_scanline) * (*width * numChannels);
        jpeg_read_scanlines(&cinfo, &rowPointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    return imageBuffer;
}

// Function to generate ASCII art from the image
void generateASCIIArt(unsigned char* image, int width, int height) {
    for (int h = 0; h < height; h += 8) { // Reduce size for ASCII art
        for (int w = 0; w < width; w += 4) {
            int r = image[(h * width + w) * 3 + 0];
            int g = image[(h * width + w) * 3 + 1];
            int b = image[(h * width + w) * 3 + 2];
            char asciiChar = pixelToASCII(r, g, b);
            printf("%c", asciiChar);
        }
        printf("\n");
    }
}

// Multiplayer ASCII art input and gameplay
void multiplayerInput() {
    char player1Char, player2Char;

    printf("Player 1, enter your character for ASCII art: ");
    scanf(" %c", &player1Char);
    printf("Player 2, enter your character for ASCII art: ");
    scanf(" %c", &player2Char);
    
    printf("You two chose characters '%c' and '%c' for the art! Let's draw!\n", player1Char, player2Char);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <jpeg-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char* imageBuffer = loadJPEG(argv[1], &width, &height);
    if (imageBuffer == NULL) {
        return EXIT_FAILURE;
    }

    multiplayerInput();
    printf("Generating ASCII art from the image:\n");
    generateASCIIArt(imageBuffer, width, height);
    
    free(imageBuffer);
    return EXIT_SUCCESS;
}