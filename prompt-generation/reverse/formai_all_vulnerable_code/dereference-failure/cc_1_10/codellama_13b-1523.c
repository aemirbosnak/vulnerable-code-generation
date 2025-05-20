//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_FILES 10

struct file_system {
    int files[MAX_FILES];
    int num_files;
};

void initialize_file_system(struct file_system *fs) {
    fs->num_files = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i] = -1;
    }
}

int create_file(struct file_system *fs, char *file_name) {
    if (fs->num_files == MAX_FILES) {
        return -1;
    }
    int file_id = fs->num_files++;
    fs->files[file_id] = open(file_name, O_RDWR | O_CREAT, 0644);
    if (fs->files[file_id] == -1) {
        return -1;
    }
    return file_id;
}

int open_file(struct file_system *fs, char *file_name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(file_name, fs->files[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void close_file(struct file_system *fs, int file_id) {
    if (file_id < 0 || file_id >= fs->num_files) {
        return;
    }
    close(fs->files[file_id]);
    fs->files[file_id] = -1;
}

int read_file(struct file_system *fs, int file_id, char *buffer, int buffer_size) {
    if (file_id < 0 || file_id >= fs->num_files) {
        return -1;
    }
    int bytes_read = read(fs->files[file_id], buffer, buffer_size);
    if (bytes_read == -1) {
        return -1;
    }
    return bytes_read;
}

int write_file(struct file_system *fs, int file_id, char *buffer, int buffer_size) {
    if (file_id < 0 || file_id >= fs->num_files) {
        return -1;
    }
    int bytes_written = write(fs->files[file_id], buffer, buffer_size);
    if (bytes_written == -1) {
        return -1;
    }
    return bytes_written;
}

int main() {
    struct file_system fs;
    initialize_file_system(&fs);

    char buffer[BUFFER_SIZE];
    int file_id = create_file(&fs, "test.txt");
    write_file(&fs, file_id, "Hello, world!", strlen("Hello, world!"));
    close_file(&fs, file_id);

    file_id = open_file(&fs, "test.txt");
    read_file(&fs, file_id, buffer, BUFFER_SIZE);
    printf("Read from file: %s\n", buffer);
    close_file(&fs, file_id);

    return 0;
}