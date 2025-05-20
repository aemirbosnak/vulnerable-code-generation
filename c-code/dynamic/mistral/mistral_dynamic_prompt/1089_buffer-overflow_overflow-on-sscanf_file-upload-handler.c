#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LEN 256
#define BUFFER_SIZE 1024

void handle_upload(char* file_name) {
    FILE* fp;
    char buffer[BUFFER_SIZE];

    fp = fopen(file_name, "r");
    if (!fp) {
        fprintf(stderr, "Failed to open file: %s\n", file_name);
        return;
    }

    size_t chars_read;
    while ((chars_read = fread(buffer, sizeof(char), BUFFER_SIZE, fp)) > 0) {
        sscanf(buffer, "%*s %n", NULL);
        // The %n in the sscanf function causes a buffer overflow if the input string contains more than BUFFER_SIZE characters.
    }

    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_to_upload>\n", argv[0]);
        return 1;
    }

    char file_name[MAX_FILE_NAME_LEN];
    strcpy(file_name, argv[1]);

    handle_upload(file_name);

    return 0;
}
