//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 16
#define IMAGE_SIZE 1024

typedef struct {
    char watermark[WATERMARK_SIZE + 1];
    int watermark_size;
    char image[IMAGE_SIZE + 1];
    int image_size;
} Watermark;

Watermark *create_watermark(const char *watermark, const char *image) {
    Watermark *w = malloc(sizeof(Watermark));
    strncpy(w->watermark, watermark, WATERMARK_SIZE);
    w->watermark_size = strlen(w->watermark);
    strncpy(w->image, image, IMAGE_SIZE);
    w->image_size = strlen(w->image);
    return w;
}

void destroy_watermark(Watermark *w) {
    free(w);
}

char *embed_watermark(const char *watermark, const char *image) {
    Watermark *w = create_watermark(watermark, image);
    char *result = malloc(IMAGE_SIZE + WATERMARK_SIZE + 1);
    int i, j;

    for (i = 0, j = 0; i < IMAGE_SIZE; i++) {
        if (i % 2 == 0) {
            result[j++] = w->image[i];
        } else {
            result[j++] = w->watermark[i / 2];
        }
    }

    destroy_watermark(w);
    return result;
}

int main() {
    const char *watermark = "Linus Torvalds";
    const char *image = "GNU/Linux is a free and open-source software operating system for computers.";
    char *watermarked_image = embed_watermark(watermark, image);
    printf("%s\n", watermarked_image);
    free(watermarked_image);
    return 0;
}