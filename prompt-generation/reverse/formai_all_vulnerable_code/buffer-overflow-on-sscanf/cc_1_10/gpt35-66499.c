//FormAI DATASET v1.0 Category: System boot optimizer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

void strLower(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char buffer[BUFFER_SIZE], username[BUFFER_SIZE], password[BUFFER_SIZE];
    int attempts = 0;

    printf("Welcome to the C System Boot Optimizer! Please enter your login credentials below.\n");

    while (attempts < 3) {
        attempts++;
        
        printf("\nUsername: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        sscanf(buffer, "%s", username);
        strLower(username);

        printf("Password: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        sscanf(buffer, "%s", password);
        strLower(password);

        if (strcmp(username, "admin") != 0 || strcmp(password, "password") != 0) {
            printf("Invalid login credentials. Please try again.\n");
        }
        else {
            printf("Login successful!\n");
            break;
        }
    }

    if (attempts == 3) {
        printf("Too many incorrect login attempts. Access denied.\n");
    }
    else {
        printf("\nThank you for using the C System Boot Optimizer.\n");
        printf("Optimizing boot sequence...\n");
        // Add boot optimization code here!
        printf("Boot sequence optimized!\n");
    }

    return EXIT_SUCCESS;
}