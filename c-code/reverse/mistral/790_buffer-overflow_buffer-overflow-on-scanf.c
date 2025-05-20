#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 10

void moveVehicle(int x, int y) {
    switch(x) {
        case 1:
            printf("Forward\n");
            break;
        case 2:
            printf("Backward\n");
            break;
        case 3:
            printf("Left\n");
            break;
        case 4:
            printf("Right\n");
            break;
        case 5:
            printf("Fast Forward\n");
            break;
        case 6:
            printf("Fast Backward\n");
            break;
        case 7:
            printf("Fast Left\n");
            break;
        case 8:
            printf("Fast Right\n");
            break;
        case 9:
            printf("Spin Left\n");
            break;
        case 10:
            printf("Spin Right\n");
            break;
        default:
            printf("Invalid Input\n");
    }

    if(y > 0)
        printf("Increase Speed\n");
    else if(y < 0)
        printf("Decrease Speed\n");
}

int main() {
    char input[MAX_INPUT];
    scanf("%s", input);
    int x = atoi(input);
    int y;
    scanf("%d", &y);
    moveVehicle(x, y);
    return 0;
}
