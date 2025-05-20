//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 16

const char SPECIAL_CHARS[] = "!@#$%^&*()-_=+[]{}|;:,.<>?";

void generate_password(char* password, int length) {
    int i;
    char c;
    srand(time(NULL));
    for (i = 0; i < length; i++) {
        do {
            c = rand() % 127;
        } while (!isalnum(c));
        password[i] = c;    
    }
}

void add_special_chars(char* password, int num_special_chars) {
    int i, len;
    len = strlen(password);
    for (i = 0; i < num_special_chars; i++) {
        password[len - i - 1] = SPECIAL_CHARS[rand() % strlen(SPECIAL_CHARS)];
    }
}

int main() {
    int i, length, num_special_chars;
    char password[MAX_LENGTH + 1];
    printf("Enter password length (between %d and %d): ", MIN_LENGTH, MAX_LENGTH);
    scanf("%d", &length);
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length!\n");
        return 1; // error code
    }
    generate_password(password, length);
    printf("Your password is: %s\n", password);
    printf("Do you want to add special characters? (y/n) ");
    char answer = getchar();
    if (answer == 'y' || answer == 'Y') {
        printf("How many special characters do you want to add? ");
        scanf("%d", &num_special_chars);
        if (num_special_chars < 1 || num_special_chars >= length) {
            printf("Invalid number of special characters!\n");
            return 1; // error code
        }
        add_special_chars(password, num_special_chars);
    }
    printf("Your final password is: %s\n", password);
    return 0; // success code
}