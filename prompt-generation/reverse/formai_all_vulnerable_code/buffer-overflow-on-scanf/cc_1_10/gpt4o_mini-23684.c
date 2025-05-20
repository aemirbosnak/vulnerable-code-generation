//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>

void list_files() {
    struct dirent *de; 
    DIR *dr = opendir("."); 

    if (dr == NULL) {
        printf("Could not open current directory" );
        return;
    }

    printf("Files in current directory:\n");
    while ((de = readdir(dr)) != NULL) {
        printf("%s\n", de->d_name);
    }
    closedir(dr);
}

void create_file(const char* filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", filename);
        return;
    }

    char content[256];
    printf("Enter content for the file (max 255 characters): ");
    fgets(content, sizeof(content), stdin);
    fprintf(fp, "%s", content);
    fclose(fp);
    printf("File %s created successfully.\n", filename);
}

void read_file(const char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File %s could not be opened for reading.\n", filename);
        return;
    }

    char ch;
    printf("Contents of %s:\n", filename);
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void delete_file(const char* filename) {
    if (remove(filename) == 0) {
        printf("File %s deleted successfully.\n", filename);
    } else {
        printf("Error deleting file %s\n", filename);
    }
}

int main() {
    int choice;
    char filename[100];
    
    while (1) {
        printf("\nSimple File Management System\n");
        printf("1. List files\n");
        printf("2. Create a file\n");
        printf("3. Read a file\n");
        printf("4. Delete a file\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline character after the number input

        switch (choice) {
            case 1:
                list_files();
                break;
            case 2:
                printf("Enter the name of the file to create: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                create_file(filename);
                break;
            case 3:
                printf("Enter the name of the file to read: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                read_file(filename);
                break;
            case 4:
                printf("Enter the name of the file to delete: ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = '\0'; // Remove newline
                delete_file(filename);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}