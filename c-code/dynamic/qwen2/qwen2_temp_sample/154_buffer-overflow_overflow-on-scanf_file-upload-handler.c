#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void handleFileUpload(char *filename) {
    char buffer[256];
    printf("Uploading file: %s\n", filename);
    printf("Enter file content (max 255 characters): ");
    scanf("%255s", buffer); // Vulnerable to buffer overflow
    printf("File uploaded successfully.\n");
}

int main() {
    char filename[100];
    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
    handleFileUpload(filename);
    return 0;
}
