//GEMINI-pro DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    char *hex;
    int r, g, b;
} color_t;

pthread_mutex_t lock;

void *convert_color(void *arg) {
    color_t *color = (color_t *)arg;

    pthread_mutex_lock(&lock);
    sscanf(color->hex, "%x", &color->r);
    sscanf(color->hex + 2, "%x", &color->g);
    sscanf(color->hex + 4, "%x", &color->b);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[10];
    color_t colors[10] = {
        {"#FF0000", 0, 0, 0},
        {"#00FF00", 0, 0, 0},
        {"#0000FF", 0, 0, 0},
        {"#FFFFFF", 0, 0, 0},
        {"#000000", 0, 0, 0},
        {"#FF00FF", 0, 0, 0},
        {"#FFFF00", 0, 0, 0},
        {"#00FFFF", 0, 0, 0},
        {"#808080", 0, 0, 0},
        {"#C0C0C0", 0, 0, 0},
    };

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, convert_color, &colors[i]);
    }

    for (int i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < 10; i++) {
        printf("%s: %d, %d, %d\n", colors[i].hex, colors[i].r, colors[i].g, colors[i].b);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}