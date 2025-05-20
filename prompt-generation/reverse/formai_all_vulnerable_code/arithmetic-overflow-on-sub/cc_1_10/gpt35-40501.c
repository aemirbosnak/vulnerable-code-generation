//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* This function generates a random character between a and z */
char random_char() {
    return (char) (rand() % 26 + 97);
}

/* This function generates a random number between 0 and 9 */
char random_number() {
    return (char) (rand() % 10 + 48);
}

/* This function generates a random special character */
char random_special_char() {
    char special_chars[] = {'!', ';', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '|', '{', '}', '[', ']', '\\', ';', '\'', ':', '\"', ',', '.', '/', '<', '>'};
    return special_chars[rand() % 30];
}

/* This function creates a password with the specified constraints */
void generate_password(int length, int num_digits, int num_special_chars, char password[]) {
    int num_letters = length - num_digits - num_special_chars;
    int i;
    for (i = 0; i < num_letters; i++) {
        password[i] = random_char();
    }
    for (i = num_letters; i < num_letters + num_digits; i++) {
        password[i] = random_number();
    }
    for (i = num_letters + num_digits; i < length; i++) {
        password[i] = random_special_char();
    }
    /* Shuffle the password using Fisher-Yates shuffle */
    srand(time(NULL));
    for (i = length - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
}

int main() {
    /* User input */
    int length, num_digits, num_special_chars;
    printf("Enter the length of the password: ");
    scanf("%d", &length);
    printf("Enter the number of digits in the password: ");
    scanf("%d", &num_digits);
    printf("Enter the number of special characters in the password: ");
    scanf("%d", &num_special_chars);
    /* Validate input */
    if (length <= 0 || num_digits < 0 || num_special_chars < 0 || num_digits + num_special_chars > length) {
        printf("Invalid input.\n");
        return 1;
    }
    /* Generate password */
    char password[length + 1];
    generate_password(length, num_digits, num_special_chars, password);
    password[length] = '\0';
    /* Print password */
    printf("Your secure password is: %s\n", password);
    return 0;
}