#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TIME 100

int main() {
    srand(time(NULL));
    int timer = rand() % (MAX_TIME + 1);

    // Simulate integer overflow by adding a large number
    timer += 2147483647; // INT_MAX

    printf("Timer value: %d\n", timer);

    return 0;
}
