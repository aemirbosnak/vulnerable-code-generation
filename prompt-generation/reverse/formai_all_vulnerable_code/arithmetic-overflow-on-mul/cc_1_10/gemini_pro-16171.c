//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

void encode(pixel *img, int w, int h, char *msg, int len) {
    if (len == 0) return;

    int x = rand() % w, y = rand() % h;

    img[x + w * y].r &= 0xfe;
    img[x + w * y].r |= msg[len - 1] & 1;

    encode(img, w, h, msg, len - 1);
}

char *decode(pixel *img, int w, int h) {
    static char *msg = NULL;
    static int len = 0;

    int x = rand() % w, y = rand() % h;

    if (img[x + w * y].r & 1) {
        msg = realloc(msg, ++len);
        msg[len - 1] = img[x + w * y].r >> 1;
    }

    if ((img[x + w * y].r & 1) == 0) {
        return msg;
    }

    return decode(img, w, h);
}

int main() {
    int w, h;
    FILE *fp;

    char *filename = "image.bmp";
    fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 18, SEEK_SET);
    fread(&w, sizeof(int), 1, fp);
    fread(&h, sizeof(int), 1, fp);

    pixel *img = malloc(w * h * sizeof(pixel));
    fread(img, w * h * sizeof(pixel), 1, fp);
    fclose(fp);

    char *msg = "Hello, world!";
    encode(img, w, h, msg, strlen(msg));

    fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    fseek(fp, 18, SEEK_SET);
    fwrite(&w, sizeof(int), 1, fp);
    fwrite(&h, sizeof(int), 1, fp);
    fwrite(img, w * h * sizeof(pixel), 1, fp);
    fclose(fp);

    char *decoded = decode(img, w, h);
    printf("%s\n", decoded);

    free(img);
    free(decoded);

    return EXIT_SUCCESS;
}