#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024

void edit_text(char *file_name) {
    FILE *file = fopen(file_name, "a+");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        fputs(buffer, file);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    char *file_name = argv[1];

    // Simulate a text editing session
    printf("Entering text editor mode. Press Ctrl+D to end input.\n");

    edit_text(file_name);

    printf("Text saved to %s\n", file_name);
    return 0;
}
