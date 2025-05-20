//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

#define MAX_FILE_NAME_LEN 1024
#define MAX_FILE_SIZE 1024 * 1024 * 10

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    int file_size;
} FileInfo;

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <partition_device>\n", argv[0]);
        return 1;
    }

    int partition_device = open(argv[1], O_RDONLY);
    if (partition_device == -1) {
        printf("Error opening partition device: %s\n", strerror(errno));
        return 1;
    }

    printf("Scanning partition device...\n");
    FILE *file_list_file = fopen("file_list.txt", "w");
    if (file_list_file == NULL) {
        printf("Error creating file_list.txt: %s\n", strerror(errno));
        close(partition_device);
        return 1;
    }

    char buffer[MAX_FILE_NAME_LEN + 1] = {0};
    int file_count = 0;
    while (fgets(buffer, MAX_FILE_NAME_LEN, file_list_file)!= NULL) {
        FileInfo file_info;
        sscanf(buffer, "%s %d", file_info.file_name, &file_info.file_size);
        printf("Found file: %s (%d bytes)\n", file_info.file_name, file_info.file_size);
        file_count++;
    }

    if (file_count == 0) {
        printf("No files found.\n");
    } else {
        printf("%d files found.\n", file_count);
    }

    fclose(file_list_file);
    close(partition_device);
    return 0;
}