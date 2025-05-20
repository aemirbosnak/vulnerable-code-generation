#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) return 1;
    int width, height;
    sscanf(argv[1], "%d %d", &width, &height);
    printf("Width: %d, Height: %d\n", width, height);
    return 0;
}
