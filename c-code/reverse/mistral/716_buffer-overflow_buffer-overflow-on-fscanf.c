#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

int main() {
    char filename[MAX_LENGTH];
    printf("Enter PGM image file name: ");
    fgets(filename, MAX_LENGTH, stdin);

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    int width, height, max_value;
    fscanf(file, "P5\n%d %d\n%d\n", &width, &height, &max_value);

    // Process the image data here...

    fclose(file);
    return 0;
}
