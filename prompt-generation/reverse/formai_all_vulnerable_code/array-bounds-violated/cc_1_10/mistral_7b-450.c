//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define DIARY_FILE "diary.txt"
#define MAX_ENTRY_LENGTH 500
#define ENTRY_FILE_NAME_LENGTH 50

// Paranoidly check if the user has write permissions to the current directory
int check_write_permission() {
    struct stat st;
    if (stat(DIARY_FILE, &st) < 0) {
        perror("Error while checking file existence");
        exit(EXIT_FAILURE);
    }

    if (S_ISDIR(st.st_mode)) {
        perror("Current directory is a directory. Please change to a valid file path.");
        exit(EXIT_FAILURE);
    }

    if (!S_ISREG(st.st_mode) || !(S_ISREG(st.st_mode) && S_IWUSR & st.st_mode)) {
        perror("Error: File is not a regular file or you don't have write permissions.");
        exit(EXIT_FAILURE);
    }

    return 1;
}

// Paranoidly write an entry to the diary file
void write_entry(const char *entry) {
    int fd = open(DIARY_FILE, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (fd < 0) {
        perror("Error while opening the diary file for writing.");
        exit(EXIT_FAILURE);
    }

    size_t entry_length = strlen(entry) + 1;
    char entry_filename[ENTRY_FILE_NAME_LENGTH];
    snprintf(entry_filename, ENTRY_FILE_NAME_LENGTH, "%d", getpid());

    if (write(fd, entry, entry_length) != entry_length) {
        perror("Error while writing the entry to the diary file.");
        exit(EXIT_FAILURE);
    }

    if (link(DIARY_FILE, entry_filename) < 0) {
        perror("Error while creating an entry file link.");
        exit(EXIT_FAILURE);
    }

    unlink(entry_filename);
    close(fd);
}

int main() {
    check_write_permission();

    printf("Enter your digital diary entry (up to %d characters):\n", MAX_ENTRY_LENGTH);

    char entry[MAX_ENTRY_LENGTH];
    fgets(entry, MAX_ENTRY_LENGTH, stdin);

    // Remove the newline character added by fgets()
    size_t entry_length = strlen(entry);
    if (entry[entry_length - 1] == '\n') {
        entry[entry_length - 1] = '\0';
    }

    write_entry(entry);

    printf("Your entry has been saved.\n");

    return EXIT_SUCCESS;
}