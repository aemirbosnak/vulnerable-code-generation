//MISTRAL-7B DATASET v1.0 Category: Time Travel Simulator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define MAX_LINE_LENGTH 256
#define TIME_TRAVEL_DELAY 50000000

typedef struct {
    char filename[MAX_LINE_LENGTH];
    char* content;
    struct stat file_stat;
} FileSnapshot;

void save_file_snapshot(FileSnapshot* fs) {
    int fd = open(fs->filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    off_t file_size = fs->file_stat.st_size;
    fs->content = malloc(file_size + 1);

    ssize_t bytes_read = read(fd, fs->content, file_size);
    if (bytes_read != file_size) {
        perror("Error reading file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void print_file_snapshot(FileSnapshot* fs) {
    printf("\n----- File snapshot: %s -----\n", fs->filename);
    printf("Size: %ld bytes\n", (long)fs->file_stat.st_size);
    printf("Content:\n%s\n", fs->content);
}

void travel_to_past(const char* filename) {
    printf("Traveling back in time to save a snapshot of %s...\n", filename);

    struct stat file_stat;
    stat(filename, &file_stat);

    FileSnapshot file_snapshot;
    strcpy(file_snapshot.filename, filename);
    file_snapshot.file_stat = file_stat;

    save_file_snapshot(&file_snapshot);

    printf("Snapshot saved.\n");
    sleep(TIME_TRAVEL_DELAY);

    printf("Returning to the present...\n");
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <file_to_travel_to>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* file_to_travel_to = argv[1];

    travel_to_past(file_to_travel_to);

    FILE* fp = fopen("snapshot.txt", "w");
    if (fp == NULL) {
        perror("Error creating snapshot.txt file");
        exit(EXIT_FAILURE);
    }

    FileSnapshot file_snapshot;
    strcpy(file_snapshot.filename, "snapshot.txt");
    save_file_snapshot(&file_snapshot);

    print_file_snapshot(&file_snapshot);
    fprintf(fp, "File snapshot saved: %s\n", file_snapshot.filename);
    fclose(fp);

    free(file_snapshot.content);

    printf("Back in the present, file snapshot saved to snapshot.txt.\n");

    return EXIT_SUCCESS;
}