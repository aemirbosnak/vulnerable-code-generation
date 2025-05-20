#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Uploading file: %s\n", filename);
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char inputFilename[256];
    printf("Enter the filename to upload: ");
    fgets(inputFilename, sizeof(inputFilename), stdin);
    inputFilename[strcspn(inputFilename, "\n")] = '\0';
    handleFileUpload(inputFilename);
    return 0;
}
