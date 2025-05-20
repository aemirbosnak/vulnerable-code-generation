#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void process_image(char *filename, char *filter) {
    FILE *file = fopen(filename, "r");
    char buffer[10];
    int count = 0;

    while (fscanf(file, "%s", buffer) != EOF) {
        count += strlen(buffer) * strlen(filter);
        strcpy(buffer, buffer + strlen(filter) - strlen(buffer));
        strcat(buffer, filter);
    }

    fclose(file);
    printf("Processed image saved to output.txt\n");
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: filter input_image.bin filter.txt\n");
        return 1;
    }

    process_image(argv[1], argv[2]);
    return 0;
}
