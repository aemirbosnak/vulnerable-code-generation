//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

// Function prototypes
int check_length(const char *password);
int check_lowercase(const char *password);
int check_uppercase(const char *password);
int check_digit(const char *password);
int check_special_char(const char *password);
int calculate_strength_score(const char *password);
void analyze_password(const char *password);

int main() {
    char password[100];

    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    analyze_password(password);

    return 0;
}

void analyze_password(const char *password) {
    int score = calculate_strength_score(password);
    
    printf("Password strength score: %d\n", score);
    
    if (score < 3) {
        printf("Password is Weak.\n");
    } else if (score < 5) {
        printf("Password is Fair.\n");
    } else if (score < 7) {
        printf("Password is Strong.\n");
    } else {
        printf("Password is Very Strong!\n");
    }
}

int calculate_strength_score(const char *password) {
    int score = 0;

    if (check_length(password))
        score++;
    if (check_lowercase(password))
        score++;
    if (check_uppercase(password))
        score++;
    if (check_digit(password))
        score++;
    if (check_special_char(password))
        score++;

    return score;
}

int check_length(const char *password) {
    int length = strlen(password);
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

int check_lowercase(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_uppercase(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_digit(const char *password) {
    for (int i = 0; password[i] != '\0'; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

int check_special_char(const char *password) {
    const char *special_characters = "!@#$%^&*()-+=<>?/|";
    for (int i = 0; password[i] != '\0'; i++) {
        if (strchr(special_characters, password[i])) {
            return 1;
        }
    }
    return 0;
}