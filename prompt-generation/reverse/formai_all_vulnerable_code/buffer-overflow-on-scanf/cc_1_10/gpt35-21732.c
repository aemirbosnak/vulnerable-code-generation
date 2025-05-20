//FormAI DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for system administrator account
typedef struct {
    char username[20];
    char password[20];
} SysAdmin;

// Function declarations
void createAccount();
void login();
void changePassword();
void shutdown();

// Global variable for current logged-in sys admin
SysAdmin currentAdmin;

int main() {
    int choice;

    // Main menu loop
    while(1) {
        printf("\nWelcome, System Administrator!\n");
        printf("1. Create Account\n");
        printf("2. Login\n");
        printf("3. Shutdown System\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount();
                break;
            case 2:
                login();
                break;
            case 3:
                shutdown();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to create a new system administrator account
void createAccount() {
    SysAdmin newAdmin;

    printf("\nEnter username: ");
    scanf("%s", newAdmin.username);

    printf("Enter password: ");
    scanf("%s", newAdmin.password);

    // Save the new admin account information to file
    FILE *adminFile = fopen("sysAdmins.dat", "ab");
    fwrite(&newAdmin, sizeof(SysAdmin), 1, adminFile);
    fclose(adminFile);

    printf("\nAccount created successfully.\n");
}

// Function to log in as a system administrator
void login() {
    SysAdmin admin;
    int loginAttempts = 0;

    // Loop for login attempts
    while(loginAttempts < 3) {
        printf("\nEnter username: ");
        scanf("%s", admin.username);

        printf("Enter password: ");
        scanf("%s", admin.password);

        // Open file of sys admins and check for matching credentials
        FILE *adminFile = fopen("sysAdmins.dat", "rb");
        while(fread(&currentAdmin, sizeof(SysAdmin), 1, adminFile)) {
            if(strcmp(admin.username, currentAdmin.username) == 0 && strcmp(admin.password, currentAdmin.password) == 0) {
                printf("\nLogged in successfully!\n");
                fclose(adminFile);
                return;
            }
        }
        fclose(adminFile);

        printf("Invalid username or password. Please try again.\n");
        loginAttempts++;
    }

    printf("Too many failed login attempts. System locked for security purposes.\n");
}

// Function to change the password of the currently logged-in sys admin
void changePassword() {
    SysAdmin newAdmin;

    printf("\nEnter new password: ");
    scanf("%s", newAdmin.password);

    // Open file of sys admins and find the current admin to update password
    FILE *adminFile = fopen("sysAdmins.dat", "rb+");
    while(fread(&currentAdmin, sizeof(SysAdmin), 1, adminFile)) {
        if(strcmp(currentAdmin.username, newAdmin.username) == 0) {
            fseek(adminFile, -sizeof(SysAdmin), SEEK_CUR);
            fwrite(&newAdmin, sizeof(SysAdmin), 1, adminFile);
            fclose(adminFile);
            printf("\nPassword changed successfully.\n");
            return;
        }
    }
    fclose(adminFile);

    printf("Error: could not change password.\n");
}

// Function to shut down the system
void shutdown() {
    printf("\nShutting down system...\n");
    // Perform system shutdown procedures
    exit(0);
}