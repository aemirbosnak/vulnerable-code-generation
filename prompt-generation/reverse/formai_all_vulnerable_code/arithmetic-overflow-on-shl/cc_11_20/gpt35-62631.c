//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(void) {
    char original_text[MAX_SIZE];
    printf("Enter the original text: ");
    fgets(original_text, MAX_SIZE, stdin);

    char watermark[MAX_SIZE];
    printf("Enter the watermark: ");
    fgets(watermark, MAX_SIZE, stdin);

    // Convert original_text to binary
    char *bin_text = malloc(MAX_SIZE * 8);
    char *p = bin_text;
    for (int i = 0; original_text[i]; i++) {
        char b = original_text[i];
        for (int j = 0; j < 8; j++) {
            *p++ = (b & 0x80) ? '1' : '0';
            b <<= 1;
        }
    }

    // Embed the watermark
    int watermark_size = strlen(watermark);
    char *pos = bin_text + (MAX_SIZE * 8 - watermark_size * 8) / 2;  // Embed in the middle
    for (int i = 0; i < watermark_size; i++) {
        char b = watermark[i];
        for (int j = 0; j < 8; j++) {
            *pos++ = (*pos & 1) ? (b & 0x80) ? '1' : '0' : (b & 0x80) ? '0' : '1';
            b <<= 1;
        }
    }

    // Convert binary back to text
    char *text = malloc(MAX_SIZE);
    p = bin_text;
    for (int i = 0; i < MAX_SIZE; i++) {
        char b = 0;
        for (int j = 0; j < 8; j++) {
            b <<= 1;
            b |= (*p++ == '1') ? 1 : 0;
        }
        text[i] = b;
    }

    printf("\n\n** Original text:\n%s", original_text);
    printf("** Watermark:\n%s", watermark);
    printf("** Watermarked text:\n%s\n", text);

    free(bin_text);
    free(text);
    return 0;
}