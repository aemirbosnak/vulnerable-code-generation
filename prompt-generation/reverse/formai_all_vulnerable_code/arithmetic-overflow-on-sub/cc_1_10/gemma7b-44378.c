//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WATERMARK_LENGTH 255

typedef struct watermark_t {
    char *data;
    int length;
    time_t timestamp;
} watermark_t;

void watermark_add(watermark_t *wm, char *data, int length) {
    wm->data = malloc(length);
    memcpy(wm->data, data, length);
    wm->length = length;
    wm->timestamp = time(NULL);
}

int watermark_verify(watermark_t *wm, char *data, int length) {
    if (wm->length != length) {
        return 0;
    }
    if (strcmp(wm->data, data) != 0) {
        return 0;
    }
    if (time(NULL) - wm->timestamp > MAX_WATERMARK_LENGTH) {
        return 0;
    }
    return 1;
}

int main() {
    watermark_t watermark;

    // Add watermark data
    char *data = "This is a secret watermark message";
    int length = strlen(data);
    watermark_add(&watermark, data, length);

    // Verify watermark data
    if (watermark_verify(&watermark, data, length)) {
        printf("Watermark verified!\n");
    } else {
        printf("Watermark verification failed.\n");
    }

    return 0;
}