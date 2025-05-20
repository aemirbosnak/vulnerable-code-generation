//GPT-4o-mini DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define MAX_PASSWORD_LENGTH 128
#define FILE_NAME "passwords.dat"

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
} User;

void hide_input(char *buffer, int size) {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    fgets(buffer, size, stdin);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void add_user() {
    User user;
    FILE *file = fopen(FILE_NAME, "ab");

    if (!file) {
        perror("Failed to open file");
        return;
    }

    printf("Enter username: ");
    scanf("%49s", user.username);
    printf("Enter password: ");
    hide_input(user.password, MAX_PASSWORD_LENGTH);
    
    fputc('\n', stdin); // to consume the newline character after hidden input
    fseek(file, 0, SEEK_END);
    
    fwrite(&user, sizeof(User), 1, file);
    fclose(file);
    printf("\nUser added successfully!\n");
}

void list_users() {
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    printf("\nStored Users:\n");
    while (fread(&user, sizeof(User), 1, file)) {
        printf("Username: %s, Password: [Hidden]\n", user.username);
    }
    
    fclose(file);
}

void delete_user() {
    User user;
    FILE *file = fopen(FILE_NAME, "rb");
    
    if (!file) {
        perror("Failed to open file");
        return;
    }
    
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    char username_to_delete[50];
    printf("Enter the username to delete: ");
    scanf("%49s", username_to_delete);

    int found = 0;
    while (fread(&user, sizeof(User), 1, file)) {
        if (strcmp(user.username, username_to_delete) == 0) {
            found = 1;
            printf("Deleting user: %s\n", user.username);
        } else {
            fwrite(&user, sizeof(User), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);
    
    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found) {
        printf("User deletion successful!\n");
    } else {
        printf("User not found.\n");
    }
}

void menu() {
    int choice;

    do {
        printf("\n--- Password Management System ---\n");
        printf("1. Add User\n2. List Users\n3. Delete User\n4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
                add_user();
                break;
            case 2: 
                list_users();
                break;
            case 3: 
                delete_user();
                break;
            case 4: 
                printf("Exiting the system. Goodbye!\n");
                break;
            default: 
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}