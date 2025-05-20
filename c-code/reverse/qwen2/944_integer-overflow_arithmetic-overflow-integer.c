#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int speed = 10;
    int time = 2147483647; // Maximum value for int on most systems
    long long distance = (long long)speed * time;

    printf("Distance: %lld\n", distance);

    return 0;
}
