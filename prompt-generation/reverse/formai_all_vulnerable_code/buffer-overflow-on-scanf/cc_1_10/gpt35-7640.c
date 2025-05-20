//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 25

// Function to generate a random character from a given character set
char random_char(char charset[]) {
    int index = rand() % strlen(charset);  // select a random index from the character set
    return charset[index];
}

// Function to generate a secure password
void generate_password(char password[], int length) {
    char lower_case[] = "abcdefghijklmnopqrstuvwxyz";
    char upper_case[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special_chars[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";
    char charset[MAX_LENGTH];
    int num_lowercase, num_uppercase, num_digits, num_special_chars;
    int i, index;
    num_lowercase = num_uppercase = num_digits = num_special_chars = 0;

    // select a random number of each type of character to include in the password
    num_lowercase = rand() % (length / 2);
    num_uppercase = rand() % (length / 2);
    num_digits = rand() % (length / 2);
    num_special_chars = length - num_lowercase - num_uppercase - num_digits;

    // add lowercase characters to the character set
    for (i = 0; i < num_lowercase; i++) {
        index = rand() % strlen(lower_case);
        charset[i] = lower_case[index];
    }

    // add uppercase characters to the character set
    for (i = num_lowercase; i < num_lowercase + num_uppercase; i++) {
        index = rand() % strlen(upper_case);
        charset[i] = upper_case[index];
    }

    // add digits to the character set
    for (i = num_lowercase + num_uppercase; i < num_lowercase + num_uppercase + num_digits; i++) {
        index = rand() % strlen(digits);
        charset[i] = digits[index];
    }

    // add special characters to the character set
    for (i = num_lowercase + num_uppercase + num_digits; i < length; i++) {
        index = rand() % strlen(special_chars);
        charset[i] = special_chars[index];
    }

    // shuffle the characters in the character set
    for (i = 0; i < length; i++) {       
        int j = rand() % length;         
        char tmp = charset[i];
        charset[i] = charset[j];
        charset[j] = tmp;
    }

    // generate the password from the character set
    for (i = 0; i < length; i++) {
        password[i] = random_char(charset);
    }

    password[length] = '\0';
}

int main(void) {
    char password[MAX_LENGTH];
    int length;

    srand((unsigned int)time(NULL));  // set random seed based on current time

    // prompt user for desired password length
    do {
        printf("Enter password length (max %d): ", MAX_LENGTH);
        scanf("%d", &length);
    } while (length < 1 || length > MAX_LENGTH);

    generate_password(password, length);
    printf("Your secure password is: %s\n", password);

    return 0;
}