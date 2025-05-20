//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_PIXELS (MAX_WIDTH * MAX_HEIGHT)
#define MAX_MESSAGE_LENGTH (MAX_PIXELS / 8)
#define ALPHABET_LENGTH 26
#define MAX_ATTEMPTS 1000

int main() {
    srand(time(NULL));
    int width, height, attempts = 0;
    char filename[100];
    printf("Enter the image filename: ");
    scanf("%s", filename);
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    char *buffer = (char *) malloc(size);
    fread(buffer, size, 1, fp);
    fclose(fp);
    char *message = (char *) malloc(MAX_MESSAGE_LENGTH);
    printf("Enter the message: ");
    scanf("%s", message);
    int message_length = strlen(message);
    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Message too long.\n");
        exit(1);
    }
    printf("Enter the number of attempts (0 for unlimited): ");
    scanf("%d", &attempts);
    if (attempts == 0)
        attempts = MAX_ATTEMPTS;
    int pixels_used = 0;
    for (int i = 0; i < MAX_PIXELS; i++) {
        if (pixels_used >= message_length)
            break;
        int x = rand() % width;
        int y = rand() % height;
        int value = buffer[i * 3];
        if (value < 128) {
            value += 1;
        } else {
            value -= 1;
        }
        buffer[i * 3] = value;
        pixels_used++;
    }
    FILE *output = fopen("output.bmp", "wb");
    fwrite(buffer, size, 1, output);
    fclose(output);
    printf("Image saved as output.bmp\n");
    return 0;
}