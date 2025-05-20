#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
    FILE *file;
    char buffer[BUFFER_SIZE];
    int i, j, k;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    i = 0;
    while ((fgets(buffer, BUFFER_SIZE, file)) != NULL) {
        for (j = 0; buffer[j]; ++j) {
            if (buffer[j] == '\n') {
                for (k = 0; k < j; ++k) {
                    if (buffer[k] == '\r') {
                        buffer[k] = '\0';
                        break;
                    }
                }
                printf("%s", &buffer[0]);
                i++;
                continue;
            }
        }
    }

    fclose(file);
    return 0;
}
