//FormAI DATASET v1.0 Category: HTML beautifier ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COL_RESET   "\033[0m"
#define COL_RED     "\033[31m"
#define COL_GREEN   "\033[32m"
#define COL_YELLOW  "\033[33m"

#define BUFFER_SIZE 8192
#define TAB_SPACES  4

#define ERROR_MSG   "Error: Unable to read file.\n"
#define USAGE_MSG   "Usage: ./beautify <filename>\n"

/* Forward Declarations */
int read_file(const char *filename, char **buffer);
int write_file(const char *filename, char *buffer, size_t size);
void beautify_html(char *buffer, size_t size);
void handle_signal(int signal);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("%s", USAGE_MSG);
        return EXIT_FAILURE;
    }

    char *buffer = NULL;
    int size = read_file(argv[1], &buffer);
    if (size == -1) {
        printf("%s", ERROR_MSG);
        return EXIT_FAILURE;
    }

    signal(SIGINT, handle_signal);
    beautify_html(buffer, size);
    write_file(argv[1], buffer, size);
    free(buffer);

    return EXIT_SUCCESS;
}

int read_file(const char *filename, char **buffer) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        return -1;
    }

    int size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    *buffer = malloc(size + 1);
    memset(*buffer, 0, size + 1);

    if (read(fd, *buffer, size) == -1) {
        return -1;
    }

    close(fd);

    return size;
}

int write_file(const char *filename, char *buffer, size_t size) {
    int fd = open(filename, O_WRONLY);
    if (fd == -1) {
        return -1;
    }

    if (write(fd, buffer, size) == -1) {
        return -1;
    }

    close(fd);

    return 0;
}

void beautify_html(char *buffer, size_t size) {
    char *output = malloc(size * 2);
    memset(output, 0, size * 2);

    int indent_level = 0;
    bool in_tag = false;
    bool in_quotes = false;

    for (size_t i = 0, j = 0; i < size; i++) {
        char c = buffer[i];

        if (c == '<') {
            in_tag = true;

            if (indent_level >= TAB_SPACES) {
                output[j++] = '\n';
                indent_level -= TAB_SPACES;
                for (int k = 0; k < indent_level; k++) {
                    output[j++] = ' ';
                }
            }

            output[j++] = c;
            if (buffer[i + 1] != '/') {
                indent_level += TAB_SPACES;
            }
        } else if (c == '>') {
            in_tag = false;
            output[j++] = c;
            if (buffer[i - 1] == '/') {
                output[j++] = '\n';
                indent_level -= TAB_SPACES;
                for (int k = 0; k < indent_level; k++) {
                    output[j++] = ' ';
                }
            }
            output[j++] = '\n';
        } else if (c == '\"') {
            in_quotes = !in_quotes;
            output[j++] = c;
        } else if (!in_quotes && !in_tag && (c == ' ' || c == '\t' || c == '\r' || c == '\n')) {
            continue;
        } else {
            output[j++] = c;
        }
    }

    memcpy(buffer, output, size * 2);

    free(output);
}

void handle_signal(int signal) {
    printf("\n%sExiting...\n", COL_RED);
    exit(EXIT_FAILURE);
}