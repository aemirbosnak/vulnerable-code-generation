//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 4096
#define MAX_FILE_NAME_LEN 256
#define MAX_FILE_SIZE (1024*1024*1024) // 1 GB

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    int size;
} FileInfo;

void print_file_info(FileInfo* file_info) {
    printf("File name: %s\n", file_info->name);
    printf("File size: %d bytes\n", file_info->size);
}

int is_file_name_valid(char* name) {
    int valid = 1;
    int name_len = strlen(name);
    if (name_len == 0) {
        valid = 0;
    } else {
        for (int i = 0; i < name_len; i++) {
            if (!isalpha(name[i])) {
                valid = 0;
                break;
            }
        }
    }
    return valid;
}

int is_file_size_valid(int size) {
    return size >= 0 && size <= MAX_FILE_SIZE;
}

int is_file_recoverable(char* file_name, int size) {
    return is_file_name_valid(file_name) && is_file_size_valid(size);
}

void recover_file(char* file_name, int size) {
    char buffer[BUF_SIZE];
    FILE* input_file = fopen(file_name, "rb");
    FILE* output_file = fopen("recovered_file.txt", "wb");
    if (input_file == NULL || output_file == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }
    int bytes_read = 0;
    while ((bytes_read = fread(buffer, 1, BUF_SIZE, input_file)) > 0) {
        if (fwrite(buffer, 1, bytes_read, output_file)!= bytes_read) {
            printf("Error: could not write to file.\n");
            exit(1);
        }
    }
    if (ferror(input_file)) {
        printf("Error: could not read from file.\n");
        exit(1);
    }
    if (fclose(input_file)!= 0 || fclose(output_file)!= 0) {
        printf("Error: could not close file.\n");
        exit(1);
    }
    printf("File successfully recovered.\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file_name> <file_size>\n", argv[0]);
        exit(1);
    }
    char* file_name = argv[1];
    int size = atoi(argv[2]);
    if (!is_file_recoverable(file_name, size)) {
        printf("Error: invalid file name or size.\n");
        exit(1);
    }
    recover_file(file_name, size);
    return 0;
}