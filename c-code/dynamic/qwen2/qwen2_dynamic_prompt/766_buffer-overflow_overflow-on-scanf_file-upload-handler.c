#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Uploading file: %s\n", filename);
    scanf("%9s", buffer); // Vulnerable to buffer overflow
}

int main() {
    char filename[256];
    printf("Enter file name: ");
    fgets(filename, sizeof(filename), stdin);
    handleFileUpload(filename);
    return 0;
}
