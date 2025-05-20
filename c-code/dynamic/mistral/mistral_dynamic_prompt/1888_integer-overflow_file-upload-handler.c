#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 4096

int main(int argc, char *argv[]) {
    char buffer[MAX_SIZE];
    FILE *file;
    char filename[256];

    if (argc < 3) {
        printf("Usage: %s <username> <file>\n", argv[0]);
        return 1;
    }

    strcpy(filename, argv[2]);
    file = fopen(filename, "w");

    fgets(buffer, sizeof(buffer), stdin);
    fwrite(buffer, strlen(buffer), 1, file);

    printf("File written successfully.\n");
    fclose(file);

    return 0;
}
