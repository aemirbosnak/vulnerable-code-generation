#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void handle_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[10];

    if (file == NULL) {
        printf("Failed to open file.\n");
        return;
    }

    size_t bytes_read = fread(buffer, sizeof(char), 10, file);
    if (bytes_read < 10) {
        printf("Premature end of file.\n");
    }

    // Dereference failure vulnerability: use buffer[10] without checking size
    char *data = (char *) malloc((unsigned int) buffer[9] + 1);
    fseek(file, ftell(file) - bytes_read, SEEK_SET);
    fread(data, 1, buffer[9], file);
    data[buffer[9]] = '\0';

    printf("Data read: %s\n", data);

    free(data);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    handle_file(argv[1]);
    return 0;
}
