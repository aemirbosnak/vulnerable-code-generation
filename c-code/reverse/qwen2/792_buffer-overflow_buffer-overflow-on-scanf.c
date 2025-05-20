#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int command;
    printf("Enter joystick command (0-9): ");
    scanf("%d", &command);

    switch(command) {
        case 0: printf("Stop\n"); break;
        case 1: printf("Forward\n"); break;
        case 2: printf("Backward\n"); break;
        case 3: printf("Left\n"); break;
        case 4: printf("Right\n"); break;
        case 5: printf("Speed Up\n"); break;
        case 6: printf("Slow Down\n"); break;
        case 7: printf("Turn On Lights\n"); break;
        case 8: printf("Turn Off Lights\n"); break;
        case 9: printf("Emergency Stop\n"); break;
        default: printf("Invalid Command\n"); break;
    }

    return 0;
}
