//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void game_loop() {
    int score = 0;
    int choice;
    while (1) {
        printf("Choose a number from 1 to 10: ");
        scanf("%d", &choice);

        if (choice > 0 && choice <= 10) {
            if (choice == 1) {
                score++;
                printf("You chose 1, score = %d\n", score);
            } else if (choice == 2) {
                score--;
                printf("You chose 2, score = %d\n", score);
            } else if (choice == 3) {
                score += 5;
                printf("You chose 3, score = %d\n", score);
            } else if (choice == 4) {
                score -= 5;
                printf("You chose 4, score = %d\n", score);
            } else if (choice == 5) {
                score += 10;
                printf("You chose 5, score = %d\n", score);
            } else if (choice == 6) {
                score -= 10;
                printf("You chose 6, score = %d\n", score);
            } else if (choice == 7) {
                score += 15;
                printf("You chose 7, score = %d\n", score);
            } else if (choice == 8) {
                score -= 15;
                printf("You chose 8, score = %d\n", score);
            } else if (choice == 9) {
                score += 20;
                printf("You chose 9, score = %d\n", score);
            } else if (choice == 10) {
                score -= 20;
                printf("You chose 10, score = %d\n", score);
            } else {
                printf("Invalid choice\n");
            }
        } else {
            printf("Invalid choice\n");
        }
    }
}

int main() {
    srand(time(NULL));
    game_loop();
    return 0;
}