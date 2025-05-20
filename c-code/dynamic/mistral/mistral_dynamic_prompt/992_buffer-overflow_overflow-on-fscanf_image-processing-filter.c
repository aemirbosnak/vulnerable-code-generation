#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100
#define FILTER_SIZE 10

void applyFilter(char *image, int *filter) {
    int i, j, k;
    for (i = 0; i < 3; ++i) {
        for (j = 0; j < 3; ++j) {
            k = i * 3 + j;
            image[k] += filter[k];
        }
    }
}

int main(int argc, char *argv[]) {
    char image[BUFFER_SIZE];
    int filter[FILTER_SIZE] = {1, 2, 1, 2, 4, 2, 1, 2, 1};

    if (argc < 2) {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    fscanf(stdout, "%s", image);
    applyFilter(image, filter);
    printf("Filtered image:\n%s\n", image);
    return 0;
}
