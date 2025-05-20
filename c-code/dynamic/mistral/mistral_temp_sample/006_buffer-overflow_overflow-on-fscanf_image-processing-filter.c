#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_image(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    char command[10];

    while (fgets(buffer, BUFFER_SIZE, file)) {
        sscanf(buffer, "%s", command);
        if (strcmp(command, "filter1") == 0) {
            // Implement filter 1 here
        } else if (strcmp(command, "filter2") == 0) {
            // Implement filter 2 here
        } else if (strcmp(command, "quit") == 0) {
            break;
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    process_image(argv[1]);

    return 0;
}
