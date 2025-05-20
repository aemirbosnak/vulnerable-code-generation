//FormAI DATASET v1.0 Category: System administration ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//function to display menu and get user choice
int menu() {
    int choice;
    printf("\n========= System Administration Program =========\n");
    printf("\n1. Check system information");
    printf("\n2. View running processes");
    printf("\n3. Kill a process");
    printf("\n4. Change system password");
    printf("\n5. Shutdown system");
    printf("\n6. Exit program");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

//function to check system information
void check_sys_info() {
    system("uname -a");
    system("uptime");
    system("df -h");
}

//function to view running processes
void view_processes() {
    system("ps -e");
}

//function to kill a process
void kill_process() {
    char pid[10];
    printf("Enter process ID to kill: ");
    scanf("%s", pid);
    char command[20];
    sprintf(command, "kill %s", pid);
    system(command);
}

//function to change system password
void change_password() {
    char newpass[20];
    printf("Enter new password: ");
    scanf("%s", newpass);
    char command[30];
    sprintf(command, "passwd %s", newpass);
    system(command);
}

//function to shutdown system
void shutdown_system() {
    system("shutdown now");
}

//main function
int main() {
    int choice;
    do {
        choice = menu();
        switch (choice) {
            case 1:
                check_sys_info();
                break;
            case 2:
                view_processes();
                break;
            case 3:
                kill_process();
                break;
            case 4:
                change_password();
                break;
            case 5:
                shutdown_system();
                break;
            case 6:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
        sleep(1); //pause for 1 second between each command
    } while (1);
    return 0;
}