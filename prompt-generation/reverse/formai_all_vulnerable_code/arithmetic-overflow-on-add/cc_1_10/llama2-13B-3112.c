//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MAX_LINE_LENGTH 1024

// Declare a structure to store the file metadata
struct file_metadata {
    char name[50];
    size_t size;
    time_t mod_time;
};

// Function to read the file metadata
struct file_metadata read_file_metadata(const char *path) {
    struct file_metadata metadata;
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", path);
        return metadata;
    }

    // Read the file name
    fgets(metadata.name, sizeof(metadata.name), file);
    metadata.name[strcspn(metadata.name, "\n")] = 0;

    // Read the file size
    long file_size = ftell(file);
    if (file_size < 0) {
        printf("Error: Unable to determine file size\n");
        return metadata;
    }
    metadata.size = file_size;

    // Read the modification time
    struct tm *tm = localtime(&metadata.mod_time);
    char buffer[32];
    fgets(buffer, sizeof(buffer), file);
    strptime(buffer, "%Y-%m-%d %H:%M:%S", tm);
    metadata.mod_time = mktime(tm);

    fclose(file);
    return metadata;
}

// Function to write the file metadata
void write_file_metadata(const char *path, const struct file_metadata *metadata) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", path);
        return;
    }

    fprintf(file, "%s\n", metadata->name);
    fprintf(file, "%lu\n", (unsigned long)metadata->size);
    fprintf(file, "%s\n", ctime(&metadata->mod_time));

    fclose(file);
}

int main() {
    // Create some files and directories
    char files[3][50] = {"file1.txt", "file2.txt", "file3.txt"};
    char dirs[3][50] = {"dir1", "dir2", "dir3"};

    // Create the files and directories
    for (int i = 0; i < 3; i++) {
        if (mkdir(dirs[i], 0755) != 0) {
            perror("mkdir");
            return 1;
        }
        if (creat(files[i], 0644) != 0) {
            perror("creat");
            return 1;
        }
    }

    // Read the file metadata
    struct file_metadata metadata;
    for (int i = 0; i < 3; i++) {
        metadata = read_file_metadata(files[i]);
        printf("File %s has size %lu and was modified on %s\n", files[i], metadata.size, ctime(&metadata.mod_time));
    }

    // Modify the file metadata
    for (int i = 0; i < 3; i++) {
        metadata = read_file_metadata(files[i]);
        metadata.size *= 2;
        metadata.mod_time = time(NULL) + 10;
        write_file_metadata(files[i], &metadata);
    }

    // Reread the file metadata
    for (int i = 0; i < 3; i++) {
        metadata = read_file_metadata(files[i]);
        printf("File %s has size %lu and was modified on %s\n", files[i], metadata.size, ctime(&metadata.mod_time));
    }

    return 0;
}