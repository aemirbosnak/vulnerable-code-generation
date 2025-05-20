//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define DIARY_FILE "diary.txt"
#define MAX_LINE_LEN 256

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int fd, ret;
    char line[MAX_LINE_LEN], cmd[MAX_LINE_LEN], *token;
    struct stat st;

    fd = open(DIARY_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) die("open");

    printf("Welcome to the Ken Thompson Style Digital Diary!\n");
    printf("Enter a command or type 'quit' to exit.\n");

    while (1) {
        printf("\nDiary > ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line) - 1] = '\0';

        if (strcmp(line, "quit") == 0) break;

        strcpy(cmd, line);
        token = strtok(cmd, " ");
        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " ");
            if (!token) {
                printf("Error: Missing message to add.\n");
                continue;
            }
            ret = write(fd, token, strlen(token) + 1);
            if (ret == -1) die("write");
            printf("Message added successfully.\n");
        } else if (strcmp(token, "read") == 0) {
            if (fstat(fd, &st) == -1) die("fstat");
            if (lseek(fd, 0, SEEK_SET) == -1) die("lseek");
            while ((ret = read(fd, line, MAX_LINE_LEN)) > 0) {
                printf("%s", line);
                if (strlen(line) < MAX_LINE_LEN - 1) printf("\n");
            }
            if (ret == -1) die("read");
        } else {
            printf("Error: Unknown command '%s'.\n", token);
        }
    }

    close(fd);
    exit(0);
}