//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 20

void draw_house(int haunted) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (i == 0 && j == 0) {
                printf("+---");
            } else if (i == 0) {
                printf("+--");
            } else if (j == 0) {
                printf("+--");
            } else if (i == ROWS - 1 && j == COLS - 1) {
                printf("+");
            } else if (i == ROWS - 1) {
                printf("+");
            } else if (j == COLS - 1) {
                printf("+");
            } else {
                printf("+");
            }
        }
        printf("\n");
    }

    if (haunted) {
        printf("Haunted House\n");
    } else {
        printf("Normal House\n");
    }
}

void simulate_haunted_house() {
    int haunted = rand() % 2;
    draw_house(haunted);
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Press 1 to simulate haunted house\n");
        printf("Press 2 to exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            simulate_haunted_house();
        }
    } while (choice!= 2);

    return 0;
}