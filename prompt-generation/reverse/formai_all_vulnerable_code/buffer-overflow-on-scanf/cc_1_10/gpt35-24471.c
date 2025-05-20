//FormAI DATASET v1.0 Category: Password management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void add_password();
void view_all_passwords();
void search_password();
void update_password();
void delete_password();
int is_valid_password(char password[]);

// Password structure
struct Password {
    char website[50];
    char username[50];
    char password[50];
};

int main() {
    int option;
    do {
        printf("\n\nMENU\n");
        printf("1. Add a password\n");
        printf("2. View all passwords\n");
        printf("3. Search a password\n");
        printf("4. Update a password\n");
        printf("5. Delete a password\n");
        printf("6. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                add_password();
                break;
            case 2:
                view_all_passwords();
                break;
            case 3:
                search_password();
                break;
            case 4:
                update_password();
                break;
            case 5:
                delete_password();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (option != 6);

    return 0;
}

// Add Password function
void add_password() {
    printf("\nADD PASSWORD\n");

    // Create new password structure
    struct Password password;

    // Get website
    printf("Enter website: ");
    scanf("%s", password.website);

    // Get username
    printf("Enter username: ");
    scanf("%s", password.username);

    // Get password
    char password_string[50];
    printf("Enter password: ");
    scanf("%s", password_string);

    // Validate password
    if (is_valid_password(password_string)) {
        // Store password into structure
        strcpy(password.password, password_string);

        // Open password file in append mode
        FILE *file = fopen("passwords.txt", "a");

        // Write to file
        fprintf(file, "%s, %s, %s\n", password.website, password.username, password.password);

        // Close file
        fclose(file);

        printf("Password added successfully!\n");
    } else {
        printf("Invalid password. Password must be at least 8 characters long and contain at least one digit and one uppercase letter.\n");
    }
}

// View All Passwords function
void view_all_passwords() {
    printf("\nVIEW ALL PASSWORDS\n");

    // Open password file in read mode
    FILE *file = fopen("passwords.txt", "r");

    // Read file and print each line
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    // Close file
    fclose(file);
}

// Search Password function
void search_password() {
    printf("\nSEARCH PASSWORD\n");

    // Get search query from user
    char query[50];
    printf("Enter something to search for: ");
    scanf("%s", query);

    // Open password file in read mode
    FILE *file = fopen("passwords.txt", "r");

    // Read file and print matching lines
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, query) != NULL) {
            printf("%s", line);
            found = 1;
        }
    }

    // Close file
    fclose(file);

    // Display message if no matching passwords found
    if (!found) {
        printf("No matching passwords found.\n");
    }
}

// Update Password function
void update_password() {
    printf("\nUPDATE PASSWORD\n");

    // Get website to update
    char website[50];
    printf("Enter website to update: ");
    scanf("%s", website);

    // Open password file in read mode
    FILE *file = fopen("passwords.txt", "r");

    // Create temporary file to store updated passwords
    FILE *temp_file = fopen("temp.txt", "w");

    // Read file and update matching password
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if line contains website to update
        if (strstr(line, website) != NULL) {
            // Get new password
            char password_string[50];
            printf("Enter new password: ");
            scanf("%s", password_string);

            // Validate password
            if (is_valid_password(password_string)) {
                // Update password in structure
                struct Password password;
                char *token = strtok(line, ", ");
                strcpy(password.website, token);
                token = strtok(NULL, ", ");
                strcpy(password.username, token);
                strcpy(password.password, password_string);

                // Write updated password to temporary file
                fprintf(temp_file, "%s, %s, %s\n", password.website, password.username, password.password);

                found = 1;

                printf("Password updated successfully!\n");
            } else {
                printf("Invalid password. Password must be at least 8 characters long and contain at least one digit and one uppercase letter.\n");
                // Write original password to temporary file
                fprintf(temp_file, "%s", line);
            }
        } else {
            // Write original password to temporary file
            fprintf(temp_file, "%s", line);
        }
    }

    // Close files
    fclose(file);
    fclose(temp_file);

    // Replace original file with temporary file
    remove("passwords.txt");
    rename("temp.txt", "passwords.txt");

    // Display message if website not found
    if (!found) {
        printf("Website not found.\n");
    }
}

// Delete Password function
void delete_password() {
    printf("\nDELETE PASSWORD\n");

    // Get website to delete
    char website[50];
    printf("Enter website to delete: ");
    scanf("%s", website);

    // Open password file in read mode
    FILE *file = fopen("passwords.txt", "r");

    // Create temporary file to store remaining passwords
    FILE *temp_file = fopen("temp.txt", "w");

    // Read file and delete matching password
    char line[100];
    int found = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // Check if line does not contain website to delete
        if (strstr(line, website) == NULL) {
            // Write password to temporary file
            fprintf(temp_file, "%s", line);
        } else {
            found = 1;
            printf("Password deleted successfully!\n");
        }
    }

    // Close files
    fclose(file);
    fclose(temp_file);

    // Replace original file with temporary file
    remove("passwords.txt");
    rename("temp.txt", "passwords.txt");

    // Display message if website not found
    if (!found) {
        printf("Website not found.\n");
    }
}

// Password Validation function
int is_valid_password(char password[]) {
    int length = strlen(password);
    // Check length is at least 8 characters
    if (length < 8) {
        return 0;
    }
    // Check for at least one digit
    int has_digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }
    if (!has_digit) {
        return 0;
    }
    // Check for at least one uppercase letter
    int has_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }
    if (!has_uppercase) {
        return 0;
    }

    // If no validation errors, return 1
    return 1;
}