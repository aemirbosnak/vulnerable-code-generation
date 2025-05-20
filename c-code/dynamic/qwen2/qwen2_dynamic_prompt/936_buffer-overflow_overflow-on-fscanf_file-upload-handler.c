#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void handleFileUpload() {
    char filename[16];
    char content[256];

    printf("Enter filename: ");
    fscanf(stdin, "%s", filename);

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("Enter file content: ");
    fscanf(stdin, "%s", content);

    fprintf(file, "%s", content);
    fclose(file);
}

int main() {
    handleFileUpload();
    return 0;
}
