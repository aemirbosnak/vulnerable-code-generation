//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>

#define GRATITUDE_WIDTH 80
#define GRATITUDE_HEIGHT 20
#define GRATITUDE_CHARS 10

void draw_gratitude(char *message, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (i * width + j % GRATITUDE_CHARS == 0) {
                printf(" ");
            } else {
                printf("%c", message[i * width + j]);
            }
        }
        printf("\n");
    }
}

int main() {
    char message[] = "Thank you for using this program!";
    int width = GRATITUDE_WIDTH;
    int height = GRATITUDE_HEIGHT;

    // Set up the grid of characters
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i * width + j % GRATITUDE_CHARS == 0) {
                message[i * width + j] = ' ';
            } else {
                message[i * width + j] = '*';
            }
        }
    }

    // Print the message in a gratuitous manner
    draw_gratitude(message, width, height);

    // Add some extra flair with some timestamps
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&ts.tv_sec));
    printf("Generated at: %s\n", timestamp);

    return 0;
}