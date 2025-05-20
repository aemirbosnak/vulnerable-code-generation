//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16
#define NUM_SPECIAL_CHARACTERS 10
#define ITERATIONS 1000

const char *special_chars = "!@#$%^&*()-_=+[]{};:'\",.<>?/";
const char *lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numeric_chars = "0123456789";

typedef struct {
    char *passwords;
    size_t count;
} PasswordList;

void init_password_list(PasswordList *list, size_t count) {
    list->count = count;
    list->passwords = (char *)malloc(count * (PASSWORD_LENGTH + 1) * sizeof(char));
    if (list->passwords == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
}

void free_password_list(PasswordList *list) {
    free(list->passwords);
    list->count = 0;
}

char get_random_char(const char *chars) {
    return chars[rand() % strlen(chars)];
}

void generate_password(char *password) {
    int i;
    password[0] = get_random_char(uppercase_chars); // Ensure at least one uppercase letter
    password[1] = get_random_char(lowercase_chars); // Ensure at least one lowercase letter
    password[2] = get_random_char(numeric_chars);   // Ensure at least one numeric character
    password[3] = get_random_char(special_chars);   // Ensure at least one special character

    for (i = 4; i < PASSWORD_LENGTH; ++i) {
        const char *all_chars = lowercase_chars;
        size_t all_chars_len = strlen(lowercase_chars);
        
        // Randomly mix in uppercase, lowercase, numbers, and special characters
        switch (rand() % 4) {
            case 0:
                all_chars = uppercase_chars; 
                all_chars_len = strlen(uppercase_chars);
                break;
            case 1:
                all_chars = lowercase_chars; 
                all_chars_len = strlen(lowercase_chars);
                break;
            case 2:
                all_chars = numeric_chars; 
                all_chars_len = strlen(numeric_chars);
                break;
            case 3:
                all_chars = special_chars; 
                all_chars_len = strlen(special_chars);
                break;
        }
        password[i] = get_random_char(all_chars);
    }
    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the password
}

void generate_passwords(PasswordList *list) {
    for (size_t i = 0; i < list->count; i++) {
        generate_password(&list->passwords[i * (PASSWORD_LENGTH + 1)]);
    }
}

void print_passwords(const PasswordList *list) {
    for (size_t i = 0; i < list->count; i++) {
        printf("Password %zu: %s\n", i + 1, &list->passwords[i * (PASSWORD_LENGTH + 1)]);
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator
    PasswordList password_list;

    printf("Welcome to the Secure Password Generator!\n");

    size_t password_count;
    printf("How many passwords would you like to generate? ");
    scanf("%zu", &password_count);

    init_password_list(&password_list, password_count);
    generate_passwords(&password_list);
    print_passwords(&password_list);
    free_password_list(&password_list);

    return 0;
}