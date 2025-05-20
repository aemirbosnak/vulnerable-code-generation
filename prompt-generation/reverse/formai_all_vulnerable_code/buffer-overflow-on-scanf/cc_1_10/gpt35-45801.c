//FormAI DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to System Admin Program!\n\n");

    // Display the menu
    printf("Please choose an option:\n");
    printf("1. Check system status\n");
    printf("2. Clear system cache\n");
    printf("3. Manage users\n");
    printf("4. Configure network settings\n");
    printf("5. Exit program\n");

    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            system("top");              // Check system status using the top command
            break;

        case 2:
            system("sudo sync && sudo echo 3 > /proc/sys/vm/drop_caches");   // Clear system cache using sync and drop_caches
            printf("System cache cleared successfully!\n");
            break;

        case 3:
            printf("Please choose an option:\n");
            printf("1. Add a new user\n");
            printf("2. Delete an existing user\n");

            int userOption;
            scanf("%d", &userOption);

            switch (userOption) {
                case 1:
                    system("sudo adduser");                 // Add a new user using adduser command
                    break;

                case 2:
                    printf("Please enter the username to delete: ");
                    char username[50];
                    scanf("%s", username);
                    char command[80] = "sudo userdel ";
                    strcat(command, username);
                    system(command);                       // Delete an existing user using userdel command
                    printf("%s has been deleted successfully!\n", username);
                    break;

                default:
                    printf("Invalid option selected!\n");
                    break;
            }
            break;

        case 4:
            printf("Please choose an option:\n");
            printf("1. Configure network interfaces\n");
            printf("2. Check network connectivity\n");

            int networkOption;
            scanf("%d", &networkOption);

            switch (networkOption) {
                case 1:
                    system("sudo nano /etc/network/interfaces");               // Configure network interfaces using nano editor
                    break;

                case 2:
                    system("ping google.com");                                  // Check network connectivity using ping command
                    break;

                default:
                    printf("Invalid option selected!\n");
                    break;
            }
            break;

        case 5:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid option selected!\n");
            break;
    }

    printf("\nThank you using our System Admin Program!\n");
    return 0;
}