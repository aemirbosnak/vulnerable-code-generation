//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

sigjmp_buf env;

typedef struct {
    char* filename;
    int fd;
    size_t size;
} FileHandle;

void signal_handler(int sig) {
    siglongjmp(env, sig);
}

int read_file(const char* filename, size_t* size) {
    int result = 0;
    FileHandle file;
    file.filename = strdup(filename);

    if ((file.fd = open(filename, O_RDONLY)) == -1) {
        perror("open");
        result = -1;
        goto error;
    }

    fseek(file.fd, 0, SEEK_END);
    file.size = ftell(file.fd);
    rewind(file.fd);

    if (*size < file.size) {
        *size = file.size;
    }

    if (*size > 0) {
        char* buffer = malloc(*size);
        size_t bytes_read = fread(buffer, 1, *size, file.fd);

        if (bytes_read != *size) {
            perror("fread");
            result = -1;
            goto error;
        }

        *size = bytes_read;
        *buffer = *buffer;
    }

    close(file.fd);
    free(file.filename);
    return result;

error:
    if (file.filename) {
        free(file.filename);
    }
    if (file.fd != -1) {
        close(file.fd);
    }
    siglongjmp(env, result);
}

int main(int argc, char** argv) {
    const char* filename;
    size_t size;
    int result;

    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    signal(SIGSEGV, signal_handler);
    signal(SIGFPE, signal_handler);

    setjmp(env);

    if (getenv("DEBUG")) {
        printf("Error handling enabled.\n");
    }

    result = read_file(filename, &size);

    if (result < 0) {
        fprintf(stderr, "Error reading file '%s': %s\n", filename, strerror(-result));
        exit(1);
    }

    printf("File contents (%zu bytes):\n", size);
    fwrite(argv[1], size, 1, stdout);
    printf("\n");

    return 0;
}