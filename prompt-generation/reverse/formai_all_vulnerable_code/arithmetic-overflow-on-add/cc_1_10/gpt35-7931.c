//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50
#define COLORS 4

int canvas[HEIGHT][WIDTH];

void* fillCanvas(void* threadID) {
    int id = (int) threadID;
    srand(time(NULL) + id);

    for (int i = id; i < HEIGHT * WIDTH; i += COLORS) {
        int x = i % WIDTH;
        int y = i / WIDTH;
        canvas[y][x] = rand() % COLORS;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[COLORS];

    for (int i = 0; i < COLORS; i++) {
        pthread_create(&threads[i], NULL, fillCanvas, (void*)i);
    }

    for (int i = 0; i < COLORS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Generated Art:\n\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int color = canvas[y][x];
            switch (color) {
                case 0:
                    printf("\033[41m  \033[0m");
                    break;
                case 1:
                    printf("\033[42m  \033[0m");
                    break;
                case 2:
                    printf("\033[43m  \033[0m");
                    break;
                case 3:
                    printf("\033[44m  \033[0m");
                    break;
                default:
                    printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}