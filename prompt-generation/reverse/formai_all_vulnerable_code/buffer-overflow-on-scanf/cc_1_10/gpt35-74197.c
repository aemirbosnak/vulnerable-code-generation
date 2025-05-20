//FormAI DATASET v1.0 Category: Password management ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

// Struct to hold password data
typedef struct PasswordData {
    int id;
    char *username;
    char *password;
} PasswordData;

// Function to generate unique password IDs
int generateID() {
    static int id = 0;
    return ++id;
}

// Function to add password data to file
void addPasswordDataToFile(PasswordData passwordData) {
    FILE *file = fopen("passwords.txt", "a");
    if (file == NULL) {
        printf("File could not be opened!");
        return;
    }

    fprintf(file, "%d;%s;%s\n", passwordData.id, passwordData.username, passwordData.password);
    fclose(file);
}

// Function to check if password already exists in file
bool passwordExistsInFile(char *password) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return false;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, ";");
        if (strcmp(token, password) == 0) {
            fclose(file);
            return true;
        }
    }

    fclose(file);
    if (line) free(line);
    return false;
}

// Function to get password data from file by ID
PasswordData getPasswordDataFromFile(int passwordID) {
    PasswordData passwordData = {0};
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        return passwordData;
    }

    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, ";");
        if (atoi(token) == passwordID) {
            passwordData.id = atoi(token);
            passwordData.username = strtok(NULL, ";");
            passwordData.password = strtok(NULL, ";");
            break;
        }
    }

    fclose(file);
    if (line) free(line);
    return passwordData;
}

// Function to print all password data in file
void printAllPasswordData() {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    FILE *file = fopen("passwords.txt", "r");
    if (file == NULL) {
        printf("File could not be opened!");
        return;
    }

    printf("\nID\tUSERNAME\tPASSWORD\n");
    while ((read = getline(&line, &len, file)) != -1) {
        char *token = strtok(line, ";");
        printf("%s\t", token);
        token = strtok(NULL, ";");
        printf("%s\t\t", token);
        token = strtok(NULL, ";");
        printf("%s", token);
    }
    printf("\n");

    fclose(file);
    if (line) free(line);
}

int main() {
    char command[256];
    bool running = true;

    while (running) {
        printf("\nEnter a command (add, get, exit):\n");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) { // Add password
            char username[256];
            char password[256];

            printf("Enter a username:\n");
            scanf("%s", username);

            while (true) {
                printf("Enter a password (must be at least 8 characters long and contain at least one uppercase letter, one lowercase letter, and one number):\n");
                scanf("%s", password);
                int length = strlen(password);
                bool hasUppercase = false;
                bool hasLowercase = false;
                bool hasNumber = false;
                for (int i = 0; i < length; i++) {
                    if ('A' <= password[i] && password[i] <= 'Z') {
                        hasUppercase = true;
                    } else if ('a' <= password[i] && password[i] <= 'z') {
                        hasLowercase = true;
                    } else if ('0' <= password[i] && password[i] <= '9') {
                        hasNumber = true;
                    }
                }
                if (length >= 8 && hasUppercase && hasLowercase && hasNumber) {
                    break;
                } else {
                    printf("Invalid password format!\n");
                }
            }

            if (passwordExistsInFile(password)) {
                printf("Password already exists!\n");
            } else {
                PasswordData passwordData = {0};
                passwordData.id = generateID();
                passwordData.username = username;
                passwordData.password = password;

                addPasswordDataToFile(passwordData);

                printf("Password added successfully!\n");
            }
        } else if (strcmp(command, "get") == 0) { // Get password
            int passwordID;
            printf("Enter a password ID:\n");
            scanf("%d", &passwordID);

            PasswordData passwordData = getPasswordDataFromFile(passwordID);
            if (passwordData.id == 0) {
                printf("Password not found!\n");
            } else {
                printf("\nID: %d\n", passwordData.id);
                printf("Username: %s\n", passwordData.username);
                printf("Password: %s\n", passwordData.password);
            }
        } else if (strcmp(command, "exit") == 0) { // Exit program
            printf("Exiting program...\n");
            running = false;
        } else { // Invalid command
            printf("Invalid command!\n");
        }
    }

    return 0;
}