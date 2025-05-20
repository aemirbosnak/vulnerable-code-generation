//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: introspective
// An uncanny watermarking reverie...

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// A canvas to paint our dreams
typedef struct {
    int width, height;
    unsigned char *pixels;
} Image;

// Uncover the secrets hidden within
Image read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) { perror("Failed to open file"); exit(1); }

    Image img;
    fscanf(fp, "P5\n%d %d\n255\n", &img.width, &img.height);
    img.pixels = malloc(img.width * img.height);
    fread(img.pixels, 1, img.width * img.height, fp);
    fclose(fp);

    return img;
}

// A spell to weave our mark upon the canvas
void watermark(Image *img, const char *message) {
    int len = strlen(message);
    
    // A subtle whisper, scattered like stardust
    for (int i = 0; i < len; i++) {
        int c = message[i];
        for (int j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            int index = i * 8 + j;

            // Paint the bit where the stars align
            if (index < img->width * img->height) {
                img->pixels[index] = (bit) ? img->pixels[index] + 1 : img->pixels[index] - 1;
            }
        }
    }
}

// A whisper carried by the wind
void save_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) { perror("Failed to save file"); exit(1); }

    fprintf(fp, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, 1, img->width * img->height, fp);
    fclose(fp);
}

// The conductor of our ethereal symphony
int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <message>\n", argv[0]);
        return 1;
    }

    // Awaken the canvas
    Image img = read_image(argv[1]);
    
    // Inscribe our message on the canvas
    watermark(&img, argv[2]);

    // A new canvas, imbued with a secret
    save_image(&img, "watermarked.pgm");
    printf("Watermarking complete. Behold 'watermarked.pgm' for the hidden message.\n");

    free(img.pixels);
    return 0;
}