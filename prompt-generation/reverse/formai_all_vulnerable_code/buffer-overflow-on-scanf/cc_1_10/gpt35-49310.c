//FormAI DATASET v1.0 Category: Password management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new password
void addPassword() {
    // Open the password file
    FILE *file = fopen("passwords.txt", "a");

    // Get the website name and password from the user
    char website[20];
    char password[20];
    printf("Enter the website name: ");
    scanf("%s", website);
    printf("Enter the password: ");
    scanf("%s", password);

    // Encrypt the password before writing it to the file
    char encrypted_password[20];
    // Encryption algorithm goes here...
    fprintf(file, "%s,%s\n", website, encrypted_password);

    // Close the file
    fclose(file);

    printf("Password added successfully!\n");
}

// Function to view saved passwords
void viewPasswords() {
    // Open the password file
    FILE *file = fopen("passwords.txt", "r");

    // Read each line of the file and print the website name
    char line[40];
    while (fgets(line, sizeof(line), file)) {
        char *website = strtok(line, ",");
        printf("%s\n", website);
    }

    // Close the file
    fclose(file);
}

// Function to retrieve a password
void retrievePassword() {
    // Open the password file
    FILE *file = fopen("passwords.txt", "r");

    // Get the website name from the user
    char website[20];
    printf("Enter the website name: ");
    scanf("%s", website);

    // Read each line of the file and search for the website
    char line[40];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        char *current_website = strtok(line, ",");
        char *current_password = strtok(NULL, ",");
        if (strcmp(current_website, website) == 0) {
            // Decrypt the password and print it to the user
            char decrypted_password[20];
            // Decryption algorithm goes here...
            printf("The password for %s is %s\n", website, decrypted_password);
            found = 1;
            break;
        }
    }

    // Close the file
    fclose(file);

    // Display an error message if the website is not found
    if (!found) {
        printf("Password not found!\n");
    }
}

int main() {
    int choice;
    do {
        // Display the menu options
        printf("\n1. Add password\n2. View passwords\n3. Retrieve password\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Call the appropriate function based on the user's choice
        switch (choice) {
            case 1:
                addPassword();
                break;
            case 2:
                viewPasswords();
                break;
            case 3:
                retrievePassword();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}