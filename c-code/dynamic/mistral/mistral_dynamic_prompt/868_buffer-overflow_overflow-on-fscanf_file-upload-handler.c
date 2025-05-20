#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_upload(char* filename) {
    FILE *file = fopen(filename, "r");
    char buffer[10];
    fscanf(file, "%s", buffer);
    printf("File contents: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    handle_upload(argv[1]);

    return 0;
}
