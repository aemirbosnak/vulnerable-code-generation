//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define CONFIG_FILE "sysadmin_config.txt"
#define BUFFER_SIZE 256

void clear_screen() {
    // Clear screen command
    printf("\033[H\033[J");
}

void display_main_menu() {
    clear_screen();
    printf("=== System Administration Program ===\n");
    printf("1. Create a file\n");
    printf("2. Show current directory\n");
    printf("3. Read a file\n");
    printf("4. Write to a file\n");
    printf("5. Exit\n");
    printf("===================================== \n");
}

void create_file() {
    char filename[BUFFER_SIZE];
    printf("Enter filename to create: ");
    scanf("%s", filename);

    int fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0644);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }
    close(fd);
    printf("File '%s' created successfully.\n", filename);
    getchar(); // Consume newline left in buffer
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input
}

void show_current_directory() {
    char cwd[BUFFER_SIZE];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current working directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input
}

void read_file() {
    char filename[BUFFER_SIZE];
    printf("Enter filename to read: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, sizeof(buffer), file)) {
        printf("%s", buffer);
    }
    fclose(file);
    printf("\nPress Enter to continue...\n");
    getchar(); // Wait for user input
}

void write_file() {
    char filename[BUFFER_SIZE];
    printf("Enter filename to write: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    printf("Enter text to write (end with EOF): \n");
    char ch;
    while ((ch = getchar()) != EOF) {
        fputc(ch, file);
    }
    fclose(file);
    printf("Text written to '%s' successfully.\n", filename);
    printf("Press Enter to continue...\n");
    getchar(); // Wait for user input
}

int main() {
    int choice;
    do {
        display_main_menu();
        printf("Choose an option [1-5]: ");
        
        if(scanf("%d", &choice) != 1) {
            while(getchar() != '\n'); // Clear invalid input
            continue;
        }
        
        switch (choice) {
            case 1:
                create_file();
                break;
            case 2:
                show_current_directory();
                break;
            case 3:
                read_file();
                break;
            case 4:
                write_file();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please choose again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}