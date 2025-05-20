#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int *img_data = NULL;
    img_data = (int *)malloc(10 * sizeof(int));

    // Use after free vulnerability
    free(img_data);
    img_data[0] = 10;

    return 0;
}
