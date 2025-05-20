#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(const char* filename) {
    char buffer[10];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open file\n");
        return;
    }
    while (!feof(file)) {
        fscanf(file, "%s", buffer);
        // Buffer overflow vulnerability here
        printf("%s\n", buffer);
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    handleFileUpload(argv[1]);
    return 0;
}
