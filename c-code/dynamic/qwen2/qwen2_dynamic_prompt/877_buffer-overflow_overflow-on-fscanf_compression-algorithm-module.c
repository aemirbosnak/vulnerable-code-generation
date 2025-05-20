#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void decompress(char *input) {
    char buffer[10];
    fscanf(input, "%s", buffer);
}

int main() {
    FILE *file = fopen("compressed.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char input[200];
    while (fgets(input, sizeof(input), file)) {
        decompress(input);
    }

    fclose(file);
    return 0;
}
