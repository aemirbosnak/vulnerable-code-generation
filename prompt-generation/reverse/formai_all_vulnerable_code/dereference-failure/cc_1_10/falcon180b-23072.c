//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_FILE_SIZE (1024 * 1024 * 10) // 10MB

typedef struct {
    char *name;
    unsigned int size;
    char *data;
} file_t;

void read_file(file_t *file) {
    int fd = open(file->name, O_RDONLY);

    if (fd == -1) {
        printf("Error opening file: %s\n", file->name);
        exit(1);
    }

    file->size = lseek(fd, 0, SEEK_END);

    if (file->size > MAX_FILE_SIZE) {
        printf("File too large: %s\n", file->name);
        exit(1);
    }

    file->data = malloc(file->size);

    if (file->data == NULL) {
        printf("Error allocating memory for file: %s\n", file->name);
        exit(1);
    }

    if (read(fd, file->data, file->size)!= file->size) {
        printf("Error reading file: %s\n", file->name);
        exit(1);
    }

    close(fd);
}

int is_virus(file_t *file) {
    const char *viruses[] = {
        "virus1",
        "virus2",
        "virus3"
    };

    int i;

    for (i = 0; i < sizeof(viruses) / sizeof(viruses[0]); i++) {
        if (strstr(file->data, viruses[i])!= NULL) {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    file_t file;
    file.name = argv[1];
    read_file(&file);

    if (is_virus(&file)) {
        printf("Virus detected in file: %s\n", file.name);
    } else {
        printf("File is clean: %s\n", file.name);
    }

    free(file.data);
    return 0;
}