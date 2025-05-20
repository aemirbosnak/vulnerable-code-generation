#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void unsafe_add(int *a, int *b, int *c) {
    int max_size = 1000000;
    int buffer[max_size];
    memcpy(buffer, a, sizeof(int) * max_size);
    memcpy(buffer + max_size - *b, b, sizeof(int));
    *c = buffer[max_size - 1];
}

int main(int argc, char *argv[]) {
    int a, b, c;

    if (argc != 4) {
        printf("Usage: %s <large_a> <large_b> <output>\n", argv[0]);
        return 1;
    }

    a = atoi(argv[1]);
    b = atoi(argv[2]);

    if (a > 2147483647 || b > 2147483647) {
        printf("Input values too large.\n");
        return 1;
    }

    unsafe_add(&a, &b, &c);
    printf("Result: %d\n", c);

    return 0;
}
