#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

void handle_file_sync(char *input) {
    char buffer[MAX_BUFFER_SIZE];
    if (sscanf(input, "%s", buffer) == 1) {
        printf("File to sync: %s\n", buffer);
        // Simulate file syncing process
        sleep(1);
    } else {
        fprintf(stderr, "Error parsing input.\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    handle_file_sync(argv[1]);

    return EXIT_SUCCESS;
}
