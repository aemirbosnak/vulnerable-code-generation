#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_image(char *filename) {
    char buffer[10];
    char data[1024];
    FILE *file = fopen(filename, "r");

    fread(data, 1, 1024, file);
    strcpy(buffer, data);
    gets(buffer); // Bounds violation
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);
    printf("Processed image.\n");
    return 0;
}
