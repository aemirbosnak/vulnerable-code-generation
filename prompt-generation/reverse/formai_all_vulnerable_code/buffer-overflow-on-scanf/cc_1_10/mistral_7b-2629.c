//MISTRAL-7B DATASET v1.0 Category: Password management ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <shadow.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sysmacros.h>

#define MAX_LEN 100
#define FILE_NAME "passwords.db"
#define SEPERATOR '|'

struct password_entry {
    char username[MAX_LEN];
    char password[MAX_LEN];
};

void encrypt_password(char *password) {
    int i;
    for (i = 0; password[i] != '\0'; i++) {
        password[i] = (password[i] + 3) % 256;
    }
}

void save_password(struct password_entry *entry) {
    int fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN * 2];
    snprintf(line, sizeof(line), "%s%c%s%c", entry->username, SEPERATOR, entry->password);

    if (write(fd, line, strlen(line)) < 0) {
        perror("Error writing to file");
        exit(EXIT_FAILURE);
    }

    close(fd);
}

void load_password(char *username, char *password) {
    int fd = open(FILE_NAME, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LEN * 2];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, line, sizeof(line))) > 0) {
        char *token = strtok(line, SEPERATOR);
        if (token != NULL && strcmp(token, username) == 0) {
            strcpy(password, strtok(NULL, SEPERATOR));
            break;
        }
    }

    close(fd);
}

void print_menu() {
    printf("\n===============\n");
    printf("|  Cyberpunk  |\n");
    printf("| Password Mgr|\n");
    printf("===============\n");
    printf("1. Add password\n");
    printf("2. List passwords\n");
    printf("3. Delete password\n");
    printf("4. Exit\n");
}

int main() {
    setvbuf(stdin, NULL, _IONBF, 0);

    char username[MAX_LEN], password[MAX_LEN];
    int choice;

    struct password_entry new_entry;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter username: ");
                scanf("%s", username);
                encrypt_password(new_entry.password);
                strcpy(new_entry.username, username);
                save_password(&new_entry);
                printf("Password saved.\n");
                break;
            case 2:
                printf("Listing passwords...\n");
                // TODO: Implement listing passwords
                break;
            case 3:
                printf("Enter username to delete: ");
                scanf("%s", username);
                // TODO: Implement deleting password
                break;
            case 4:
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return EXIT_SUCCESS;
}