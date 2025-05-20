//FormAI DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include <stdio.h>

int main() {
    printf("Welcome to the Robot Movement Control Program!\n");
    int pos_x = 0, pos_y = 0;
    char direction = 'N';
    while (1) {
        printf("Current position: (%d,%d), facing %c\n", pos_x, pos_y, direction);
        printf("Enter your command (F|B|L|R|Q): ");
        char command;
        scanf(" %c", &command);
        switch(command) {
            case 'F':
                if (direction == 'N')
                    pos_y++;
                else if (direction == 'S')
                    pos_y--;
                else if (direction == 'E')
                    pos_x++;
                else // direction == 'W'
                    pos_x--;
                break;
            case 'B':
                if (direction == 'N')
                    pos_y--;
                else if (direction == 'S')
                    pos_y++;
                else if (direction == 'E')
                    pos_x--;
                else // direction == 'W'
                    pos_x++;
                break;
            case 'L':
                if (direction == 'N')
                    direction = 'W';
                else if (direction == 'S')
                    direction = 'E';
                else if (direction == 'E')
                    direction = 'N';
                else // direction == 'W'
                    direction = 'S';
                break;
            case 'R':
                if (direction == 'N')
                    direction = 'E';
                else if (direction == 'S')
                    direction = 'W';
                else if (direction == 'E')
                    direction = 'S';
                else // direction == 'W'
                    direction = 'N';
                break;
            case 'Q':
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Unknown command %c\n", command);
                break;
        }
    }
    return 0;
}