//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("Welcome to the Brave System Administration Example Program!\n");
    printf("This program allows you to manage user accounts and files on your system.\n");

    int option;

    // Loop until user chooses to exit the program
    while (1) {
        printf("\nPlease select an option:\n");
        printf("1. Create new user account\n");
        printf("2. Delete user account\n");
        printf("3. View all user accounts\n");
        printf("4. Create new file\n");
        printf("5. Delete file\n");
        printf("6. View all files\n");
        printf("7. Exit program\n");

        printf("Option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option) {
            case 1: {
                char username[20];
                printf("Enter username to create: ");
                scanf("%s", username);
                char command[30];
                sprintf(command, "sudo useradd %s", username);
                system(command);
                printf("User account %s created successfully.\n", username);
                break;
            }
            case 2: {
                char username[20];
                printf("Enter username to delete: ");
                scanf("%s", username);
                char command[30];
                sprintf(command, "sudo userdel %s", username);
                system(command);
                printf("User account %s deleted successfully.\n", username);
                break;
            }
            case 3: {
                system("cut -d: -f1 /etc/passwd");
                break;
            }
            case 4: {
                char filename[20];
                printf("Enter filename to create: ");
                scanf("%s", filename);
                FILE *file = fopen(filename, "w");
                if (file) {
                    printf("File %s created successfully.\n", filename);
                    fclose(file);
                } else {
                    printf("Error creating file.\n");
                }
                break;
            }
            case 5: {
                char filename[20];
                printf("Enter filename to delete: ");
                scanf("%s", filename);
                char command[30];
                sprintf(command, "sudo rm %s", filename);
                system(command);
                printf("File %s deleted successfully.\n", filename);
                break;
            }
            case 6: {
                system("ls -l");
                break;
            }
            case 7: {
                printf("Exiting program...\n");
                exit(0);
            }
            default: {
                printf("Invalid option, please try again.\n");
                break;
            }
        }
    }

    return 0;
}