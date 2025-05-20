//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: post-apocalyptic
#include <stdio.h>

int main() {
    char name[100];
    int score = 0;
    char* state = "ALIVE";
    int x = 0;
    int y = 0;
    int turns = 0;
    int difficulty = 0;

    printf("Welcome to the post-apocalyptic C Table Game! \n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Hello, %s. \n", name);

    printf("The world is a dangerous place, and you must survive. \n");
    printf("You are in a room with %d zombies and %d items. \n", 10, 5);
    printf("Your goal is to collect all the items and escape the room alive. \n");
    printf("Each turn, you can move up, down, left, or right. \n");
    printf("You can also pick up or drop an item. \n");
    printf("You have %d turns to complete the game. \n", 100);

    while (difficulty < 5 && state!= "DEAD") {
        printf("Enter your move (up, down, left, right, pick up, drop): ");
        scanf("%d", &x);

        switch (x) {
            case 1:
                if (y == 0) {
                    y = -1;
                } else {
                    y = 1;
                }
                break;
            case 2:
                if (y == 0) {
                    y = 1;
                } else {
                    y = -1;
                }
                break;
            case 3:
                if (x == 0) {
                    x = -1;
                } else {
                    x = 1;
                }
                break;
            case 4:
                if (x == 0) {
                    x = 1;
                } else {
                    x = -1;
                }
                break;
            case 5:
                if (score < 5) {
                    score++;
                } else {
                    printf("You have collected all the items. \n");
                    state = "DEAD";
                }
                break;
            case 6:
                if (score > 0) {
                    score--;
                } else {
                    printf("You dropped your last item. \n");
                    state = "DEAD";
                }
                break;
            default:
                printf("Invalid move. \n");
                state = "DEAD";
                break;
        }

        if (state == "DEAD") {
            printf("You died. Game over. \n");
            break;
        }

        if (state == "ALIVE") {
            printf("You are in a room with %d zombies and %d items. \n", 10 - score, 5);
            printf("You have %d turns to complete the game. \n", 100 - turns);
            printf("Enter your move (up, down, left, right, pick up, drop): ");
            scanf("%d", &x);
        }
    }

    return 0;
}