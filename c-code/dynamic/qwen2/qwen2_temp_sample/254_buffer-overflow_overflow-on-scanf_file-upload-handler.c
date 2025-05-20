#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 256

void handleFileUpload() {
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the filename: ");
    scanf("%s", filename); // Vulnerable line - no length check
}

int main() {
    handleFileUpload();
    return 0;
}
