//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_FILE_SIZE 1024 * 1024
#define BUFFER_SIZE 1024

void replace_sorry(char *buffer, int *position) {
    int len_sorry = strlen("sorry");
    int len_replacement = strlen("I borked it good and proper!");

    if (*position + len_sorry <= BUFFER_SIZE) {
        if (strncmp(buffer + *position, "sorry", len_sorry) == 0) {
            memmove(buffer + *position + len_replacement, buffer + *position, len_sorry);
            memcpy(buffer + *position, "I borked it good and proper!", len_replacement);
            *position += len_replacement;
        } else {
            (*position)++;
        }
    } else {
        char *new_buffer = (char *) realloc(buffer, (*position) + len_replacement + 1);
        if (new_buffer == NULL) {
            fprintf(stderr, "Memory allocation failed!\n");
            exit(EXIT_FAILURE);
        }
        replace_sorry(new_buffer, position);
    }
}

int main(int argc, char **argv) {
    int fd, ret;
    char *file_content = NULL;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    fstat(fd, &file_stat);
    file_content = (char *) malloc(file_stat.st_size + 1);
    if (file_content == NULL) {
        perror("Memory allocation failed!");
        close(fd);
        exit(EXIT_FAILURE);
    }

    ssize_t read_bytes = read(fd, file_content, file_stat.st_size);
    if (read_bytes < 0) {
        perror("Error reading file");
        free(file_content);
        close(fd);
        exit(EXIT_FAILURE);
    }

    int position = 0;
    replace_sorry(file_content, &position);

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Error creating output file");
        free(file_content);
        exit(EXIT_FAILURE);
    }

    ret = write(fd, file_content, position);
    if (ret < 0) {
        perror("Error writing to output file");
        free(file_content);
        close(fd);
        exit(EXIT_FAILURE);
    }

    free(file_content);
    close(fd);
    printf("Replaced all 'sorry' with 'I borked it good and proper!' in %s\n", argv[1]);

    return EXIT_SUCCESS;
}