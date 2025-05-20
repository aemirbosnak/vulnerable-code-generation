//MISTRAL-7B DATASET v1.0 Category: Basic Unix-like Shell ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main() {
    char filename[1024];
    int ch;
    int total_words = 0;
    int words_on_line = 0;

    printf("I'm so grateful you're here!\n");
    printf("Please enter the filename: ");
    scanf("%s", filename);

    int file_fd = open(filename, O_RDONLY);
    if (file_fd < 0) {
        perror("Error opening file");
        return 1;
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) < 0) {
        perror("Error getting file status");
        close(file_fd);
        return 1;
    }

    char *file_buffer = malloc(file_stat.st_size);
    if (file_buffer == NULL) {
        perror("Error allocating memory for file buffer");
        close(file_fd);
        return 1;
    }

    ssize_t bytes_read = read(file_fd, file_buffer, file_stat.st_size);
    if (bytes_read < 0) {
        perror("Error reading file");
        free(file_buffer);
        close(file_fd);
        return 1;
    }

    char *line_start = file_buffer;
    while ((ch = *line_start++) != '\0') {
        if (ch == '\n') {
            words_on_line = 0;
            total_words += (line_start - file_buffer) / sizeof(char) - 1;
            line_start = file_buffer;
        } else if (ch == ' ' || ch == '\t') {
            words_on_line++;
        }
    }

    total_words += (line_start - file_buffer) / sizeof(char);

    printf("The file '%s' contains %d words.\n", filename, total_words);

    free(file_buffer);
    close(file_fd);

    return 0;
}