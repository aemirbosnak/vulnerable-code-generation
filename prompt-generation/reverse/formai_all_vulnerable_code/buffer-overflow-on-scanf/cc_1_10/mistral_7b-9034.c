//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <ctype.h>

#define DIARY_FILE "cyberdiary.dat"
#define MAX_LINE_LENGTH 256
#define ENTRY_SIZE (sizeof(struct entry) + MAX_LINE_LENGTH)

struct entry {
    time_t timestamp;
    char description[MAX_LINE_LENGTH];
};

void print_menu() {
    printf("\n***** Cyberpunk Digital Diary *****\n");
    printf("1. New Entry\n");
    printf("2. View Entries\n");
    printf("3. Delete Entry\n");
    printf("4. Exit\n");
}

int save_entry(struct entry entry) {
    int fd, ret;
    struct stat st;

    fd = open(DIARY_FILE, O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("open");
        return -1;
    }

    ret = write(fd, &entry, ENTRY_SIZE);
    if (ret != ENTRY_SIZE) {
        perror("write");
        close(fd);
        return -1;
    }

    fsync(fd);
    close(fd);

    return 0;
}

void load_entry(int index, struct entry *entry) {
    int fd = open(DIARY_FILE, O_RDONLY);

    if (fd < 0) {
        perror("open");
        return;
    }

    lseek(fd, index * ENTRY_SIZE, SEEK_SET);
    read(fd, entry, ENTRY_SIZE);

    close(fd);
}

int main(int argc, char *argv[]) {
    char line[MAX_LINE_LENGTH];
    struct entry new_entry;
    int choice, index, num_entries = 0;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a description for your new entry: ");
            fgets(new_entry.description, MAX_LINE_LENGTH, stdin);
            new_entry.description[strlen(new_entry.description) - 1] = '\0';
            time(&new_entry.timestamp);

            save_entry(new_entry);
            num_entries++;
            break;

        case 2: {
            struct entry entry;
            int i;

            printf("\nID\tTimestamp\tDescription\n");
            for (i = 0; i < num_entries; i++) {
                load_entry(i, &entry);
                printf("%d\t%s\t%s\n", i, ctime(&entry.timestamp), entry.description);
            }
            break;
        }

        case 3: {
            int id;
            struct entry entry;

            printf("Enter the ID of the entry to delete: ");
            scanf("%d", &id);

            load_entry(id, &entry);

            if (remove(DIARY_FILE) < 0) {
                perror("remove");
                printf("Error deleting file.\n");
            } else {
                num_entries--;
                printf("Entry deleted successfully.\n");
            }

            break;
        }

        case 4:
            exit(0);

        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}