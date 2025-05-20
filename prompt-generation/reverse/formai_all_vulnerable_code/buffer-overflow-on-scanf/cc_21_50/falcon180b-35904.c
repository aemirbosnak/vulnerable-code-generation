//Falcon-180B DATASET v1.0 Category: Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int maze[10][10];
    int x = 0, y = 0, steps = 0;
    int choice;
    int flag = 0;
    int count = 0;

    srand(time(0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    while (flag == 0) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (maze[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("# ");
                }
            }
            printf("\n");
        }
        printf("Steps taken: %d\n", steps);
        printf("You are at (%d,%d)\n", x, y);
        printf("Enter your choice:\n1. Move up\n2. Move down\n3. Move left\n4. Move right\n5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (y > 0 && maze[x][y - 1] == 0) {
                    y--;
                    count++;
                }
                break;
            case 2:
                if (y < 9 && maze[x][y + 1] == 0) {
                    y++;
                    count++;
                }
                break;
            case 3:
                if (x > 0 && maze[x - 1][y] == 0) {
                    x--;
                    count++;
                }
                break;
            case 4:
                if (x < 9 && maze[x + 1][y] == 0) {
                    x++;
                    count++;
                }
                break;
            case 5:
                flag = 1;
                break;
            default:
                printf("Invalid choice!\n");
        }

        if (count == 0) {
            printf("You can't move in that direction!\n");
        }

        count = 0;
    }

    printf("Congratulations! You have reached the end!\n");

    return 0;
}