//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define DIARY_FILE "diary.dat"
#define LINE_SIZE 1024
#define ENTRY_SIZE (100 + 1 + 1 + sizeof(time_t))

typedef struct {
    char name[100];
    char text[100];
    time_t timestamp;
} entry_t;

int main(int argc, char *argv[]) {
    int fd, i;
    char buffer[LINE_SIZE];
    entry_t new_entry;

    if (access(DIARY_FILE, F_OK) != -1) {
        fd = open(DIARY_FILE, O_RDWR);

        while (read(fd, buffer, LINE_SIZE) > 0) {
            sscanf(buffer, "%[^:]: %s %s %ld", new_entry.name, new_entry.text, &new_entry.timestamp);
            printf("%s: %s %s\n", new_entry.name, new_entry.text, ctime(&new_entry.timestamp));
        }

        close(fd);
    }

    printf("\nEnter your name: ");
    fgets(new_entry.name, sizeof(new_entry.name), stdin);
    new_entry.name[strlen(new_entry.name) - 1] = '\0';

    printf("\nEnter your message: ");
    fgets(new_entry.text, sizeof(new_entry.text), stdin);
    new_entry.text[strlen(new_entry.text) - 1] = '\0';

    new_entry.timestamp = time(NULL);

    fd = open(DIARY_FILE, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    for (i = lseek(fd, 0, SEEK_END); i >= 0; i -= ENTRY_SIZE) {
        lseek(fd, i, SEEK_SET);
        write(fd, &new_entry, ENTRY_SIZE);
    }

    printf("\nEntry saved.\n");

    close(fd);

    return 0;
}