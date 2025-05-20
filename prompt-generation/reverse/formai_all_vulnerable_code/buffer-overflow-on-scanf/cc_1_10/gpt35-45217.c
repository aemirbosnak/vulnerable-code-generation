//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>

int moves = 0;

void hanoi(int discs, int from, int to, int via) {
    if (discs == 1) {
        printf("Move disk from tower %d to tower %d.\n", from, to);
        moves++;
    } else {
        hanoi(discs - 1, from, via, to);
        printf("Move disk from tower %d to tower %d.\n", from, to);
        moves++;
        hanoi(discs - 1, via, to, from);
    }
}

int main() {
    int discs, from, to, via;

    printf("Welcome to the Tower of Hanoi game.\n");
    printf("But first, we need to verify your identity.\n");

    while (1) {
        printf("Please enter your password: ");
        char password[20];
        scanf("%s", password);

        // Check password
        if (strcmp(password, "12345") == 0) {
            printf("Welcome, authenticated user.\n");
            printf("Please enter the number of discs to play with: ");
            scanf("%d", &discs);
            printf("Please enter the initial tower to move from (1, 2 or 3): ");
            scanf("%d", &from);
            printf("Please enter the destination tower to move to (1, 2, or 3): ");
            scanf("%d", &to);
            printf("Please enter the third tower to use as a temporary holding spot (1, 2, or 3): ");
            scanf("%d", &via);

            printf("Starting game with %d discs.\n", discs);
            printf("Moving from tower %d to tower %d, using tower %d as a holding spot.\n", from, to, via);
            hanoi(discs, from, to, via);
            printf("Finished in %d moves. Congratulations!\n", moves);
            break;
        } else {
            printf("Incorrect password, please try again.\n");
        }
    }

    return 0;
}