//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

typedef uint8_t BYTE;

const int secret_size = 16;

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <image> <secret>\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        perror("Error opening image file");
        return 1;
    }

    FILE *secret = fopen(argv[2], "rb");
    if (!secret) {
        perror("Error opening secret file");
        fclose(image);
        return 1;
    }

    BYTE image_data[65536];
    fread(image_data, 1, 65536, image);
    fclose(image);

    BYTE *secret_data = (BYTE *)malloc(secret_size);
    fread(secret_data, 1, secret_size, secret);
    fclose(secret);

    int offset = 0;
    BYTE *p = (BYTE *)malloc(secret_size);
    for (int i = 0; i < secret_size; i++) {
        p[i] = secret_data[i];
        if (p[i] == 0) {
            offset = i + 1;
            break;
        }
    }

    int n = 0;
    int max_offset = 0;
    for (int i = 0; i < 65536; i++) {
        if (image_data[i] == 0) {
            n = 0;
            for (int j = i; j < 65536; j++) {
                if (image_data[j] == 0) {
                    n++;
                } else {
                    break;
                }
            }

            if (n > max_offset) {
                max_offset = n;
            }
        }
    }

    if (max_offset == 0) {
        printf("No suitable offset found in the image\n");
        return 1;
    }

    for (int i = 0; i < secret_size; i++) {
        if (p[i] == 0) {
            break;
        }
        for (int j = i; j < secret_size; j++) {
            image_data[i + offset] = p[j];
            offset++;
        }
    }

    FILE *output = fopen(argv[1], "wb");
    fwrite(image_data, 1, 65536, output);
    fclose(output);

    printf("Steganography successful!\n");
    free(p);
    return 0;
}