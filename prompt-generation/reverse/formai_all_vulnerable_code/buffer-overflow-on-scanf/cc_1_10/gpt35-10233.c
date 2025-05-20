//FormAI DATASET v1.0 Category: System administration ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int status;
    printf("Welcome to the system administrator program.\n");
    printf("Please choose one of the following menu options:\n");
    printf("1. Check system load\n");
    printf("2. Check disk usage\n");
    printf("3. Restart a service\n");
    printf("4. Quit\n");

    int choice;
    char service[50];

    scanf("%d", &choice);

    switch(choice) {
        case 1:
            // Check system load
            system("uptime");
            break;
        case 2:
            // Check disk usage
            system("df -h");
            break;
        case 3:
            // Restart a service
            printf("Please enter the name of the service you would like to restart: ");
            scanf("%s", service);

            pid = fork();

            if (pid == 0) {
                // Child process
                execl("/usr/sbin/service", "/usr/sbin/service", service, "restart", NULL);
                exit(0);
            } else if (pid < 0) {
                printf("Error: Failed to fork process.");
                exit(1);
            } else {
                // Parent process
                waitpid(pid, &status, 0);
            }
            break;
        case 4:
            // Quit
            printf("Goodbye!\n");
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
            break;
    }

    return 0;
}