//Code Llama-13B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PATH_LENGTH 1024

typedef struct {
    char source[MAX_PATH_LENGTH];
    char dest[MAX_PATH_LENGTH];
} file_pair_t;

void copy_file(const char* source, const char* dest) {
    FILE* src = fopen(source, "r");
    FILE* dst = fopen(dest, "w");
    if (!src || !dst) {
        fprintf(stderr, "Error opening file: %s\n", source);
        return;
    }
    char buffer[BUFFER_SIZE];
    size_t n;
    while ((n = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        fwrite(buffer, 1, n, dst);
    }
    fclose(src);
    fclose(dst);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s source_dir dest_dir\n", argv[0]);
        return 1;
    }
    DIR* dir = opendir(argv[1]);
    if (!dir) {
        fprintf(stderr, "Error opening directory: %s\n", argv[1]);
        return 1;
    }
    file_pair_t* file_pairs = malloc(sizeof(file_pair_t) * 1024);
    if (!file_pairs) {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }
    int i = 0;
    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            snprintf(file_pairs[i].source, MAX_PATH_LENGTH, "%s/%s", argv[1], entry->d_name);
            snprintf(file_pairs[i].dest, MAX_PATH_LENGTH, "%s/%s", argv[2], entry->d_name);
            i++;
        }
    }
    closedir(dir);
    for (int j = 0; j < i; j++) {
        copy_file(file_pairs[j].source, file_pairs[j].dest);
    }
    free(file_pairs);
    return 0;
}