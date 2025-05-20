//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORDS 10

// Password structure to hold username and password
typedef struct Password {
    char *username;
    char *password;
} Password;

// Function to add a password to the password list
void add_password(Password *passwords, int *count) {
    if (*count >= MAX_PASSWORDS) {
        printf("Maximum number of passwords reached.\n");
        return;
    }
    
    Password new_password;
    new_password.username = malloc(sizeof(char)*20);
    new_password.password = malloc(sizeof(char)*20);
    
    printf("Enter username: ");
    scanf("%s", new_password.username);
    
    printf("Enter password: ");
    scanf("%s", new_password.password);
    
    passwords[*count] = new_password;
    (*count)++;
    
    printf("Password added.\n");
}

// Function to remove a password from the password list
void remove_password(Password *passwords, int *count) {
    if (*count == 0) {
        printf("There are no passwords to remove.\n");
        return;
    }
    
    int index;
    printf("Enter the index of the password to remove: ");
    scanf("%d", &index);
    
    if (index < 0 || index >= *count) {
        printf("Invalid index.\n");
        return;
    }
    
    free(passwords[index].username);
    free(passwords[index].password);
    
    for (int i = index; i < *count - 1; i++) {
        passwords[i] = passwords[i+1];
    }
    
    (*count)--;
    
    printf("Password removed.\n");
}

// Function to list all passwords in the password list
void list_passwords(Password *passwords, int count) {
    if (count == 0) {
        printf("There are no passwords to list.\n");
        return;
    }
    
    printf("List of passwords:\n");
    
    for (int i = 0; i < count; i++) {
        printf("%d. Username: %s, Password: %s\n", i, passwords[i].username, passwords[i].password);
    }
}

// Function to save the passwords to a file
void save_passwords(Password *passwords, int count, char *filename) {
    FILE *file = fopen(filename, "wb");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fwrite(&count, sizeof(int), 1, file);
    
    for (int i = 0; i < count; i++) {
        int username_length = strlen(passwords[i].username)+1;
        int password_length = strlen(passwords[i].password)+1;
        
        fwrite(&username_length, sizeof(int), 1, file);
        fwrite(passwords[i].username, sizeof(char), username_length, file);
        
        fwrite(&password_length, sizeof(int), 1, file);
        fwrite(passwords[i].password, sizeof(char), password_length, file);
    }
    
    fclose(file);
    
    printf("Passwords saved to file.\n");
}

// Function to load the passwords from a file
void load_passwords(Password *passwords, int *count, char *filename) {
    FILE *file = fopen(filename, "rb");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    
    fread(count, sizeof(int), 1, file);
    
    for (int i = 0; i < *count; i++) {
        int username_length;
        fread(&username_length, sizeof(int), 1, file);
        passwords[i].username = malloc(sizeof(char)*username_length);
        fread(passwords[i].username, sizeof(char), username_length, file);
        
        int password_length;
        fread(&password_length, sizeof(int), 1, file);
        passwords[i].password = malloc(sizeof(char)*password_length);
        fread(passwords[i].password, sizeof(char), password_length, file);
    }
    
    fclose(file);
    
    printf("Passwords loaded from file.\n");
}

int main() {
    Password passwords[MAX_PASSWORDS];
    int count = 0;
    char filename[20];
    
    while (1) {
        printf("Password Management System:\n");
        printf("1. Add password\n");
        printf("2. Remove password\n");
        printf("3. List passwords\n");
        printf("4. Save passwords to file\n");
        printf("5. Load passwords from file\n");
        printf("6. Exit program\n");
        printf("Enter your choice: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_password(passwords, &count);
                break;
            case 2:
                remove_password(passwords, &count);
                break;
            case 3:
                list_passwords(passwords, count);
                break;
            case 4:
                printf("Enter filename to save to: ");
                scanf("%s", filename);
                save_passwords(passwords, count, filename);
                break;
            case 5:
                printf("Enter filename to load from: ");
                scanf("%s", filename);
                load_passwords(passwords, &count, filename);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}