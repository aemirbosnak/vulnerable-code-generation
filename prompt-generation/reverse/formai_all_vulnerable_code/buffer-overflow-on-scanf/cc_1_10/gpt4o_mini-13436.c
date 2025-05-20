//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

void display_options();
int get_valid_length();
void get_character_choices(int *use_upper, int *use_lower, int *use_digits, int *use_special);
void generate_password(char *password, int length, int use_upper, int use_lower, int use_digits, int use_special);
void fill_password(char *password, int length, int use_upper, int use_lower, int use_digits, int use_special);
void print_password(const char *password);

const char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";
const char digit_chars[] = "0123456789";
const char special_chars[] = "!@#$%^&*()-_=+[]{};:,.<>?";

int main() {
    srand(time(NULL));  // Seed for random number generation

    display_options();
    
    int length = get_valid_length();
    
    int use_upper, use_lower, use_digits, use_special;
    get_character_choices(&use_upper, &use_lower, &use_digits, &use_special);
    
    char password[MAX_LENGTH + 1];  // +1 for null terminator
    generate_password(password, length, use_upper, use_lower, use_digits, use_special);
    
    print_password(password);
    
    return 0;
}

void display_options() {
    printf("Secure Password Generator\n");
    printf("=========================\n");
}

int get_valid_length() {
    int length;
    do {
        printf("Enter the desired password length (1 to %d): ", MAX_LENGTH);
        scanf("%d", &length);
        if (length < 1 || length > MAX_LENGTH) {
            printf("Invalid length! Please try again.\n");
        }
    } while (length < 1 || length > MAX_LENGTH);
    return length;
}

void get_character_choices(int *use_upper, int *use_lower, int *use_digits, int *use_special) {
    *use_upper = 0, *use_lower = 0, *use_digits = 0, *use_special = 0;
    
    printf("Include uppercase letters? (1 for yes, 0 for no): ");
    scanf("%d", use_upper);
    
    printf("Include lowercase letters? (1 for yes, 0 for no): ");
    scanf("%d", use_lower);
    
    printf("Include digits? (1 for yes, 0 for no): ");
    scanf("%d", use_digits);
    
    printf("Include special characters? (1 for yes, 0 for no): ");
    scanf("%d", use_special);
    
    if (!(*use_upper || *use_lower || *use_digits || *use_special)) {
        printf("At least one character type must be selected. Defaulting to lowercase letters.\n");
        *use_lower = 1;
    }
}

void generate_password(char *password, int length, int use_upper, int use_lower, int use_digits, int use_special) {
    fill_password(password, length, use_upper, use_lower, use_digits, use_special);
    password[length] = '\0';  // Null terminate the password string
}

void fill_password(char *password, int length, int use_upper, int use_lower, int use_digits, int use_special) {
    int char_types = use_upper + use_lower + use_digits + use_special;
    if (char_types == 0) return;  // Should not occur due to early validation in get_character_choices
    
    for (int i = 0; i < length; ++i) {
        int type = rand() % char_types;
        
        if (type == 0 && use_upper) {
            password[i] = upper_chars[rand() % strlen(upper_chars)];
        } else if (type == 1 && use_lower) {
            password[i] = lower_chars[rand() % strlen(lower_chars)];
        } else if (type == 2 && use_digits) {
            password[i] = digit_chars[rand() % strlen(digit_chars)];
        } else if (type == 3 && use_special) {
            password[i] = special_chars[rand() % strlen(special_chars)];
        }
    }
}

void print_password(const char *password) {
    printf("Generated Password: %s\n", password);
}