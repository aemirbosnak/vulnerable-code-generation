//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: intelligent
#include <stdio.h>

#define MAX_HEIGHT 1000
#define MAX_SPEED 50

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Drone {
    int height;
    int x;
    int y;
    int speed;
    enum Direction direction;
};

void printDroneInfo(struct Drone drone) {
    printf("Current height: %d\n", drone.height);
    printf("Current position: (%d, %d)\n", drone.x, drone.y);
    printf("Current speed: %d\n", drone.speed);
    char* dir;
    switch (drone.direction) {
        case UP:
            dir = "UP";
            break;
        case DOWN:
            dir = "DOWN";
            break;
        case LEFT:
            dir = "LEFT";
            break;
        case RIGHT:
            dir = "RIGHT";
            break;
        default:
            dir = "UNKNOWN";
            break;
    }
    printf("Current direction: %s\n", dir);
}

int main() {
    struct Drone drone = {0, 0, 0, 0, RIGHT};
    while (1) {
        printf("Enter a command (h)eight, (f)ly, (l)and, (s)top: ");
        char command;
        scanf("%c", &command);
        getchar(); // read in the newline character
        switch (command) {
            case 'h':
                printf("Enter the desired height (1 to %d): ", MAX_HEIGHT);
                int height;
                scanf("%d", &height);
                drone.height = height;
                break;
            case 'f':
                printf("Enter the desired speed (1 to %d): ", MAX_SPEED);
                int speed;
                scanf("%d", &speed);
                drone.speed = speed;
                printf("Enter the desired direction (u, d, l, r): ");
                char dir;
                scanf("%c", &dir);
                switch (dir) {
                    case 'u':
                        drone.direction = UP;
                        drone.y += drone.speed;
                        break;
                    case 'd':
                        drone.direction = DOWN;
                        drone.y -= drone.speed;
                        break;
                    case 'l':
                        drone.direction = LEFT;
                        drone.x -= drone.speed;
                        break;
                    case 'r':
                        drone.direction = RIGHT;
                        drone.x += drone.speed;
                        break;
                    default:
                        printf("Invalid direction. Please try again.\n");
                        break;
                }
                break;
            case 'l':
                printf("Landing...\n");
                drone.height = 0;
                break;
            case 's':
                printf("Stopping...\n");
                return 0;
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }
        printDroneInfo(drone);
    }
    return 0;
}