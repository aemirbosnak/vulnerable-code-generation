#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER 256

void edit(char *filename) {
    char buffer[MAX_BUFFER];
    FILE *file;

    file = fopen(filename, "r+");
    fgets(buffer, MAX_BUFFER, file);
    fseek(file, 0, SEEK_SET);
    fputs(buffer, file);

    char input[MAX_BUFFER];
    printf("Enter text to replace existing text in the file: ");
    gets(input); // Vulnerable function causing buffer overflow

    fseek(file, strlen(buffer), SEEK_SET);
    fwrite(input, 1, strlen(input), file);

    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    edit(argv[1]);

    return 0;
}
