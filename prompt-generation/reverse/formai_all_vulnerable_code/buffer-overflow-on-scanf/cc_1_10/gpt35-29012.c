//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for illegal characters in input
int detect(const char *input) {
    char illegal[] = {'$', '#', '@', '`', '|', '^', '&', '\\', '%', '(', ')'};
    int len = strlen(input);
    for(int i=0; i<len; i++) {
        for(int j=0; j<sizeof(illegal); j++) {
            if(input[i] == illegal[j]) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char username[20];
    char password[20];
    int attempts = 0;

    printf("Fair warning! The intrusion detection system keeps an eye on you.\n");
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    while(detect(username) || detect(password)) {
        printf("Illegal characters detected! Please try again.\n");
        printf("\nEnter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);
    }

    // Intrusion detection starts here
    printf("Verifying login credentials...\n");
    while(attempts < 3) { // User has 3 attempts to enter correct credentials
        if(strcmp(username, "Romeo") == 0 && strcmp(password, "Rosel1ne") == 0) {
            printf("You have successfully logged in!\n");
            break;
        }
        else if(strcmp(username, "Juliet") == 0 && strcmp(password, "Capulet") == 0) {
            printf("You have successfully logged in!\n");
            break;
        }
        else {
            printf("Login failed. Please try again.\nEnter your username: ");
            scanf("%s", username);
            printf("Enter your password: ");
            scanf("%s", password);
        }
        attempts++;
    }
    if(attempts == 3) {
        printf("Intrusion detected. Your account has been locked.\n");
    }
    return 0;
}