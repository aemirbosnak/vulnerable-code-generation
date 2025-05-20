#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void handle_file_upload(char* filename) {
    FILE* file = fopen(filename, "r");
    char buffer[BUFFER_SIZE];
    char* content = NULL;
    size_t len = 0;
    size_t bytes_read;

    if (!file) {
        printf("Error: unable to open file.\n");
        return;
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        if (len + bytes_read > BUFFER_SIZE) {
            printf("Error: input file is too large.\n");
            fclose(file);
            free(content);
            return;
        }

        if (len) {
            content = realloc(content, len + bytes_read);
            strcpy(content + len, buffer);
            len += bytes_read;
        } else {
            content = malloc(bytes_read);
            memcpy(content, buffer, bytes_read);
        }
    }

    fclose(file);
    content[len] = '\0';

    // OUT OF BOUNDS WRITE VULNERABILITY BELOW ---------------
    char secret[10] = "SECRET";
    strcpy(secret + 5, content);  // writing more than the size of 'secret' array
    // ------------------------------------------------------

    printf("File uploaded and processed successfully.\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./file_upload_handler <filename>\n");
        return 1;
    }

    handle_file_upload(argv[1]);

    return 0;
}
