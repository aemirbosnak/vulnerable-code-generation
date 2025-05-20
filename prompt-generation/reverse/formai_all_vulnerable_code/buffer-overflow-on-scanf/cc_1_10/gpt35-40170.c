//FormAI DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x,y;
} Coords;

int getBit(unsigned char byte, int index) {
    return (byte & (1 << (8 - index))) > 0;
}

unsigned char setBit(unsigned char byte, int index, int value) {
    if (value) {
        return byte | (1 << (8 - index));
    } else {
        return byte & ~(1 << (8 - index));
    }
}

void hideMessage(Coords *pixels, char *message, int messageLen) {
    int pixelIndex = 0, bitIndex = 1;
    unsigned char pixelByte = 0;
    
    while (bitIndex <= messageLen * 8) {
        int bit = getBit(message[bitIndex / 8], bitIndex % 8);
        pixelByte = setBit(pixelByte, bitIndex % 8, bit);
        
        if (bitIndex % 8 == 0) {
            pixels[pixelIndex].y = pixelByte;
            pixelIndex++;
            pixelByte = 0;
        }
        
        bitIndex++;
    }
    
    if (bitIndex % 8 != 1) {
        pixels[pixelIndex].y = pixelByte;
        pixelIndex++;
    }
    
    pixels[pixelIndex].y = -1;
    
    printf("Message hidden in %d pixels\n", pixelIndex);
}

void showMessage(Coords *pixels) {
    int pixelIndex = 0, bitIndex = 1;
    unsigned char pixelByte = 0;
    char message[1024] = {0};
    
    while (pixels[pixelIndex].y != -1) {
        pixelByte = pixels[pixelIndex].y;
        message[bitIndex / 8] = setBit(message[bitIndex / 8], bitIndex % 8, getBit(pixelByte, bitIndex % 8));
        
        if (bitIndex % 8 == 0) {
            printf("%c", message[bitIndex / 8]);
        }
        
        pixelIndex++;
        bitIndex++;
    }
    
    printf("\n");
}

int main() {
    Coords pixels[1024] = {0};
    char message[1024] = {0};
    int messageLen;
    
    printf("Enter message to hide: ");
    scanf("%[^\n]s", message);
    messageLen = strlen(message);
    
    hideMessage(pixels, message, messageLen);
    
    printf("The hidden message is: ");
    showMessage(pixels);
    
    return 0;
}