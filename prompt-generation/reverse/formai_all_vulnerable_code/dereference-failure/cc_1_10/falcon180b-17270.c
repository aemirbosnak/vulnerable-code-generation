//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char *name;
    unsigned char *data;
    size_t size;
} FileInfo;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    FileInfo file_info = {0};
    file_info.name = argv[1];
    file_info.data = malloc(MAX_FILE_SIZE);
    file_info.size = fread(file_info.data, 1, MAX_FILE_SIZE, fp);
    fclose(fp);

    if (file_info.size == 0) {
        printf("File is empty.\n");
        free(file_info.data);
        return 0;
    }

    unsigned char *buffer = malloc(file_info.size + 1);
    memcpy(buffer, file_info.data, file_info.size);
    buffer[file_info.size] = '\0';

    char *token = strtok(buffer, "\n");
    while (token!= NULL) {
        if (strlen(token) >= 2 && isalpha(token[0]) && isalpha(token[1])) {
            printf("Possible virus detected: %s\n", token);
        }
        token = strtok(NULL, "\n");
    }

    free(file_info.data);
    free(buffer);

    return 0;
}