#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char command[5];
    int speed;
    int direction;

    printf("Enter command (forward/backward): ");
    scanf("%s", command);
    printf("Enter speed (0-100): ");
    scanf("%d", &speed);
    printf("Enter direction (left/right): ");
    scanf("%s", command);

    if (strcmp(command, "forward") == 0) {
        printf("Moving forward at %d%% speed.\n", speed);
    } else if (strcmp(command, "backward") == 0) {
        printf("Moving backward at %d%% speed.\n", speed);
    } else {
        printf("Invalid command.\n");
    }

    return 0;
}
