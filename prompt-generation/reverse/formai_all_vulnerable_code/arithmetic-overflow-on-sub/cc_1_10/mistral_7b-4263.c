//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#define WORD "word"
#define FILE_PATH "input.txt"

int main() {
    int fd, i, pos, count = 0;
    char buf[4096], word_buf[64];
    struct stat file_stat;

    if (stat(FILE_PATH, &file_stat) < 0) {
        perror("Error while getting file stats");
        exit(1);
    }

    fd = open(FILE_PATH, O_RDONLY);
    if (fd < 0) {
        perror("Error while opening file");
        exit(1);
    }

    lseek(fd, file_stat.st_size - 1, SEEK_SET);
    read(fd, &buf, 1);

    while (read(fd, buf, 4095) > 0) {
        for (i = 0; i < 4096 && buf[i] != '\0'; i++) {
            if (buf[i] == '\n') {
                pos = i;
                i--;
                break;
            }
        }

        memset(word_buf, '\0', sizeof(word_buf));
        strncpy(word_buf, buf + pos - strlen(WORD) + 1, strlen(WORD) + 1);

        if (strcmp(word_buf, WORD) == 0) {
            count++;
            i += strlen(WORD);
            memmove(buf + i, buf + pos, file_stat.st_size % (pos + 1) - pos);
            file_stat.st_size -= (pos + 1);
            lseek(fd, file_stat.st_size, SEEK_SET);
            continue;
        }

        i += strlen(word_buf);
        memmove(buf, buf + pos, file_stat.st_size % (pos + 1) - pos);
        file_stat.st_size -= (pos + 1);
        lseek(fd, file_stat.st_size, SEEK_SET);
    }

    close(fd);
    printf("The word '%s' appears %d times in the file '%s'\n", WORD, count, FILE_PATH);

    return 0;
}