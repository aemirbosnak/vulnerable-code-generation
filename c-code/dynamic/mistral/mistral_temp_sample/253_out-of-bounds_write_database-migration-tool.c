#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

void migrate_data(char *source, char *destination) {
    FILE *src = fopen(source, "r");
    FILE *dst = fopen(destination, "w");

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, src)) {
        // Here is the intentional out-of-bounds write
        strcpy(buffer + strlen(buffer), "Excessive data");
        fputs(buffer, dst);
    }

    fclose(src);
    fclose(dst);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <destination_file>\n", argv[0]);
        return 1;
    }

    migrate_data(argv[1], argv[2]);
    return 0;
}
