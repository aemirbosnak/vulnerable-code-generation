//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

void display_usage(char *path) {
    struct stat statbuf;
    long total = 0;
    long used = 0;
    long free = 0;

    // Get filesystem statistics for the given path
    if (stat(path, &statbuf) == 0) {
        total = statbuf.st_size;
        // Assuming we can approximate used space
        used = total - statbuf.st_blocks * 512; // 512 bytes per disk block
        free = total - used;

        printf("Disk usage for path: %s\n", path);
        printf("Total: %ld bytes\n", total);
        printf("Used: %ld bytes\n", used);
        printf("Free: %ld bytes\n", free);
    } else {
        perror("Unable to retrieve stats");
    }
}

void analyze_directory(const char *dir_path) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dir_path)) == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip the . and .. entries
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[1024];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            struct stat statbuf;

            if (stat(full_path, &statbuf) == 0) {
                printf("%s - Size: %ld bytes\n", full_path, statbuf.st_size);
            } else {
                perror("Unable to retrieve stats");
            }
        }
    }

    closedir(dir);
}

int main() {
    char path[1024];
    int choice;

    printf("Welcome to the Disk Space Analyzer!\n");

    while (1) {
        printf("Please enter a directory path to analyze (or type 'exit' to quit): ");
        fgets(path, sizeof(path), stdin);
        path[strcspn(path, "\n")] = 0; // Remove trailing newline

        if (strcmp(path, "exit") == 0) {
            break;
        }

        display_usage(path);
        analyze_directory(path);

        printf("\nDo you want to analyze another directory? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf
        if (choice != 1) {
            break;
        }
    }

    printf("Thank you for using the Disk Space Analyzer!\n");
    return 0;
}