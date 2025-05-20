//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PROCESSES 1024
#define BUFFER_SIZE 256

void listProcesses() {
    FILE *fp;
    char buffer[BUFFER_SIZE];

    printf("\n--- List of Running Processes ---\n");
    fp = popen("ps -eo pid,comm", "r");
    if (fp == NULL) {
        perror("Failed to run command");
        return;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    pclose(fp);
}

void killProcess(pid_t pid) {
    if (kill(pid, SIGTERM) == -1) {
        perror("Failed to terminate process");
    } else {
        printf("Process %d terminated successfully.\n", pid);
    }
}

void createFile() {
    char filename[BUFFER_SIZE];
    char content[BUFFER_SIZE];
    
    printf("Enter filename to create: ");
    scanf("%s", filename);
    
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error creating file");
        return;
    }

    printf("Enter content for the file:\n");
    getchar(); // To consume the newline left by scanf
    fgets(content, sizeof(content), stdin);
    
    write(fd, content, strlen(content));
    close(fd);
    printf("File %s created successfully!\n", filename);
}

void deleteFile() {
    char filename[BUFFER_SIZE];
    
    printf("Enter filename to delete: ");
    scanf("%s", filename);
    
    if (remove(filename) == 0) {
        printf("File %s deleted successfully!\n", filename);
    } else {
        perror("Error deleting file");
    }
}

void displayMenu() {
    printf("\n--- System Administration Utility ---\n");
    printf("1. List running processes\n");
    printf("2. Kill a process\n");
    printf("3. Create a file\n");
    printf("4. Delete a file\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    pid_t pid;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                listProcesses();
                break;

            case 2:
                printf("Enter PID of the process to kill: ");
                scanf("%d", &pid);
                killProcess(pid);
                break;

            case 3:
                createFile();
                break;

            case 4:
                deleteFile();
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}