//FormAI DATASET v1.0 Category: System administration ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main() {
    int password_attempts = 0;
    char password[20];

    printf("Welcome to the futuristic system administration program.\n");
    printf("Please enter your password to access the system: ");
    scanf("%s", password);

    while (password_attempts < 3) {
        if (strcmp(password, "myfuturisticpassword") == 0) {
            printf("Access granted!\n");
            break;
        }
        else {
            printf("Incorrect password. Please try again.\n");
            password_attempts++;
            printf("Password attempts remaining: %d\n", 3 - password_attempts);
            printf("Enter password: ");
            scanf("%s", password);
        }
    }

    if (password_attempts >= 3) {
        printf("Maximum password attempts exceeded. System locked.\n");
        exit(EXIT_FAILURE);
    }

    int choice;
    printf("Please choose an option:\n");
    printf("1. Display system status\n");
    printf("2. Start system backup\n");
    printf("3. Simulate system crash\n");
    printf("4. Exit program\n");

    while (1) {
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("System is currently running.\n");
                break;
            case 2:
                printf("Starting system backup...\n");
                sleep(5); // simulate backup process
                printf("Backup completed successfully.\n");
                break;
            case 3:
                printf("Simulating system crash...\n");
                for (int i=0; i<10; i++) {
                    printf("Error %d: %s\n", errno, strerror(errno)); // print fake error messages
                    sleep(1);
                }
                printf("Crash simulation complete.\n");
                break;
            case 4:
                printf("Exiting program...\n");
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}