//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ATTEMPTS 5
#define PASSWORD_LENGTH 8
#define SECRET_WORD "overcast"

void clear_screen() {
    printf("\033[H\033[J"); // ANSI escape code to clear the screen
}

void generate_password(char *password) {
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int i;

    for(i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = characters[rand() % (sizeof(characters) - 1)];
    }
    password[PASSWORD_LENGTH] = '\0'; // Null terminate the string
}

void display_warning() {
    printf("\n!! WARNING: Unauthorized access detected !!\n");
    printf("This is a secure system. You are being monitored.\n\n");
}

int check_password(char *input_password) {
    // Simulating a complex check by requiring the input to start with 'secure'
    return strncmp(input_password, "secure", 6) == 0;
}

int is_overcast() {
    // Randomly return whether it's overcast (simulate paranoia)
    return rand() % 2;
}

void paranoid_mode() {
    char input_password[PASSWORD_LENGTH + 1];
    
    clear_screen();
    printf("Paranoid Mode Activated! Complete the password to proceed.\n");
    
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter password (try %d/%d): ", attempts + 1, MAX_ATTEMPTS);
        scanf("%s", input_password);
        
        if (check_password(input_password)) {
            printf("Access Granted. Welcome!\n");
            break;
        } else {
            // Fake alarm activation for failed attempts
            display_warning();
            attempts++;
        }
        
        if (attempts == MAX_ATTEMPTS) {
            printf("Maximum attempts reached. Exiting...\n");
            exit(EXIT_FAILURE);
        }
    }
}

void secret_message() {
    if (is_overcast()) {
        printf("Not all is as it seems... You might be followed...\n");
    } else {
        printf("Things seem clear, but watch your back!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    clear_screen();
    printf("Welcome to the Paranoid System!\n");
    
    paranoid_mode();

    printf("\nRunning System Check...\n");
    // Simulating a check for the secret word
    char user_input[20];
    printf("Please enter the secret word to continue: ");
    scanf("%s", user_input);
    
    if (strcmp(user_input, SECRET_WORD) == 0) {
        printf("Secret access granted...\n");
        secret_message();
    } else {
        printf("Access denied! You are in a risky zone.\n");
        display_warning();
        printf("Exiting...\n");
        exit(EXIT_FAILURE);
    }

    printf("You have navigated the paranoia successfully. System is stable.\n");
    return 0;
}