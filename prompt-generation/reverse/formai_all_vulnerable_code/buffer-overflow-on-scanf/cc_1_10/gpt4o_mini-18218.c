//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

void create_directory(const char *dir_name) {
    if (mkdir(dir_name, 0755) == 0) {
        printf("Directory '%s' created successfully.\n", dir_name);
    } else {
        perror("Error creating directory");
    }
}

void list_files(const char *dir_name) {
    DIR *dir;
    struct dirent *entry;

    if ((dir = opendir(dir_name)) == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("Contents of directory '%s':\n", dir_name);
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    closedir(dir);
}

void create_file(const char *file_name) {
    FILE *file = fopen(file_name, "w");
    if (file) {
        fprintf(file, "This file was created on the system.\n");
        fclose(file);
        printf("File '%s' created successfully.\n", file_name);
    } else {
        perror("Error creating file");
    }
}

void delete_file(const char *file_name) {
    if (remove(file_name) == 0) {
        printf("File '%s' deleted successfully.\n", file_name);
    } else {
        perror("Error deleting file");
    }
}

void display_menu() {
    printf("\nSystem Administration Tool\n");
    printf("1. Create Directory\n");
    printf("2. List Files in Directory\n");
    printf("3. Create File\n");
    printf("4. Delete File\n");
    printf("5. Exit\n");
    printf("Choose an option (1-5): ");
}

int main() {
    int choice;
    char name[256];

    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume leftover newline character

        switch (choice) {
            case 1:
                printf("Enter directory name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                create_directory(name);
                break;

            case 2:
                printf("Enter directory name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                list_files(name);
                break;

            case 3:
                printf("Enter file name to create: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                create_file(name);
                break;

            case 4:
                printf("Enter file name to delete: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline
                delete_file(name);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}