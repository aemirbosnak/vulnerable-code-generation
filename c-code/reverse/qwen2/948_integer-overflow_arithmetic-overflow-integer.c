#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int speed = 10;
    int direction = 90;
    int time = 5;

    int distance = speed * time;

    printf("Distance: %d\n", distance);

    return 0;
}
