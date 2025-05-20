#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char *filename) {
    FILE *file;
    char buffer[BUFFER_SIZE];

    if ((file = fopen(filename, "r")) == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    printf("Uploading file: %s...\n", filename);

    while (fgets(buffer, BUFFER_SIZE, file)) {
        printf("%s", buffer);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    char user_input[1024];

    if (argc != 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    printf("Enter the maximum size of the buffer (in bytes): ");
    scanf("%s", user_input);

    char *filename = malloc(strlen(argv[1]) + strlen(user_input) + 2);
    sprintf(filename, "%s%s%s", argv[1], ", size=", user_input);

    handle_file_upload(filename);

    free(filename);
    return 0;
}
