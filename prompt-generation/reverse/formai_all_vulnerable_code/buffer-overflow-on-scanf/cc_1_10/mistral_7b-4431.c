//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define DIARY_FILE "diary.txt"
#define MAX_LINE_LENGTH 255

void writeDiaryEntry(const char *entry) {
    int fd;
    char buffer[MAX_LINE_LENGTH];

    fd = open(DIARY_FILE, O_WRONLY | O_APPEND);
    if (fd < 0) {
        perror("Error opening diary file");
        return;
    }

    strcpy(buffer, entry);
    if (write(fd, buffer, strlen(buffer)) < 0) {
        perror("Error writing to diary file");
    }

    close(fd);
}

void readDiaryEntry(int entryNumber) {
    int fd, position = 0;
    char buffer[MAX_LINE_LENGTH];
    ssize_t bytesRead;

    fd = open(DIARY_FILE, O_RDONLY);
    if (fd < 0) {
        perror("Error opening diary file");
        return;
    }

    lseek(fd, (entryNumber - 1) * sizeof(buffer), SEEK_SET);
    bytesRead = read(fd, buffer, sizeof(buffer));
    if (bytesRead < 0) {
        perror("Error reading from diary file");
        close(fd);
        return;
    }

    printf("Entry %d:\n%s\n", entryNumber, buffer);
    close(fd);
}

void main() {
    int choice, entryNumber;
    char entry[MAX_LINE_LENGTH];

    while (1) {
        printf("Your Digital Diary\n");
        printf("1. Write a new entry\n");
        printf("2. Read an entry\n");
        printf("3. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Write your thoughts:\n");
                fgets(entry, MAX_LINE_LENGTH, stdin);
                writeDiaryEntry(entry);
                break;
            case 2:
                printf("Enter the number of the entry to read: ");
                scanf("%d", &entryNumber);
                readDiaryEntry(entryNumber);
                break;
            case 3:
                printf("Goodbye, take care!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
}