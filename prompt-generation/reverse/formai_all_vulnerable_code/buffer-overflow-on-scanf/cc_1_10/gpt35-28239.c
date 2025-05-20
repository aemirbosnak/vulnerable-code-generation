//FormAI DATASET v1.0 Category: System administration ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    system("clear"); // clear the terminal window

    // Display welcome message
    printf("Welcome to our System Administration Example Program!\n");
    printf("Please enter your username: ");

    char username[20];
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0; // remove the newline character at the end

    // Display menu options
    int option;
    do {
        printf("\nWelcome, %s!\n", username);
        printf("Please select an option:\n");
        printf("1. Display current system settings\n");
        printf("2. Update system settings\n");
        printf("3. Run system diagnostic tests\n");
        printf("4. Exit program\n");
        printf("Option: ");

        scanf("%d", &option);
        getchar(); // consume the newline character left by scanf()

        switch (option) {
            case 1:
                system("echo 'Current system settings:'");
                system("cat /etc/os-release");
                break;
            case 2:
                printf("Please enter the new system hostname: ");

                char hostname[20];
                fgets(hostname, sizeof(hostname), stdin);
                hostname[strcspn(hostname, "\n")] = 0;

                char command[50];
                sprintf(command, "hostnamectl set-hostname %s", hostname);
                system(command);
                break;
            case 3:
                system("echo 'Running system diagnostic tests:'");
                system("echo 'Test 1: CPU Stress Test'");
                system("stress -c 2 -t 10s");
                system("echo 'Test 2: Memory Stress Test'");
                system("stress -m 2 -t 10s");
                break;
            case 4:
                break;
            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (option != 4);

    // Display exit message
    printf("\nThank you for using our System Administration Example Program.\n");
}