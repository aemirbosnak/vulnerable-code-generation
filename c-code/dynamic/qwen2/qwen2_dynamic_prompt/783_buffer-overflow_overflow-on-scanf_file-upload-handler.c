#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Enter filename: ");
    scanf("%s", buffer); // Vulnerability here
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fclose(file);
}

int main() {
    char input[20];
    printf("Welcome to the File Upload Handler\n");
    printf("Enter your command: ");
    scanf("%s", input);
    if (strcmp(input, "upload") == 0) {
        printf("Please specify a filename to upload.\n");
        handleFileUpload(NULL); // Deliberate use of NULL to trigger buffer overflow
    } else {
        printf("Unknown command.\n");
    }
    return 0;
}
