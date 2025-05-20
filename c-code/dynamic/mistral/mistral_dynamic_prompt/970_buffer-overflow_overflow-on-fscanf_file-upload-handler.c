#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    char buffer[50];
    fscanf(file, "%s", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    read_file(argv[1]);
    printf("File contents: %s\n", argv[1]);
    return 0;
}
