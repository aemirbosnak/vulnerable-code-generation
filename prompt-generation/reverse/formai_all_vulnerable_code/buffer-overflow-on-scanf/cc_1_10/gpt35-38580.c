//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80
#define MAX_THREADS 4

typedef struct {
    int startX;
    int endX;
    int startY;
    int endY;
    char text[MAX_WIDTH][MAX_HEIGHT];
} ImageData;

void* generateAscii(void* arg) {
    ImageData* data = (ImageData*)arg;
    char ascii[MAX_HEIGHT * MAX_WIDTH];
    int currentIndex = 0;

    for (int y = data->startY; y < data->endY; y++, currentIndex++) {
        for (int x = data->startX; x < data->endX; x++, currentIndex++) {
            int asciiValue = (int)data->text[x][y];
            ascii[currentIndex] = (char)asciiValue;
        }
        ascii[currentIndex] = '\n';
    }
    ascii[currentIndex] = '\0';

    printf("%s\n", ascii);

    return NULL;
}

int main() {
    int width, height;
    char text[MAX_WIDTH][MAX_HEIGHT];

    printf("Enter the width of the image: ");
    scanf("%d", &width);

    printf("Enter the height of the image: ");
    scanf("%d", &height);

    printf("Enter the text for the image (one character per line):\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            scanf(" %c", &text[x][y]);
        }
    }

    pthread_t threads[MAX_THREADS];
    ImageData images[MAX_THREADS];

    int threadCount = 0;
    for (int i = 0; i < MAX_THREADS; i++) {
        // Calculate boundaries for each thread
        int step = width / MAX_THREADS;
        images[i].startX = i * step;
        images[i].endX = (i + 1) * step;
        images[i].startY = 0;
        images[i].endY = height;

        // Keep the last thread updated with any remaining pixels
        if (i == MAX_THREADS - 1) {
            images[i].endX = width;
        }

        memcpy(images[i].text, text, sizeof(text));

        pthread_create(&threads[i], NULL, generateAscii, (void*)&images[i]);
        threadCount++;
    }

    // Wait for threads to finish
    for (int i = 0; i < threadCount; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}