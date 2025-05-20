//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_FILE_SIZE (1024*1024*1024) // 1 GB

typedef struct {
    char *filename;
    FILE *file;
    char *buffer;
    size_t size;
} File;

void read_file(File *file) {
    file->buffer = malloc(MAX_FILE_SIZE);
    if (file->buffer == NULL) {
        printf("Error: Could not allocate memory for buffer.\n");
        exit(1);
    }
    file->size = 0;
    fseek(file->file, 0, SEEK_SET);
    while (fread(file->buffer + file->size, 1, 1, file->file) == 1) {
        file->size++;
    }
    rewind(file->file);
}

void write_file(File *file) {
    fseek(file->file, 0, SEEK_SET);
    fwrite(file->buffer, 1, file->size, file->file);
}

int main() {
    char *filename = "romantic_data.txt";
    File file = {
       .filename = filename,
       .file = fopen(filename, "r+b"),
       .buffer = NULL,
       .size = 0
    };

    if (file.file == NULL) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    read_file(&file);

    char *search_word = "romance";
    char *replace_word = "love";

    char *found_word = strstr(file.buffer, search_word);
    while (found_word!= NULL) {
        strncpy(found_word, replace_word, strlen(replace_word));
        found_word += strlen(replace_word);
        found_word = strstr(found_word, search_word);
    }

    write_file(&file);
    printf("Data recovery completed successfully.\n");

    fclose(file.file);
    free(file.buffer);
    return 0;
}