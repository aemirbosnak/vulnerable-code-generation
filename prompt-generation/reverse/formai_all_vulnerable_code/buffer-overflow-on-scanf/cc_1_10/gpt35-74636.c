//FormAI DATASET v1.0 Category: System administration ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void display_menu() {
    printf("\n");
    printf("=====================================================================\n");
    printf("|                          ADMIN PANEL MENU                         |\n");
    printf("=====================================================================\n");
    printf("| 1. System Information         | 2. User Management                |\n");
    printf("| 3. File Management            | 4. Network Management             |\n");
    printf("| 5. Process Management         | 6. System Update                  |\n");
    printf("| 7. Exit                       |                                   |\n");
    printf("=====================================================================\n");
    printf("Enter your choice: ");
}

void system_info() {
    printf("\nSystem Information:\n");
    system("uname -a");
    printf("CPU Info:\n");
    system("lscpu");
    printf("Memory Info:\n");
    system("free -h");
    printf("Disk Space Info:\n");
    system("df -h");
}

void user_management() {
    printf("\nUser Management:\n");
    while (1) {
        printf("\n");
        printf("=====================================================\n");
        printf("|               USER MANAGEMENT MENU                |\n");
        printf("=====================================================\n");
        printf("| 1. Add new user               | 2. Delete a user  |\n");
        printf("| 3. Change user password       | 4. Back           |\n");
        printf("=====================================================\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter new user name: ");
                char new_username[20];
                scanf("%s", new_username);
                char add_user_cmd[50];
                sprintf(add_user_cmd, "adduser %s", new_username);
                system(add_user_cmd);
                break;
            
            case 2:
                printf("Enter the user name to delete: ");
                char del_username[20];
                scanf("%s", del_username);
                char del_user_cmd[50];
                sprintf(del_user_cmd, "deluser --remove-home %s", del_username);
                system(del_user_cmd);
                break;
            
            case 3:
                printf("Enter the user name to update password for: ");
                char pwd_username[20];
                scanf("%s", pwd_username);
                char pwd_cmd[50];
                sprintf(pwd_cmd, "passwd %s", pwd_username);
                system(pwd_cmd);
                break;
            
            case 4:
                return;
            
            default:
                printf("Invalid choice! Please enter the correct choice.\n");
                break;
        }
    }
}

void file_management() {
    printf("\nFile Management:\n");
    while (1) {
        printf("\n");
        printf("=====================================================\n");
        printf("|               FILE MANAGEMENT MENU               |\n");
        printf("=====================================================\n");
        printf("| 1. List files                 | 2. Create a file  |\n");
        printf("| 3. Delete a file              | 4. Back           |\n");
        printf("=====================================================\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Listing current directory files: \n");
                system("ls -al");
                break;
            
            case 2:
                printf("Enter the file name and content (separated by space): ");
                char filename[50], content[100];
                scanf("%s %s", filename, content);
                FILE *fp = fopen(filename, "w");
                if(fp != NULL) {
                    fprintf(fp, "%s", content);
                    printf("%s created successfully with content - %s\n", filename, content);
                    fclose(fp);
                }
                else {
                    printf("Error: Unable to create file %s\n", filename);
                }
                break;
            
            case 3:
                printf("Enter the file name to delete: ");
                char file_to_delete[50];
                scanf("%s", file_to_delete);
                char delete_cmd[50];
                sprintf(delete_cmd, "rm %s", file_to_delete);
                system(delete_cmd);
                break;
            
            case 4:
                return;
            
            default:
                printf("Invalid choice! Please enter the correct choice.\n");
                break;
        }
    }
}

void network_management() {
    printf("\nNetwork Management:\n");
    printf("Display network interfaces: \n");
    system("ifconfig");
}

void process_management() {
    printf("\nProcess Management:\n");
    printf("Displaying running processes: \n");
    system("ps -aux");
}

void system_update() {
    printf("\nSystem Update:\n");
    printf("Updating the system...\n");
    system("apt-get update && apt-get upgrade -y");
}

int main() {
    while (1) {
        display_menu();
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                system_info();
                break;
            
            case 2:
                user_management();
                break;
            
            case 3:
                file_management();
                break;
            
            case 4:
                network_management();
                break;
            
            case 5:
                process_management();
                break;
            
            case 6:
                system_update();
                break;
            
            case 7:
                printf("Exiting...\n");
                exit(0);
            
            default:
                printf("Invalid choice! Please enter the correct choice.\n");
                break;
        }
    }
    return 0;
}