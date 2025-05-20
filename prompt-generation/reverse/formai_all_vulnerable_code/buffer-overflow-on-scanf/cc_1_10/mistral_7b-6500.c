//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 256
#define MAX_FILE_NAME_LENGTH 1024

void check_memory_allocation(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void print_array(int arr[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void read_file(const char *filename, char *buffer, size_t size) {
    int file_fd;
    size_t read_bytes;

    check_memory_allocation(buffer);

    file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    read_bytes = read(file_fd, buffer, size - 1);
    if (read_bytes < 0) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    buffer[read_bytes] = '\0';
    close(file_fd);
}

void print_string_reversed(const char *str) {
    int length = strlen(str);
    int i;

    for (i = length - 1; i >= 0; i--) {
        putchar(str[i]);
    }
}

void print_file_content_reversed(const char *filename) {
    char buffer[MAX_LINE_LENGTH];

    read_file(filename, buffer, MAX_LINE_LENGTH);

    printf("Content of %s:\n", filename);
    print_string_reversed(buffer);
    printf("\n");
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    print_array(numbers, size);

    char filename[MAX_FILE_NAME_LENGTH];

    printf("Enter file name: ");
    scanf("%s", filename);

    print_file_content_reversed(filename);

    return EXIT_SUCCESS;
}