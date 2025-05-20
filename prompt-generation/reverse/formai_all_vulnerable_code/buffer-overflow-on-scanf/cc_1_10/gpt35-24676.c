//FormAI DATASET v1.0 Category: Password management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Function prototype
void add_password();
void display_passwords();
void search_password();
void delete_password();

// Structure to hold password details
struct password {
    char website[50];
    char username[50];
    char pass[50];
} p;

// Function to display main menu
void menu() {
    int choice;
    printf("\n\nMenu");
    printf("\n1. Add Password");
    printf("\n2. Display Passwords");
    printf("\n3. Search Password");
    printf("\n4. Delete Password");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            add_password();
            break;
        case 2:
            display_passwords();
            break;
        case 3:
            search_password();
            break;
        case 4:
            delete_password();
            break;
        case 5:
            printf("\n\nThank you for using the program.");
            exit(0);
            break;
        default:
            printf("\nInvalid choice. Please try again.");
    }

    // Show menu again
    menu();
}

// Function to add new password
void add_password() {
    printf("\n\nAdd Password");
    printf("\nEnter website name: ");
    scanf("%s", p.website);
    printf("\nEnter username: ");
    scanf("%s", p.username);
    printf("\nEnter password: ");
    scanf("%s", p.pass);

    // Open file for writing
    FILE *fptr = fopen("passwords.txt", "a");
    if (fptr == NULL) {
        printf("\nError opening file.");
    } else {
        // Write to file
        fprintf(fptr, "%s %s %s\n", p.website, p.username, p.pass);
        printf("\nPassword added successfully.");
        // Close file
        fclose(fptr);
    }
}

// Function to display all passwords
void display_passwords() {
    printf("\n\nDisplay Passwords\n");
    // Open file for reading
    FILE *fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("\nError opening file.");
    } else {
        // Read from file and print
        while (fscanf(fptr, "%s %s %s", p.website, p.username, p.pass) != EOF) {
            printf("%s %s %s\n", p.website, p.username, p.pass);
        }
        // Close file
        fclose(fptr);
    }
}

// Function to search for a password
void search_password() {
    char s_web[50];
    printf("\n\nSearch Password");
    printf("\nEnter website name: ");
    scanf("%s", s_web);

    // Open file for reading
    FILE *fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("\nError opening file.");
    } else {
        int found = 0;
        // Read from file and search for website
        while (fscanf(fptr, "%s %s %s", p.website, p.username, p.pass) != EOF) {
            if (strcmp(p.website, s_web) == 0) {
                printf("\n\nWebsite: %s \nUsername: %s \nPassword: %s", p.website, p.username, p.pass);
                found = 1;
                break;
            }
        }
        // Close file
        fclose(fptr);
        if (!found) {
            printf("\n\nPassword not found.");
        }
    }
}

// Function to delete a password
void delete_password() {
    char d_web[50];
    printf("\n\nDelete Password");
    printf("\nEnter website name: ");
    scanf("%s", d_web);

    // Open file for reading
    FILE *fptr = fopen("passwords.txt", "r");
    if (fptr == NULL) {
        printf("\nError opening file.");
    } else {
        // Create temporary file for writing
        FILE *temp = fopen("temp.txt", "w");
        // Read from file, search for website and delete
        while (fscanf(fptr, "%s %s %s", p.website, p.username, p.pass) != EOF) {
            if (strcmp(p.website, d_web) != 0) {
                fprintf(temp, "%s %s %s\n", p.website, p.username, p.pass);
            } else {
                printf("\n\nPassword deleted successfully.");
            }
        }
        // Close files
        fclose(fptr);
        fclose(temp);
        // Delete old file
        remove("passwords.txt");
        // Rename temporary file to original file name
        rename("temp.txt", "passwords.txt");
    }
}

// Main function
int main() {
    printf("\n\nWelcome to Password Management Program.");
    menu();
    return 0;
}