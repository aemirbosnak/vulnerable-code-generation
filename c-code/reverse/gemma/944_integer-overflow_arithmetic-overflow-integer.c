#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int distance = 0;
    int speed = 0;
    int direction = 0;

    printf("Enter distance: ");
    scanf("%d", &distance);

    // Integer overflow vulnerability
    distance = distance * 2;

    printf("Enter speed: ");
    scanf("%d", &speed);

    direction = speed * distance;

    printf("Vehicle is moving: distance %d, speed %d, direction %d\n", distance, speed, direction);

    return 0;
}
