//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 4096

typedef struct file_header {
    char magic[4];
    int version;
    int num_files;
} file_header_t;

typedef struct file_entry {
    char name[256];
    int size;
    int offset;
} file_entry_t;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    int img_fd = open(argv[1], O_RDONLY);
    if (img_fd == -1) {
        printf("Error opening image file: %s\n", strerror(errno));
        return 1;
    }

    struct stat st;
    if (fstat(img_fd, &st) == -1) {
        printf("Error getting image file status: %s\n", strerror(errno));
        close(img_fd);
        return 1;
    }

    char *img_data = malloc(st.st_size);
    if (img_data == NULL) {
        printf("Error allocating memory for image data\n");
        close(img_fd);
        return 1;
    }

    if (read(img_fd, img_data, st.st_size)!= st.st_size) {
        printf("Error reading image file: %s\n", strerror(errno));
        free(img_data);
        close(img_fd);
        return 1;
    }

    file_header_t *header = (file_header_t *) img_data;
    if (memcmp(header->magic, "IMG2", 4)!= 0) {
        printf("Invalid image file format\n");
        free(img_data);
        close(img_fd);
        return 1;
    }

    int num_files = header->num_files;
    file_entry_t *entries = (file_entry_t *) (img_data + sizeof(file_header_t));

    for (int i = 0; i < num_files; i++) {
        printf("File %d: %s (%d bytes)\n", i+1, entries[i].name, entries[i].size);
    }

    free(img_data);
    close(img_fd);

    return 0;
}