//FormAI DATASET v1.0 Category: System administration ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// function to execute shell commands and return the output as a string
char* exec_shell_command(char* command) {
    char* result = malloc(1024);
    FILE* fp = popen(command, "r");
    fgets(result, 1024, fp);
    pclose(fp);
    return result;
}

int main() {
    printf("Welcome to the System Administration Example Program\n");
    printf("This program will help you perform various system administration tasks\n\n");

    int choice;
    while(1) {
        printf("Please select an option:\n");
        printf("1. View system information\n");
        printf("2. Restart the system\n");
        printf("3. View running processes\n");
        printf("4. Kill a process\n");
        printf("5. Exit the program\n");

        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:
                printf("System Information:\n");
                printf("Hostname: %s", exec_shell_command("hostname"));
                printf("Kernel Version: %s", exec_shell_command("uname -r"));
                printf("Operating System: %s", exec_shell_command("uname -o"));
                printf("CPU Details:\n%s", exec_shell_command("lscpu"));
                printf("Memory Usage:\n%s", exec_shell_command("free -m"));
                break;
            case 2:
                printf("Restarting the system...\n");
                int status = system("sudo shutdown -r now");
                if (status != 0) {
                    printf("Failed to restart the system\n");
                }
                break;
            case 3:
                printf("Running Processes:\n");
                system("ps aux");
                break;
            case 4:
                printf("Enter PID of process to kill: ");
                int pid;
                scanf("%d", &pid);
                printf("\n");
                char kill_command[100];
                sprintf(kill_command, "kill %d", pid);
                int kill_status = system(kill_command);
                if (kill_status != 0) {
                    printf("Failed to kill process with PID: %d\n", pid);
                }
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again\n");
                break;
        }
        printf("\n");
    }
    return 0;
}