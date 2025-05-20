#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void process_level(int level) {
    int max_level = 100;
    if (level > max_level) {
        printf("Congratulations! You've reached the maximum level.\n");
    } else {
        printf("Level: %d\n", level);
    }
}

int main() {
    int current_level = 90;
    int increment = 20;

    // Integer overflow vulnerability
    current_level += increment;

    process_level(current_level);

    return 0;
}
