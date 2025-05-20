//MISTRAL-7B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BUFFER_SIZE 4096
#define MAX_FILE_SIZE 1048576
#define MAX_LINE_LENGTH 1024

typedef struct {
    char *path;
    char *content;
    size_t size;
} eBook;

eBook *load_file(const char *path) {
    int fd = open(path, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return NULL;
    }

    struct stat st;
    fstat(fd, &st);
    eBook *book = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);

    book->path = strdup(path);
    book->size = st.st_size;

    return book;
}

void display_page(eBook *book, int page_num) {
    if (page_num < 0 || page_num >= book->size / MAX_LINE_LENGTH) {
        printf("Invalid page number\n");
        return;
    }

    size_t start = page_num * MAX_LINE_LENGTH;
    size_t end = start + MAX_LINE_LENGTH;

    char line[MAX_LINE_LENGTH + 1];
    for (size_t i = 0; i < MAX_LINE_LENGTH; ++i) {
        line[i] = book->content[start + i];
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }

    printf("%s\n", line);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path_to_ebook>\n", argv[0]);
        return 1;
    }

    eBook *ebook = load_file(argv[1]);
    if (!ebook) {
        return 1;
    }

    int page_num = 0;
    while (1) {
        char command[3];
        scanf("%s", command);

        if (strcmp(command, "next") == 0) {
            ++page_num;
            display_page(ebook, page_num);
        } else if (strcmp(command, "prev") == 0) {
            --page_num;
            display_page(ebook, page_num);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    free(ebook->path);
    munmap(ebook->content, ebook->size);
    free(ebook);

    return 0;
}