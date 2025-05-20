//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 12

typedef struct {
    int x, y;
} Point;

void draw_frame(Point pos) {
    int i, j;

    for (i = 0; i < HEIGHT + 2; i++) {
        if (i == 0 || i == HEIGHT + 1) {
            for (j = 0; j < WIDTH; j++)
                printf("%c", 201);
            printf("\n");
        } else {
            if (i == pos.y) {
                for (j = 0; j < WIDTH; j++) {
                    if (j == pos.x)
                        printf(">%s<", " ");
                    else
                        printf("%c", 196);
                }
                printf("\n");
            } else {
                for (j = 0; j < WIDTH; j++)
                    printf("%c", 196);
                printf("\n");
            }
        }
    }
}

void clear_terminal() {
    int i, j;

    for (i = 0; i < HEIGHT + 2; i++) {
        for (j = 0; j < WIDTH; j++)
            printf("%c", 196);
        printf("\n");
    }
}

void hack(int* number, int* detected) {
    int guess;
    int tries = 5;

    srand(time(NULL));
    *number = rand() % 100 + 1;

    while (tries > 0) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess == *number) {
            printf("Access granted! You hacked the system.\n");
            clear_terminal();
            return;
        }

        (*detected)++;
        printf("Incorrect guess. Tries remaining: %d\n", tries--);
        printf("System detected intrusion. Consequences incoming...\n");
        sleep(1);
        clear_terminal();

        if (tries == 0) {
            printf("Game over. You failed to hack the system.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    int number, detected = 0;
    Point pos = { WIDTH / 2, HEIGHT / 2 };

    system("clear");
    draw_frame(pos);

    hack(&number, &detected);

    return EXIT_SUCCESS;
}