//Code Llama-13B DATASET v1.0 Category: Password management ; Style: expert-level
int main() {
    // Declare variables
    char username[20];
    char password[20];
    char confirm_password[20];
    char new_password[20];
    char new_confirm_password[20];
    int choice;
    int status;

    // Initialize variables
    strcpy(username, "");
    strcpy(password, "");
    strcpy(confirm_password, "");
    strcpy(new_password, "");
    strcpy(new_confirm_password, "");
    choice = 0;
    status = 0;

    // Print menu
    printf("Welcome to the password management system\n");
    printf("1. Create a new password\n");
    printf("2. Change existing password\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    // Create a new password
    if (choice == 1) {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your new password: ");
        scanf("%s", new_password);
        printf("Confirm your new password: ");
        scanf("%s", new_confirm_password);
        if (strcmp(new_password, new_confirm_password) == 0) {
            status = 1;
            printf("Password created successfully\n");
        } else {
            printf("Passwords do not match\n");
        }
    }

    // Change existing password
    else if (choice == 2) {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your current password: ");
        scanf("%s", password);
        printf("Enter your new password: ");
        scanf("%s", new_password);
        printf("Confirm your new password: ");
        scanf("%s", new_confirm_password);
        if (strcmp(new_password, new_confirm_password) == 0) {
            status = 1;
            printf("Password changed successfully\n");
        } else {
            printf("Passwords do not match\n");
        }
    }

    // Exit
    else if (choice == 3) {
        status = 1;
        printf("Exiting the system\n");
    }

    // Invalid choice
    else {
        printf("Invalid choice\n");
    }

    // Display status
    if (status == 1) {
        printf("Status: Success\n");
    } else {
        printf("Status: Failure\n");
    }

    return 0;
}