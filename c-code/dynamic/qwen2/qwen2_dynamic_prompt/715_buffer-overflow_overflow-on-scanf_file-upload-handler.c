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
    scanf("%s", buffer); // Vulnerability here
    printf("Hello, %s!\n", buffer);
}

int main() {
    char filename[256];
    printf("Welcome to the File Upload Handler\n");
    printf("Enter the file name to upload: ");
    scanf("%255s", filename); // Safe input handling
    handleFileUpload(filename);
    return 0;
}
