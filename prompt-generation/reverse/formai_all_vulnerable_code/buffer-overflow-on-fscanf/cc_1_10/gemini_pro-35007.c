//GEMINI-pro DATASET v1.0 Category: Data recovery tool ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct file_entry_s {
    char* name;
    size_t size;
    char* data;
} file_entry_t;

typedef struct file_system_s {
    size_t num_files;
    file_entry_t* files;
} file_system_t;

static bool read_file_system(file_system_t* fs, const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        return false;
    }

    fscanf(fp, "%zu\n", &fs->num_files);
    fs->files = malloc(sizeof(file_entry_t) * fs->num_files);
    for (size_t i = 0; i < fs->num_files; i++) {
        fscanf(fp, "%s %zu\n", fs->files[i].name, &fs->files[i].size);
        fs->files[i].data = malloc(fs->files[i].size);
        fread(fs->files[i].data, fs->files[i].size, 1, fp);
    }

    fclose(fp);
    return true;
}

static void write_file_system(const file_system_t* fs, const char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        return;
    }

    fprintf(fp, "%zu\n", fs->num_files);
    for (size_t i = 0; i < fs->num_files; i++) {
        fprintf(fp, "%s %zu\n", fs->files[i].name, fs->files[i].size);
        fwrite(fs->files[i].data, fs->files[i].size, 1, fp);
    }

    fclose(fp);
}

static void print_file_system(const file_system_t* fs) {
    for (size_t i = 0; i < fs->num_files; i++) {
        printf("%s (%zu bytes)\n", fs->files[i].name, fs->files[i].size);
    }
}

static void free_file_system(file_system_t* fs) {
    for (size_t i = 0; i < fs->num_files; i++) {
        free(fs->files[i].name);
        free(fs->files[i].data);
    }
    free(fs->files);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    file_system_t fs;
    if (!read_file_system(&fs, argv[1])) {
        printf("Error reading file system from %s\n", argv[1]);
        return 1;
    }

    print_file_system(&fs);

    write_file_system(&fs, argv[2]);

    free_file_system(&fs);

    return 0;
}