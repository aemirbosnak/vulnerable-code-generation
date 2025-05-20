//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 256

void print_file_info(const char *filename, struct stat file_stat) {
    printf("File: %s\n", filename);
    printf("Size: %ld bytes\n", file_stat.st_size);
    printf("Last modified: %s", ctime(&file_stat.st_mtime));
    printf("Permissions: \n");
    printf(" - Read: %s\n", (file_stat.st_mode & S_IRUSR) ? "Yes" : "No");
    printf(" - Write: %s\n", (file_stat.st_mode & S_IWUSR) ? "Yes" : "No");
    printf(" - Execute: %s\n", (file_stat.st_mode & S_IXUSR) ? "Yes" : "No");
    printf("\n");
}

void list_directory(const char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    char full_path[BUFFER_SIZE];

    dir = opendir(path);
    if (!dir) {
        perror("Could not open directory");
        return;
    }

    printf("Listing files in directory: %s\n\n", path);
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') { // Skip hidden files
            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                print_file_info(entry->d_name, file_stat);
            } else {
                perror("Could not retrieve file info");
            }
        }
    }
    closedir(dir);
}

void create_directory(const char *dir_name) {
    if (mkdir(dir_name, 0755) == 0) {
        printf("Directory '%s' created successfully.\n", dir_name);
    } else {
        perror("Error creating directory");
    }
}

void delete_file(const char *file_name) {
    if (remove(file_name) == 0) {
        printf("File '%s' deleted successfully.\n", file_name);
    } else {
        perror("Error deleting file");
    }
}

void create_file(const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file) {
        fprintf(file, "This is a sample file named '%s'.\n", file_name);
        fclose(file);
        printf("File '%s' created successfully.\n", file_name);
    } else {
        perror("Error creating file");
    }
}

void display_menu() {
    printf("\n");
    printf("1. List files in a directory\n");
    printf("2. Create a new directory\n");
    printf("3. Create a new file\n");
    printf("4. Delete a file\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char input[BUFFER_SIZE];
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // consume the newline character left by scanf

        switch (choice) {
            case 1:
                printf("Enter the directory path: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                list_directory(input);
                break;
            case 2:
                printf("Enter the new directory name: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                create_directory(input);
                break;
            case 3:
                printf("Enter the new file name: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                create_file(input);
                break;
            case 4:
                printf("Enter the file name to delete: ");
                fgets(input, BUFFER_SIZE, stdin);
                input[strcspn(input, "\n")] = 0; // Remove the trailing newline
                delete_file(input);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}