#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define BUFFER_SIZE 8192

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    char *file_data;
    size_t len, file_size;

    if (argc != 3) {
        printf("Usage: %s <filename> <filesize>\n", argv[0]);
        return 1;
    }

    file_size = atoll(argv[2]);
    file_data = malloc(file_size);

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        free(file_data);
        return 1;
    }

    len = fread(file_data, 1, file_size, file);
    fclose(file);

    for (size_t i = 0; i < len; i += BUFFER_SIZE) {
        memcpy(buffer, &file_data[i], (len < BUFFER_SIZE ? len - i : BUFFER_SIZE));
        printf("%s", buffer); // Dereference failure possible here due to printf formatting
    }

    free(file_data);
    return 0;
}
