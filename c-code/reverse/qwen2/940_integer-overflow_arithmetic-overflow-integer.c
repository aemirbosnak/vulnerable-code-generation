#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int speed = 10;
    int time = 214748364; // Close to INT_MAX
    int distance;

    distance = speed * time; // Intentional integer overflow

    printf("Distance: %d\n", distance);

    return 0;
}
