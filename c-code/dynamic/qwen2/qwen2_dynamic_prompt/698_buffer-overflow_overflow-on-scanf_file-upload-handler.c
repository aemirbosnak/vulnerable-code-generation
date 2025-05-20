#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Uploading file: %s\n", filename);
    scanf("%s", buffer); // Vulnerability: No bounds checking
}

int main() {
    char filename[256];
    printf("Enter the filename to upload: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0'; // Remove newline character

    handleFileUpload(filename);

    return 0;
}
