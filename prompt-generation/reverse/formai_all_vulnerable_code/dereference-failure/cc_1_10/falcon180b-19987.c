//Falcon-180B DATASET v1.0 Category: Error handling ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define ERR_OK 0
#define ERR_MALLOC_FAILURE 1
#define ERR_FILE_NOT_FOUND 2
#define ERR_FILE_READ_FAILURE 3
#define ERR_INVALID_ARGUMENT 4
#define ERR_INVALID_OPERATION 5
#define ERR_UNKNOWN 6

typedef struct {
    int code;
    char *message;
} error_t;

static error_t *last_error = NULL;

void set_last_error(int code, char *message) {
    last_error = malloc(sizeof(error_t));
    last_error->code = code;
    last_error->message = strdup(message);
}

error_t *get_last_error() {
    return last_error;
}

void free_last_error() {
    if (last_error!= NULL) {
        free(last_error->message);
        free(last_error);
        last_error = NULL;
    }
}

int main() {
    char *filename = "nonexistent_file.txt";
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        set_last_error(ERR_FILE_NOT_FOUND, "File not found");
        return ERR_FILE_NOT_FOUND;
    }
    
    char buffer[100];
    size_t bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file);
    
    if (bytes_read <= 0) {
        set_last_error(ERR_FILE_READ_FAILURE, "Failed to read file");
        return ERR_FILE_READ_FAILURE;
    }
    
    printf("File content: %s\n", buffer);
    
    fclose(file);
    return ERR_OK;
}