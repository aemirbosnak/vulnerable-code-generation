//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

#define DIARY_FILE "diary.txt"

typedef struct {
    time_t time;
    char message[100];
} DiaryEntry;

void save_entry(DiaryEntry entry) {
    int fd = open(DIARY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening diary file");
        exit(EXIT_FAILURE);
    }

    struct timeval tv;
    gettimeofday(&tv, NULL);

    ssize_t len = write(fd, &entry.time, sizeof(entry.time));
    if (len != sizeof(entry.time)) {
        perror("Error writing time to diary file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    len = write(fd, entry.message, strlen(entry.message));
    if (len < 0) {
        perror("Error writing message to diary file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void print_entry(DiaryEntry entry) {
    struct tm *tm = localtime(&entry.time);
    printf("%s %s %d %d:%d:%d %s\n",
           asctime(tm),
           entry.message,
           tm->tm_mday,
           tm->tm_mon + 1,
           tm->tm_hour,
           tm->tm_min,
           tm->tm_sec);
}

void print_menu() {
    printf("Welcome to the Surrealist Digital Diary!\n");
    printf("1. Write an entry\n");
    printf("2. Read last entry\n");
    printf("3. Exit\n");
}

int main() {
    signal(SIGINT, SIG_IGN); // Ignore CTRL+C

    int choice;
    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                DiaryEntry entry;
                printf("Enter a message: ");
                scanf("%s", entry.message);

                time_t now = time(NULL);
                entry.time = now;

                save_entry(entry);
                printf("Entry saved.\n");
                break;
            }
            case 2: {
                int fd = open(DIARY_FILE, O_RDONLY);
                if (fd < 0) {
                    perror("Error opening diary file");
                    exit(EXIT_FAILURE);
                }

                DiaryEntry last_entry;
                size_t len = read(fd, &last_entry, sizeof(last_entry));
                if (len != sizeof(last_entry)) {
                    perror("Error reading last entry from diary file");
                    close(fd);
                    exit(EXIT_FAILURE);
                }

                close(fd);

                print_entry(last_entry);
                break;
            }
            case 3:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}