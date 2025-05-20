#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Enter file content: ");
    scanf("%s", buffer);
    printf("File content saved as %s\n", filename);
}

int main() {
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename);
    handleFileUpload(filename);
    return 0;
}
