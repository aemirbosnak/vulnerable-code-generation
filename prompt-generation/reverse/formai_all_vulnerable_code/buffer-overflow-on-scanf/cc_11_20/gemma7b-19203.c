//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, a, b, c;
    char ch, cmd;

    printf("Enter 'start' to begin: ");
    scanf("%s", &ch);

    if (ch == 'start') {
        printf("Enter the dimensions of the matrix (x, y): ");
        scanf("%d %d", &x, &y);

        printf("Enter the number of iterations: ");
        scanf("%d", &z);

        a = rand() % x;
        b = rand() % y;
        c = rand() % z;

        printf("The coordinates of the bomb are: (%d, %d, %d)\n", a, b, c);

        for (int i = 0; i < z; i++) {
            printf("Enter 'move' followed by the direction (north, south, east, west): ");
            scanf("%s %s", &cmd, &ch);

            switch (cmd) {
                case 'move':
                    switch (ch) {
                        case 'n':
                            if (b > 0) {
                                b--;
                                printf("You moved north.\n");
                            } else {
                                printf("You cannot move north.\n");
                            }
                            break;
                        case 's':
                            if (b < y - 1) {
                                b++;
                                printf("You moved south.\n");
                            } else {
                                printf("You cannot move south.\n");
                            }
                            break;
                        case 'e':
                            if (a > 0) {
                                a--;
                                printf("You moved east.\n");
                            } else {
                                printf("You cannot move east.\n");
                            }
                            break;
                        case 'w':
                            if (a < x - 1) {
                                a++;
                                printf("You moved west.\n");
                            } else {
                                printf("You cannot move west.\n");
                            }
                            break;
                    }
                    break;
            }

            if (a == a && b == b && c == c) {
                printf("You found the bomb! You win!\n");
                exit(0);
            }
        }

        printf("You ran out of iterations. Game over.\n");
        exit(0);
    } else {
        printf("Invalid input. Please try again.\n");
    }

    return 0;
}