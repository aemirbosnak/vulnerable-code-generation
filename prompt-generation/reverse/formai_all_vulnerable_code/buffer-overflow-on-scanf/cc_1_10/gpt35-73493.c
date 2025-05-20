//FormAI DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME 20
#define MAX_PASSWORD 20

void createNewUser(char *username, char *password);
void deleteUser(char *username);
void changeUserPassword(char *username, char *old_password, char *new_password);
void displayAllUsers();

struct User
{
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
};

int main()
{
    int choice;
    char username[MAX_USERNAME];
    char password[MAX_PASSWORD];
    char new_password[MAX_PASSWORD];
    
    while (1)
    {
        printf("MENU\n");
        printf("1. Create new user\n");
        printf("2. Delete user\n");
        printf("3. Change user password\n");
        printf("4. Display all users\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
            {
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                createNewUser(username, password);
                printf("%s user created successfully!\n", username);
                break;
            }
            case 2:
            {
                printf("Enter username to delete: ");
                scanf("%s", username);
                deleteUser(username);
                printf("%s user deleted successfully!\n", username);
                break;
            }
            case 3:
            {
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter old password: ");
                scanf("%s", password);
                printf("Enter new password: ");
                scanf("%s", new_password);
                changeUserPassword(username, password, new_password);
                printf("%s password changed successfully!\n", username);
                break;
            }
            case 4:
            {
                displayAllUsers();
                break;
            }
            case 5:
            {
                printf("Exiting program...\n");
                exit(0);
            }
            default:
            {
                printf("Invalid choice! Please try again.\n");
                break;
            }
        }
        printf("\n");
    }
    
    return 0;
}

void createNewUser(char *username, char *password)
{
    struct User newUser;
    strcpy(newUser.username, username);
    strcpy(newUser.password, password);
    
    FILE *file = fopen("users.dat", "ab");
    fwrite(&newUser, sizeof(struct User), 1, file);
    fclose(file);
}

void deleteUser(char *username)
{
    struct User currentUser;
    
    FILE *inputFile = fopen("users.dat", "rb");
    FILE *outputFile = fopen("temp.dat", "wb");
    
    while (fread(&currentUser, sizeof(struct User), 1, inputFile))
    {
        if (strcmp(currentUser.username, username) != 0)
        {
            fwrite(&currentUser, sizeof(struct User), 1, outputFile);
        }
    }
    
    fclose(inputFile);
    fclose(outputFile);
    remove("users.dat");
    rename("temp.dat", "users.dat");
}

void changeUserPassword(char *username, char *old_password, char *new_password)
{
    struct User currentUser;
    
    FILE *inputFile = fopen("users.dat", "rb");
    FILE *outputFile = fopen("temp.dat", "wb");
    
    while (fread(&currentUser, sizeof(struct User), 1, inputFile))
    {
        if (strcmp(currentUser.username, username) == 0 && strcmp(currentUser.password, old_password) == 0)
        {
            strcpy(currentUser.password, new_password);
        }
        fwrite(&currentUser, sizeof(struct User), 1, outputFile);
    }
    
    fclose(inputFile);
    fclose(outputFile);
    remove("users.dat");
    rename("temp.dat", "users.dat");
}

void displayAllUsers()
{
    struct User currentUser;
    int count = 1;
    
    FILE *file = fopen("users.dat", "rb");
    printf("All registered users:\n");
    while (fread(&currentUser, sizeof(struct User), 1, file))
    {
        printf("%d. Username: %s, Password: %s\n", count, currentUser.username, currentUser.password);
        count++;
    }
    fclose(file);
}