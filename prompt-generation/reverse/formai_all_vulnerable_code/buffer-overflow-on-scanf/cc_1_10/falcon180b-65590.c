//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: surrealist
#include <stdio.h>

#define MAX_FILES 1000
#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    long size;
} File;

void print_files(File *files, int count) {
    printf("Files:\n");
    for (int i = 0; i < count; i++) {
        printf("%s (%ld bytes)\n", files[i].name, files[i].size);
    }
}

int main() {
    char dir_name[MAX_LINE_LENGTH];
    printf("Enter directory name: ");
    scanf("%s", dir_name);

    printf("Scanning directory...\n");

    char cmd[MAX_LINE_LENGTH];
    sprintf(cmd, "du -a %s | sort -nr", dir_name);

    FILE *pipe = popen(cmd, "r");

    if (pipe == NULL) {
        printf("Error: could not open pipe\n");
        return 1;
    }

    File files[MAX_FILES];
    int count = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, pipe)!= NULL) {
        if (count >= MAX_FILES) {
            printf("Error: too many files\n");
            pclose(pipe);
            return 1;
        }

        char *name = strtok(line, " ");
        long size = strtol(name, NULL, 10);

        strcpy(files[count].name, name);
        files[count].size = size;

        count++;
    }

    pclose(pipe);

    printf("Total disk space used: %ld bytes\n", files[0].size);

    print_files(files, count);

    return 0;
}