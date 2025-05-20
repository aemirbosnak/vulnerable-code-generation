#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void migrateData(const char* filename) {
    FILE *file;
    char destination[10];
    
    file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file.\n");
        return;
    }
    
    while (!feof(file)) {
        // This loop reads from the file until EOF is reached
        fscanf(file, "%s", destination);
        // The vulnerability lies here: no size check on fgets destination
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    migrateData(argv[1]);
    
    return 0;
}
