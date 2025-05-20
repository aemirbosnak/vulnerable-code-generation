//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#define BUFFER_SIZE 1024

/**
 * Asynchronous Password Strength Checker
 **/

/* Password rules */
bool has_uppercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_lowercase(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (islower(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_digit(char* password) {
    for (int i = 0; i < strlen(password); i++) {
        if (isdigit(password[i])) {
            return true;
        }
    }
    return false;
}

bool has_special_char(char* password) {
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '='};
    int num_special_chars = sizeof(special_chars) / sizeof(special_chars[0]);

    for (int i = 0; i < strlen(password); i++) {
        for (int j = 0; j < num_special_chars; j++) {
            if (password[i] == special_chars[j]) {
                return true;
            }
        }
    }
    return false;
}

/* Child process signal handler */
void signal_child(int sig) {
    wait(NULL);
}

/* Main function */
int main() {
    char password[BUFFER_SIZE];
    int fd[2];

    /* Create pipe */
    if (pipe(fd) == -1) {
        perror("Pipe failed");
        exit(EXIT_FAILURE);
    }

    /* Fork child process */
    pid_t pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        /* Child process */

        /* Create signal handler for child process */
        signal(SIGINT, signal_child);

        /* Read password from pipe */
        char password[BUFFER_SIZE];
        if (read(fd[0], password, sizeof(password)) == -1) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        /* Check complexity of password */
        bool is_uppercase = has_uppercase(password);
        bool is_lowercase = has_lowercase(password);
        bool has_digit_char = has_digit(password);
        bool has_special_chars = has_special_char(password);
        int password_length = strlen(password);

        /* Output result to pipe */
        char complexity[BUFFER_SIZE];
        if (is_uppercase && is_lowercase && has_digit_char && has_special_chars && password_length >= 8) {
            snprintf(complexity, sizeof(complexity), "Strong password\n");
        } else {
            snprintf(complexity, sizeof(complexity), "Weak password\n");
        }

        if (write(fd[1], complexity, strlen(complexity)) == -1) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } else {
        /* Parent process */

        /* Set non-blocking read and write */
        fcntl(fd[0], F_SETFL, O_NONBLOCK);
        fcntl(fd[1], F_SETFL, O_NONBLOCK);

        /* Read password from user input */
        printf("Enter password: ");
        fgets(password, BUFFER_SIZE, stdin);
        password[strlen(password)-1] = '\0'; /* Remove newline character */

        /* Write password to pipe */
        if (write(fd[1], password, strlen(password)) == -1) {
            perror("Write failed");
            exit(EXIT_FAILURE);
        }

        /* Sleep for 1 second to allow child process to execute */
        sleep(1);

        /* Read result from pipe */
        char complexity[BUFFER_SIZE];
        if (read(fd[0], complexity, sizeof(complexity)) != -1) {
            printf("%s\n", complexity);
        } else {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }

        /* Close pipe */
        close(fd[0]);
        close(fd[1]);

        exit(EXIT_SUCCESS);
    }

    return 0;
}