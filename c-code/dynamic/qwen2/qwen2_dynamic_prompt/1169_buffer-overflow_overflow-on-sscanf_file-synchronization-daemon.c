#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void handle_file_sync(char *input) {
    char buffer[MAX_BUFFER_SIZE];
    if (sscanf(input, "%s", buffer) != 1) {
        fprintf(stderr, "Error parsing input\n");
        return;
    }
    printf("Syncing file: %s\n", buffer);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    handle_file_sync(argv[1]);

    return 0;
}
