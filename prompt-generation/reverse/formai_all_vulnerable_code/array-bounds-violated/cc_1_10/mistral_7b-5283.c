//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRY_LEN 200
#define ENTRY_NUM 10
#define ENTRY_SIZE (sizeof(struct diary_entry) + MAX_ENTRY_LEN)

struct diary_entry {
    time_t timestamp;
    char content[MAX_ENTRY_LEN];
};

void _error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(void) {
    int fd, i, j;
    struct stat st;
    struct diary_entry entries[ENTRY_NUM];

    if ((fd = open(DIARY_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1)
        _error("Failed to open file");

    if (fstat(fd, &st) == -1)
        _error("Failed to stat file");

    if (st.st_size % ENTRY_SIZE) {
        if (lseek(fd, ENTRY_SIZE - (st.st_size % ENTRY_SIZE), SEEK_SET) == -1)
            _error("Failed to move file pointer");

        if (write(fd, "", 1) == -1)
            _error("Failed to write empty space");
    }

    for (i = 0; i < ENTRY_NUM; ++i) {
        entries[i].timestamp = time(NULL);
        printf("Enter diary entry %d (%s): ", i + 1, ctime(&entries[i].timestamp));
        fgets(entries[i].content, MAX_ENTRY_LEN, stdin);
        entries[i].content[strlen(entries[i].content) - 1] = '\0';

        if (lseek(fd, ENTRY_SIZE * i, SEEK_SET) == -1)
            _error("Failed to move file pointer");

        if (write(fd, &entries[i], ENTRY_SIZE) != ENTRY_SIZE)
            _error("Failed to write diary entry");

        sleep(1); // Add a shocking delay between entries
    }

    printf("\nYour shocking digital diary has been created!\n");
    close(fd);
    return EXIT_SUCCESS;
}