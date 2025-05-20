//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

typedef struct { char c; size_t len; } word_t;

size_t file_size(const char *path) {
    struct stat st;
    if (stat(path, &st) < 0) return 0;
    return st.st_size;
}

word_t *load_file(const char *path) {
    size_t size = file_size(path);
    word_t *data = mmap(NULL, size, PROT_READ, MAP_PRIVATE, open(path, O_RDONLY), 0);
    close(open(path, O_RDONLY));
    data[size / sizeof(word_t)] = (word_t){0, 0};
    return data;
}

void print_words(const word_t *data, size_t len) {
    for (size_t i = 0; i < len; ++i) {
        printf("%c", data[i].c);
        if (data[i].len > 1) {
            write(STDOUT_FILENO, data[i].c, data[i].len - 1);
        }
    }
    printf("\n");
}

int main() {
    char *filename = getenv("TYPING_TEST_FILE");
    if (!filename) {
        fprintf(stderr, "TYPING_TEST_FILE environment variable is not set.\n");
        return 1;
    }

    word_t *file = load_file(filename);
    size_t len = file_size(filename) / sizeof(word_t);

    clock_t start = clock();
    print_words(file, len);
    clock_t end = clock();
    double time_spent = (end - start) / CLOCKS_PER_SEC;

    printf("Time spent: %.12f seconds\n", time_spent);

    munmap(file, file_size(filename));

    return 0;
}

#define TYPING_TEST_FILE "test.txt"