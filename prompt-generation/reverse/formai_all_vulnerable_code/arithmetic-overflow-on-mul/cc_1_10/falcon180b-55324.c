//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_PIXELS 10000

typedef struct {
    int x, y;
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int id;
    int start_x, start_y;
    int end_x, end_y;
} ThreadData;

Pixel *image;
int width, height;

void *thread_func(void *arg) {
    ThreadData *data = (ThreadData *) arg;

    int x, y;
    for (y = data->start_y; y <= data->end_y; y++) {
        for (x = data->start_x; x <= data->end_x; x++) {
            Pixel *pixel = &image[(y * width) + x];
            pixel->r = 0;
            pixel->g = 0;
            pixel->b = 0;
        }
    }

    return NULL;
}

int main() {
    printf("Enter the image width: ");
    scanf("%d", &width);

    printf("Enter the image height: ");
    scanf("%d", &height);

    image = (Pixel *) malloc(width * height * sizeof(Pixel));

    int num_threads = 0;

    printf("Enter the number of threads (max %d): ", MAX_THREADS);
    scanf("%d", &num_threads);

    pthread_t threads[MAX_THREADS];

    int pixels_per_thread = width * height / num_threads;

    int i, j;
    for (i = 0; i < num_threads; i++) {
        int start_x = i * pixels_per_thread;
        int end_x = (i + 1) * pixels_per_thread - 1;

        int start_y = 0;
        int end_y = height - 1;

        ThreadData data;
        data.id = i;
        data.start_x = start_x;
        data.end_x = end_x;
        data.start_y = start_y;
        data.end_y = end_y;

        pthread_create(&threads[i], NULL, thread_func, &data);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Image processing completed!\n");

    return 0;
}