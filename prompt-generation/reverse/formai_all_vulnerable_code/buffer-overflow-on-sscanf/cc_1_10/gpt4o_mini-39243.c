//GPT-4o-mini DATASET v1.0 Category: Database querying ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define NAME_LENGTH 30
#define FILENAME "database.txt"

typedef struct {
    int id;
    char name[NAME_LENGTH];
} User;

void addUser(int id, const char *name);
void viewUsers();
void deleteUser(int id);
void clearScreen();
void displayMenu();

int main() {
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter User ID: ");
                scanf("%d", &id);
                getchar(); // consume newline
                printf("Enter User Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                addUser(id, name);
                break;
                
            case 2:
                viewUsers();
                break;

            case 3:
                printf("Enter User ID to delete: ");
                scanf("%d", &id);
                deleteUser(id);
                break;

            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addUser(int id, const char *name) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "%d,%s\n", id, name);
    fclose(file);
    printf("User added successfully!\n");
}

void viewUsers() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    
    char line[100];
    printf("\nCurrent Users:\n");
    while (fgets(line, sizeof(line), file)) {
        int id;
        char name[NAME_LENGTH];
        sscanf(line, "%d,%[^\n]", &id, name);
        printf("ID: %d, Name: %s\n", id, name);
    }
    fclose(file);
}

void deleteUser(int id) {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Unable to create temp file");
        fclose(file);
        return;
    }
    
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        int currentId;
        sscanf(line, "%d", &currentId);
        
        if (currentId != id) {
            fprintf(tempFile, "%s", line);
        } else {
            found = 1;
        }
    }
    
    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(FILENAME);
        rename("temp.txt", FILENAME);
        printf("User with ID %d deleted successfully!\n", id);
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void clearScreen() {
    system("clear || cls");
}

void displayMenu() {
    clearScreen();
    printf("==== Simple User Database ====\n");
    printf("1. Add User\n");
    printf("2. View Users\n");
    printf("3. Delete User\n");
    printf("4. Exit\n");
    printf("==============================\n");
    printf("Enter your choice: ");
}