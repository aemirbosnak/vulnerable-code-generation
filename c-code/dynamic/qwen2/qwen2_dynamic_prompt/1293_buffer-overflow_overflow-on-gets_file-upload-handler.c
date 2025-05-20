#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[100];
    printf("Uploading file: %s\n", filename);
    gets(buffer); // Vulnerable to buffer overflow
}

int main() {
    char filename[256];
    printf("Enter the filename to upload: ");
    fgets(filename, sizeof(filename), stdin);
    handleFileUpload(filename);
    return 0;
}
