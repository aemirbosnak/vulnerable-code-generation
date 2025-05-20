#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    char buffer[1024];
    while (fgets(buffer, sizeof(buffer), file)) {
        // Simulate processing the file content
    }
    fclose(file);

    // Dereference a null pointer
    int *ptr = NULL;
    printf("%d\n", *ptr); // This will cause a segmentation fault
}

int main() {
    char filename[] = "example.txt";
    handleFileUpload(filename);
    return 0;
}
