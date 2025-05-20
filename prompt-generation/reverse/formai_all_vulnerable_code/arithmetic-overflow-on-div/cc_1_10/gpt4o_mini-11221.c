//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PLAYERS 4
#define ASCII_CHARS " .:-=+*%@#"
#define MAX_WIDTH 100

struct Player {
    char name[50];
    char imagePath[256];
    int scaleFactor;
};

void convertToASCII(struct Player *player, unsigned char *imageData, int width, int height);
void readJPEG(const char *filename, unsigned char **imageData, int *width, int *height);
void getPlayerInput(struct Player *player);

int main() {
    struct Player players[MAX_PLAYERS];
    unsigned char *imageData;
    int width, height;

    printf("Welcome to the Multiplayer Image to ASCII Art Converter!\n");
    printf("Enter player details. A maximum of %d players can join!\n", MAX_PLAYERS);

    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("\nPlayer %d:\n", i + 1);
        getPlayerInput(&players[i]);
        
        readJPEG(players[i].imagePath, &imageData, &width, &height);
        convertToASCII(&players[i], imageData, width, height);

        free(imageData);
    }

    return 0;
}

void getPlayerInput(struct Player *player) {
    printf("Enter your name: ");
    fgets(player->name, sizeof(player->name), stdin);
    player->name[strcspn(player->name, "\n")] = 0; // Remove newline character

    printf("Enter the path to your image (JPEG format): ");
    fgets(player->imagePath, sizeof(player->imagePath), stdin);
    player->imagePath[strcspn(player->imagePath, "\n")] = 0; // Remove newline character

    printf("Enter ASCII scale factor (1-10): ");
    scanf("%d", &player->scaleFactor);
    while (getchar() != '\n'); // Clear the input buffer
}

void readJPEG(const char *filename, unsigned char **imageData, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Can't open %s\n", filename);
        exit(1);
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int pixelSize = cinfo.output_components;

    *imageData = (unsigned char *)malloc(*width * *height * pixelSize);
    unsigned char *ptr = *imageData;

    while (cinfo.output_scanline < cinfo.output_height) {
        ptr += jpeg_read_scanlines(&cinfo, &ptr, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
}

void convertToASCII(struct Player *player, unsigned char *imageData, int width, int height) {
    int scale = player->scaleFactor;
    int asciiWidth = width / scale;
    int asciiHeight = height / scale;

    printf("\nASCII Art for %s (Scale: %d):\n", player->name, scale);

    for (int y = 0; y < asciiHeight; y++) {
        for (int x = 0; x < asciiWidth; x++) {
            int pixelIndex = (y * scale * width + x * scale) * 3;
            int grey = (imageData[pixelIndex] + imageData[pixelIndex + 1] + imageData[pixelIndex + 2]) / 3;
            char asciiChar = ASCII_CHARS[(grey * (strlen(ASCII_CHARS) - 1)) / 255];
            putchar(asciiChar);
        }
        putchar('\n');
    }
}