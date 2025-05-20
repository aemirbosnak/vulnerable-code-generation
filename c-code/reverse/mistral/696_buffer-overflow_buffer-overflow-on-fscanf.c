#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int word_count[256] = {0};

    if (argc != 2) {
        printf("Usage: %s <log_file>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 2;
    }

    while (fgets(buffer, BUFFER_SIZE, file)) {
        sscanf(buffer, "%s", buffer);
        word_count[(unsigned char)buffer[0]]++;
    }

    for (int i = 0; i < 256; ++i) {
        if (word_count[i]) {
            printf("%c: %d\n", i, word_count[i]);
        }
    }

    fclose(file);
    return 0;
}
