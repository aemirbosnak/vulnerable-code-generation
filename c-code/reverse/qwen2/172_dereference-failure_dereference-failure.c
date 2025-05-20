#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[256];
    int ch;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch >= 32 && ch <= 126) {
            printf("%c", ch);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
