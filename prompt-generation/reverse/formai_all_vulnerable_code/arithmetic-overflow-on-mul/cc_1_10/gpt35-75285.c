//FormAI DATASET v1.0 Category: Image Steganography ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to read the input image
void readImage(FILE* image, int* w, int* h, int* d, unsigned char** r, unsigned char** g, unsigned char** b) {
    char magicNum[3];
    fscanf(image, "%s", magicNum);
    fscanf(image, "%d %d %d", w, h, d);
    int maxVal = 0;
    fscanf(image, "%d", &maxVal);

    *r = (unsigned char*) malloc(*w * *h * sizeof(unsigned char));
    *g = (unsigned char*) malloc(*w * *h * sizeof(unsigned char));
    *b = (unsigned char*) malloc(*w * *h * sizeof(unsigned char));

    // Read pixels
    for (int i = 0; i < *w * *h; i++) {
        fscanf(image, "%c%c%c", &((*r)[i]), &((*g)[i]), &((*b)[i]));
    }
}

// Function to hide message in the image
void steganography(unsigned char* r, unsigned char* g, unsigned char* b, char* message) {
    int messageLength = strlen(message);
    if ((messageLength + 1) * 8 > strlen(r) + strlen(g) + strlen(b)) {
        printf("Image is not big enough to hide the message.");
        exit(1);
    }

    for (int i = 0, j = 0, k = 0, l = 0; i < messageLength; i++, j+=3, k+=3, l+=3) {
        // Convert character to binary string
        char binary[8];
        int val = (int) message[i];
        for (int x = 7; x >= 0; x--) {
            binary[x] = (val % 2 == 0) ? '0' : '1';
            val /= 2;
        }

        // Replace LSB of each channel with the binary string bits
        for (int x = 0; x < 8; x++) {
            r[j] = (r[j] & 0xFE) | (binary[x] - '0');
            g[k] = (g[k] & 0xFE) | (binary[x] - '0');
            b[l] = (b[l] & 0xFE) | (binary[x] - '0');
            j++;
            k++;
            l++;
        }
    }
}

// Function to retrieve message from image
char* retrieveMessage(unsigned char* r, unsigned char* g, unsigned char* b, int w, int h) {
    char* message = (char*) malloc(w * h * sizeof(char));
    int messageLength = 0;

    for (int i = 0, j = 0, k = 0, l = 0; ; i++, j+=3, k+=3, l+=3) {
        int val = 0;
        char binary[8];

        // Combine LSB of each channel to get a byte
        for (int x = 0; x < 8; x++) {
            binary[x] = (r[j] & 0x01) + '0';
            binary[x+1] = '\0';
            val += (r[j] & 0x01) * pow(2, 7-x);
            j++;
        }
        if (val == 0) {
            break;
        }
        message[messageLength] = (char) val;
        messageLength++;

        val = 0;

        for (int x = 0; x < 8; x++) {
            binary[x] = (g[k] & 0x01) + '0';
            binary[x+1] = '\0';
            val += (g[k] & 0x01) * pow(2, 7-x);
            k++;
        }
        if (val == 0) {
            break;
        }
        message[messageLength] = (char) val;
        messageLength++;

        val = 0;

        for (int x = 0; x < 8; x++) {
            binary[x] = (b[l] & 0x01) + '0';
            binary[x+1] = '\0';
            val += (b[l] & 0x01) * pow(2, 7-x);
            l++;
        }
        if (val == 0) {
            break;
        }
        message[messageLength] = (char) val;
        messageLength++;
    }

    return message;
}

// Main function
int main() {
    FILE* image = fopen("image.ppm", "r");
    int w, h, d;
    unsigned char* r;
    unsigned char* g;
    unsigned char* b;

    if (image) {
        readImage(image, &w, &h, &d, &r, &g, &b);
    } else {
        printf("Could not open image.");
        return 1;
    }

    fclose(image);

    char message[] = "Hello, world!";
    
    // Hide message in the image
    steganography(r, g, b, message);

    // Write image with hidden message
    FILE* outputImage = fopen("output.ppm", "w");
    fprintf(outputImage, "P6\n%d %d\n%d\n", w, h, d);
    for (int i = 0; i < w * h; i++) {
        fputc(r[i], outputImage);
        fputc(g[i], outputImage);
        fputc(b[i], outputImage);
    }
    fclose(outputImage);

    // Retrieve message from the image
    FILE* output = fopen("output.ppm", "r");
    if (output) {
        readImage(output, &w, &h, &d, &r, &g, &b);
    }
    fclose(output);

    char* retrieved = retrieveMessage(r, g, b, w, h);

    printf("Original message: %s\n", message);
    printf("Retrieved message: %s\n", retrieved);

    return 0;
}