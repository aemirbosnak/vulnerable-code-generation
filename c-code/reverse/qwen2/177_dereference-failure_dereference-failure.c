#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char filename[256];
    FILE *file;
    int hasNonAscii = 0;

    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = '\0';

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch > 127) {
            hasNonAscii = 1;
            break;
        }
    }

    fclose(file);

    if (hasNonAscii) {
        printf("The file contains non-ASCII characters.\n");
    } else {
        printf("The file does not contain non-ASCII characters.\n");
    }

    return EXIT_SUCCESS;
}
