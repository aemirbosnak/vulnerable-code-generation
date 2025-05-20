//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 32
#define MAX_NUM_SPECIAL_CHARS 10

char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char lower[] = "abcdefghijklmnopqrstuvwxyz";
char digits[] = "0123456789";
char special[] = "!@#$%^&*()_+~`|}{[]:;?><,./-=";

int get_random_int(int min, int max) {
    return (rand() % (max - min)) + min;
}

char get_random_char(char* char_set, int set_size) {
    int random_index = get_random_int(0, set_size);
    return char_set[random_index];
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Get user input for password length and number of special characters
    int password_length, num_special_chars;
    printf("Enter password length (between %d and %d characters): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    printf("Enter number of special characters (between 0 and %d): ", MAX_NUM_SPECIAL_CHARS);
    scanf("%d", &num_special_chars);

    if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
        printf("Invalid password length. Exiting...\n");
        return 0;
    }

    if (num_special_chars < 0 || num_special_chars > MAX_NUM_SPECIAL_CHARS) {
        printf("Invalid number of special characters. Exiting...\n");
        return 0;
    }

    // Calculate number of letters and digits needed for password
    int num_letters = password_length - num_special_chars - 1;
    int num_digits = 1;

    // Generate random characters for password
    char password[MAX_PASSWORD_LENGTH];
    int i;
    for (i = 0; i < num_letters; i++) {
        if (i == 0) { // First character must be a letter
            if (get_random_int(0, 2) == 0) {
                password[i] = get_random_char(upper, sizeof(upper));
            } else {
                password[i] = get_random_char(lower, sizeof(lower));
            }
        } else { // All other characters can be letters or digits
            if (get_random_int(0, 2) == 0) {
                password[i] = get_random_char(upper, sizeof(upper));
            } else {
                password[i] = get_random_char(lower, sizeof(lower));
            }
            if (i == (num_letters - num_digits - 1) && num_digits > 0) { // Add digit at specific index
                password[i+1] = get_random_char(digits, sizeof(digits));
                num_digits--;
            }
        }
    }

    // Add special characters to password
    for (i = 0; i < num_special_chars; i++) {
        password[num_letters + i] = get_random_char(special, sizeof(special));
    }

    // Add last character (must be a digit)
    password[password_length-1] = get_random_char(digits, sizeof(digits));

    // Shuffle password characters
    for (i = password_length - 1; i > 0; i--) {
        int j = get_random_int(0, i+1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Print password
    printf("Your generated password is: ");
    for (i = 0; i < password_length; i++) {
        printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}