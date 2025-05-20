//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void create_directory(const char *path);
void list_directory(const char *path, int depth);
void remove_directory(const char *path);
void remove_directory_recursively(const char *path);

int main() {
    int choice;
    char path[256];

    while (1) {
        printf("\nDirectory Management System\n");
        printf("1. Create Directory\n");
        printf("2. List Directory\n");
        printf("3. Remove Directory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  // To consume newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the path to create directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0;  // Remove newline character
                create_directory(path);
                break;
            case 2:
                printf("Enter the path to list directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0;  // Remove newline character
                list_directory(path, 0);
                break;
            case 3:
                printf("Enter the path to remove directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0;  // Remove newline character
                remove_directory_recursively(path);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void create_directory(const char *path) {
    if (mkdir(path, 0777) == 0) {
        printf("Directory created: %s\n", path);
    } else {
        perror("Error creating directory");
    }
}

void list_directory(const char *path, int depth) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {  // Skip hidden files
            for (int i = 0; i < depth; i++)
                printf("  ");  // Indentation for depth
            printf("%s\n", entry->d_name);
            if (entry->d_type == DT_DIR) {  // If directory, recurse into it
                char subpath[256];
                snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
                list_directory(subpath, depth + 1);
            }
        }
    }
    closedir(dir);
}

void remove_directory_recursively(const char *path) {
    DIR *dir = opendir(path);
    struct dirent *entry;

    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {  // Skip hidden files
            char subpath[256];
            snprintf(subpath, sizeof(subpath), "%s/%s", path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                remove_directory_recursively(subpath);  // Recurse into subdirectory
            } else {
                unlink(subpath);  // Remove file
            }
        }
    }
    closedir(dir);

    // Remove the directory itself
    if (rmdir(path) == 0) {
        printf("Removed directory: %s\n", path);
    } else {
        perror("Error removing directory");
    }
}