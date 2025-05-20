//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PIXELS_PER_BYTE 8

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%d %d", &img->width, &img->height);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void write_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fp, "%d %d\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void embed_message(image *img, const char *message) {
    int i, j, k;
    int msglen = strlen(message);
    for (i = 0, k = 0; i < img->height && k < msglen; i++) {
        for (j = 0; j < img->width && k < msglen; j++) {
            img->data[i * img->width + j].r &= 0xFE;
            img->data[i * img->width + j].r |= (message[k++] >> 7) & 0x01;
            img->data[i * img->width + j].g &= 0xFE;
            img->data[i * img->width + j].g |= (message[k++] >> 6) & 0x01;
            img->data[i * img->width + j].b &= 0xFE;
            img->data[i * img->width + j].b |= (message[k++] >> 5) & 0x01;
        }
    }
}

char *extract_message(image *img) {
    int i, j, k;
    int msglen = 0;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            msglen += (img->data[i * img->width + j].r & 0x01) << 7;
            msglen += (img->data[i * img->width + j].g & 0x01) << 6;
            msglen += (img->data[i * img->width + j].b & 0x01) << 5;
        }
    }

    char *message = malloc(msglen + 1);
    if (!message) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return NULL;
    }

    for (i = 0, k = 0; i < img->height && k < msglen; i++) {
        for (j = 0; j < img->width && k < msglen; j++) {
            message[k++] = (img->data[i * img->width + j].r & 0x01) << 7;
            message[k++] = (img->data[i * img->width + j].g & 0x01) << 6;
            message[k++] = (img->data[i * img->width + j].b & 0x01) << 5;
        }
    }

    message[msglen] = '\0';
    return message;
}

void usage(const char *progname) {
    printf("Usage: %s <input image> <output image> <message>\n", progname);
    printf("Embeds the specified message into the input image and writes the result to the output image.\n");
}

int main(int argc, char **argv) {
    if (argc != 4) {
        usage(argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    embed_message(img, argv[3]);

    write_image(argv[2], img);

    free(img->data);
    free(img);

    return 0;
}