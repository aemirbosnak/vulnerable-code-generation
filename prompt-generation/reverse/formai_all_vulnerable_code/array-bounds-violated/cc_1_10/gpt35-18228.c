//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM_ATTEMPTS 5    // Maximum number of attempts to enter the correct password
#define MINIMUM_PASSWORD_LENGTH 8  // Minimum length of the password
#define MAXIMUM_PASSWORD_LENGTH 20 // Maximum length of the password

#define INTRUSION_DETECTED_MSG "INTRUSION DETECTED! SENDING ALERT..."
#define INDENTATION "    "

// Function prototypes
int authenticate();
void clear_buffer();
void log_attempt(int attempt_num, int max_attempts);
void send_alert();

int main() {
    int num_attempts = 0;
    int authenticated = 0;

    // Loop until the user is authenticated or has exceeded the maximum number of attempts.
    while(num_attempts < MAXIMUM_ATTEMPTS && !authenticated) {
        printf("Enter Password: ");
        authenticated = authenticate();
        if(!authenticated) {
            log_attempt(num_attempts, MAXIMUM_ATTEMPTS);
            num_attempts++;
            if(num_attempts == MAXIMUM_ATTEMPTS) {
                send_alert();
            }
        }
    }
    // If authenticated, display welcome message.
    if(authenticated) {
        printf("\n%sAccess granted. Welcome!\n", INDENTATION);
    }

    return 0;
}

int authenticate() {
    char password[MAXIMUM_PASSWORD_LENGTH + 1];
    int length, lower = 0, upper = 0, number = 0, special = 0;

    fgets(password, MAXIMUM_PASSWORD_LENGTH + 1, stdin);
    length = strlen(password) - 1;
    if(password[length] == '\n') {    // Remove newline character at the end (if exists)
        password[length] = '\0';
    }
    clear_buffer();

    // Check password length
    if(length < MINIMUM_PASSWORD_LENGTH) {
        printf("%sPassword must be at least %d characters long.\n", INDENTATION, MINIMUM_PASSWORD_LENGTH);
        return 0;
    }

    // Check password requirements
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            lower = 1;
        } else if(password[i] >= 'A' && password[i] <= 'Z') {
            upper = 1;
        } else if(password[i] >= '0' && password[i] <= '9') {
            number = 1;
        } else {
            special = 1;
        }
    }
    if(!(lower && upper && number && special)) {
        printf("%sPassword must contain at least one lowercase letter, one uppercase letter, one digit, and one special character.\n", INDENTATION);
        return 0;
    }

    return 1;
}

void clear_buffer() {
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void log_attempt(int attempt_num, int max_attempts) {
    printf("%sIncorrect password. Attempt %d/%d.\n", INDENTATION, attempt_num + 1, max_attempts);
}

void send_alert() {
    printf("%s%s\n", INDENTATION, INTRUSION_DETECTED_MSG);
    // A function to send an alert (e.g. by email, SMS, or push notification) could be implemented here.
}