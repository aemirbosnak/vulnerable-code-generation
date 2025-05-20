//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MIN_LENGTH 12
#define MAX_LENGTH 20
#define NUM_SPECIAL_CHARS 10

const char *specialChars = "!@#$%^&*()-=_+[]{}|;:'\",.<>?/`~";
const char *upperChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *lowerChars = "abcdefghijklmnopqrstuvwxyz";
const char *digitChars = "0123456789";

void paranoid_warning() {
    printf("#########################\n");
    printf("#   WARNING! WARNING!   #\n");
    printf("# For your security,   #\n");
    printf("# DO NOT share your     #\n");
    printf("# passwords with anyone!#\n");
    printf("#########################\n\n");
}

int is_strength_valid(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    for (int i = 0; i < strlen(password); i++) {
        if (strchr(upperChars, password[i])) hasUpper = 1;
        else if (strchr(lowerChars, password[i])) hasLower = 1;
        else if (strchr(digitChars, password[i])) hasDigit = 1;
        else if (strchr(specialChars, password[i])) hasSpecial = 1;
    }
    
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

void generate_secure_password(char *password, int length) {
    int i;
    char *allChars = malloc(strlen(upperChars) + strlen(lowerChars) + strlen(digitChars) + strlen(specialChars) + 1);

    // Concatenate all character sets into one array
    strcpy(allChars, upperChars);
    strcat(allChars, lowerChars);
    strcat(allChars, digitChars);
    strcat(allChars, specialChars);

    srand(time(NULL) ^ getpid()); // Secure random seed for generation
    for (i = 0; i < length; i++) {
        password[i] = allChars[rand() % (strlen(allChars))]; // Randomly choose a character
    }
    password[length] = '\0'; // Null-terminate the password

    free(allChars);
}

void prompt_for_password_length(int *length) {
    printf("Enter desired password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", length);

    // Ensuring the password length is within bounds
    while (*length < MIN_LENGTH || *length > MAX_LENGTH) {
        printf("Invalid length! Please enter a length between %d and %d: ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", length);
    }
}

int main() {
    char password[MAX_LENGTH + 1];
    int length;

    paranoid_warning();
    prompt_for_password_length(&length);

    do {
        generate_secure_password(password, length);
    } while (!is_strength_valid(password));

    printf("Your secure password is: %s\n", password);
    printf("Store it safely! Never share it with anyone. Understand? It's YOURS!\n");

    return 0;
}