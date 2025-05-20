#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char filename[10];
    FILE *file;
    int width, height, maxval;

    printf("Enter PGM file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fscanf(file, "%*s %d %d %d", &width, &height, &maxval);
    fclose(file);

    printf("Width: %d\nHeight: %d\nMax value: %d\n", width, height, maxval);

    return 0;
}
