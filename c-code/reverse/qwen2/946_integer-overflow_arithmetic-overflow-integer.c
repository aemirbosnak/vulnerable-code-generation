#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int speed = 5;
    int time = 2147483647; // Maximum value for signed int on most systems
    long distance;

    distance = (long)speed * time; // Potential overflow here

    printf("Distance: %ld\n", distance);

    return 0;
}
