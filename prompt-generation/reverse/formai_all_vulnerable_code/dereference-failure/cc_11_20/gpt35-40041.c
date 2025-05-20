//FormAI DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 25
#define FILENAME "passwords.txt"

struct password {
    char service[MAX_LENGTH];
    char username[MAX_LENGTH];
    char password[MAX_LENGTH];
};

int main() {
    int choice, count = 0, i, found = 0;
    struct password * passwords;
    FILE * file_ptr;
    
    // Read passwords from file
    file_ptr = fopen(FILENAME, "r");
    if (file_ptr == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    while (fscanf(file_ptr, "%s %s %s", passwords[count].service, passwords[count].username, passwords[count].password) == 3) {
        count++;
        passwords = realloc(passwords, (count + 1) * sizeof(struct password));
    }
    fclose(file_ptr);
    
    // Start main loop
    while (1) {
        // Print menu
        printf("Password Management Menu\n");
        printf("------------------------\n");
        printf("1. View saved passwords\n");
        printf("2. Add a new password\n");
        printf("3. Search for a password\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Handle menu choice
        switch (choice) {
            // View passwords
            case 1:
                if (count == 0) {
                    printf("No passwords saved!\n");
                } else {
                    printf("Saved Passwords\n");
                    printf("----------------\n");
                    for (i = 0; i < count; i++) {
                        printf("%s: %s/%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                    }
                    printf("\n");
                }
                break;
            // Add new password
            case 2:
                printf("Enter service name: ");
                scanf("%s", passwords[count].service);
                printf("Enter username: ");
                scanf("%s", passwords[count].username);
                printf("Enter password: ");
                scanf("%s", passwords[count].password);
                count++;
                passwords = realloc(passwords, (count + 1) * sizeof(struct password));
                file_ptr = fopen(FILENAME, "a");
                fprintf(file_ptr, "%s %s %s\n", passwords[count-1].service, passwords[count-1].username, passwords[count-1].password);
                fclose(file_ptr);
                printf("Password added successfully!\n");
                break;
            // Search for password
            case 3:
                printf("Enter service name: ");
                char search_service[MAX_LENGTH];
                scanf("%s", search_service);
                for (i = 0; i < count; i++) {
                    if (strcmp(passwords[i].service, search_service) == 0) {
                        printf("%s: %s/%s\n", passwords[i].service, passwords[i].username, passwords[i].password);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("No password found for service %s\n", search_service);
                }
                break;
            // Quit
            case 4:
                printf("Goodbye!\n");
                free(passwords);
                return 0;
            // Invalid choice
            default:
                printf("Invalid choice, try again.\n");
                break;
        }
    }
}