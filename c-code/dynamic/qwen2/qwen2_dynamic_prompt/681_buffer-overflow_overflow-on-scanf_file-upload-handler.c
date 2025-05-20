#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Uploading file: %s\n", filename);
    printf("Enter your name: ");
    scanf("%9s", buffer); // Vulnerable to buffer overflow
    printf("Hello, %s!\n", buffer);
}

int main() {
    char filename[256];
    printf("Welcome to the File Upload Handler\n");
    printf("Enter the file name to upload: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character
    handleFileUpload(filename);
    return 0;
}
