//Falcon-180B DATASET v1.0 Category: File handling ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_SIZE 1024

// Function to read a line from a file
char* read_line(int fd) {
    char* line = malloc(MAX_LINE_SIZE);
    char ch;
    int count = 0;

    while ((ch = getc(fd))!= EOF) {
        line[count++] = ch;
        if (count == MAX_LINE_SIZE - 1) {
            line = realloc(line, sizeof(char) * (MAX_LINE_SIZE * 2));
        }
    }

    line[count] = '\0';
    return line;
}

// Function to write a line to a file
void write_line(int fd, char* line) {
    fprintf(fd, "%s", line);
    fprintf(fd, "\n");
}

// Function to search for a word in a file
int search_word(int fd, char* word) {
    char* line = NULL;
    int found = 0;

    while ((line = read_line(fd))!= NULL) {
        if (strstr(line, word)!= NULL) {
            found = 1;
            break;
        }
    }

    return found;
}

int main(int argc, char* argv[]) {
    int fd;
    char* word;

    if (argc!= 3) {
        printf("Usage: %s <filename> <word>\n", argv[0]);
        exit(1);
    }

    word = argv[2];
    fd = open(argv[1], O_RDONLY);

    if (fd == -1) {
        printf("Error opening file: %s\n", argv[1]);
        exit(1);
    }

    if (search_word(fd, word)) {
        printf("Word found!\n");
    } else {
        printf("Word not found.\n");
    }

    close(fd);
    return 0;
}