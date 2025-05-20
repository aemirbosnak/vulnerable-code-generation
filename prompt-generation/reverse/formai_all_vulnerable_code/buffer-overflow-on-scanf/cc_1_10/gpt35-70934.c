//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

// function to generate a secure password
char* generate_password(int length, int use_lowercase, int use_uppercase, int use_numbers, int use_special_chars) {

    char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char special_chars[] = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";

    // calculate size of character set based on user preferences
    int char_set_size = 0;
    if (use_lowercase) char_set_size += sizeof(lowercase_chars) - 1;
    if (use_uppercase) char_set_size += sizeof(uppercase_chars) - 1;
    if (use_numbers) char_set_size += sizeof(numbers) - 1;
    if (use_special_chars) char_set_size += sizeof(special_chars) - 1;

    // create character set array
    char char_set[char_set_size];
    int i = 0;
    if (use_lowercase) {
        for (int j = 0; j < sizeof(lowercase_chars) - 1; j++) {
            char_set[i] = lowercase_chars[j];
            i++;
        }
    }
    if (use_uppercase) {
        for (int j = 0; j < sizeof(uppercase_chars) - 1; j++) {
            char_set[i] = uppercase_chars[j];
            i++;
        }
    }
    if (use_numbers) {
        for (int j = 0; j < sizeof(numbers) - 1; j++) {
            char_set[i] = numbers[j];
            i++;
        }
    }
    if (use_special_chars) {
        for (int j = 0; j < sizeof(special_chars) - 1; j++) {
            char_set[i] = special_chars[j];
            i++;
        }
    }

    // seed random number generator
    srand(time(NULL));

    // allocate memory for password
    char *password = (char*) malloc((length + 1) * sizeof(char));

    // generate random password using character set
    for (i = 0; i < length; i++) {
        int random_index = rand() % char_set_size;
        password[i] = char_set[random_index];
    }
    password[length] = '\0'; // terminate string with null character

    return password;
}

// function to check if a string contains only alphanumeric characters
int is_alphanumeric(char *str, int length) {
    for (int i = 0; i < length; i++) {
        if (!isalnum(str[i])) return 0;
    }
    return 1;
}

int main() {

    // get user preferences
    int length, use_lowercase, use_uppercase, use_numbers, use_special_chars;
    printf("Enter desired password length: ");
    scanf("%d", &length);
    printf("Include lowercase letters? (1 = yes, 0 = no): ");
    scanf("%d", &use_lowercase);
    printf("Include uppercase letters? (1 = yes, 0 = no): ");
    scanf("%d", &use_uppercase);
    printf("Include numbers? (1 = yes, 0 = no): ");
    scanf("%d", &use_numbers);
    printf("Include special characters? (1 = yes, 0 = no): ");
    scanf("%d", &use_special_chars);

    // generate password
    char *password = generate_password(length, use_lowercase, use_uppercase, use_numbers, use_special_chars);

    // check password security
    int password_secure = is_alphanumeric(password, length);

    // print password and security message
    printf("Password: %s\n", password);
    if (password_secure) {
        printf("Password is secure.\n");
    } else {
        printf("Password is not secure.\n");
    }

    // free memory allocated for password
    free(password);

    return 0;
}