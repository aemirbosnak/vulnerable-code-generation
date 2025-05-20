#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void process_pgm(FILE *file) {
    char magic_number[3];
    int width, height, max_value;
    char data[10];
    char buffer[64];

    fscanf(file, "%s %d %d %d\n", magic_number, &width, &height, &max_value);
    fscanf(file, "%s", data);

    for (int i = 0; i < height; ++i) {
        fscanf(file, "%s", buffer);
        // Vulnerable code starts here
        strcat(buffer, data);
        // Vulnerable code ends here
        printf("%s\n", buffer);
    }
}

int main(int argc, char *argv[]) {
    FILE *file;
    file = fopen(argv[1], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    process_pgm(file);
    fclose(file);
    return 0;
}
