//Falcon-180B DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE 100

char input[MAX_LINE];

void sigchld_handler(int signo) {
    int status;
    waitpid(-1, &status, WNOHANG);
}

int is_number(char *str) {
    int i;
    for (i = 0; str[i]!= '\0'; i++) {
        if (!isdigit(str[i])) {
            return FALSE;
        }
    }
    return TRUE;
}

int main() {
    int choice;
    char *argv[3];
    pid_t childpid;
    int status;

    signal(SIGCHLD, sigchld_handler);

    while (TRUE) {
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a number.\n");
                    break;
                }
                argv[0] = "celsius_to_fahrenheit";
                argv[1] = input;
                childpid = fork();
                if (childpid == -1) {
                    printf("Error forking process.\n");
                    exit(1);
                } else if (childpid == 0) {
                    execvp("celsius_to_fahrenheit", argv);
                    exit(1);
                } else {
                    waitpid(childpid, &status, 0);
                }
                break;
            case 2:
                printf("Enter temperature in Fahrenheit: ");
                scanf("%s", input);
                if (!is_number(input)) {
                    printf("Invalid input. Please enter a number.\n");
                    break;
                }
                argv[0] = "fahrenheit_to_celsius";
                argv[1] = input;
                childpid = fork();
                if (childpid == -1) {
                    printf("Error forking process.\n");
                    exit(1);
                } else if (childpid == 0) {
                    execvp("fahrenheit_to_celsius", argv);
                    exit(1);
                } else {
                    waitpid(childpid, &status, 0);
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}