#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload(char *filename) {
    char buffer[10];
    printf("Enter file content: ");
    scanf("%s", buffer); // Vulnerability here
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fprintf(file, "%s\n", buffer);
    fclose(file);
}

int main() {
    char filename[20];
    printf("Enter filename: ");
    scanf("%s", filename); // Potential buffer overflow here
    handleFileUpload(filename);
    return 0;
}
