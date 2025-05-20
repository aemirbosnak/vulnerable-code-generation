#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[256];
    char ch;

    printf("Enter the filename: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch != ' ' && ch != '\n' && ch != '\0') {
            putchar(ch);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}
