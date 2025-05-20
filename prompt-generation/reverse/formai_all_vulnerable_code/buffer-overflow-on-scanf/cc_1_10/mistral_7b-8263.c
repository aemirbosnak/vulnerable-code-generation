//MISTRAL-7B DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_LENGTH 12
#define MAX_LENGTH 20

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a given set
char random_char(char set[]) {
    return set[random_number(0, sizeof(set) - 1)];
}

// Function to generate a secure password with given length and character sets
void generate_password(int length, char* password) {
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char digit[] = "0123456789";
    char special[] = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    int num_upper = random_number(0, length / 3);
    int num_lower = random_number(0, length / 3);
    int num_digit = random_number(0, length / 3);
    int num_special = length - (num_upper + num_lower + num_digit);

    for (int i = 0; i < num_upper; i++)
        password[i] = random_char(upper);

    for (int i = num_upper; i < num_upper + num_lower; i++)
        password[i] = random_char(lower);

    for (int i = num_upper + num_lower; i < length; i++) {
        if (num_digit > 0) {
            password[i] = random_char(digit);
            num_digit--;
        } else if (num_special > 0) {
            password[i] = random_char(special);
            num_special--;
        } else {
            password[i] = random_char(lower);
        }
    }

    password[length] = '\0'; // null terminate the password
}

int main() {
    int length;

    printf("Enter password length (min 12, max 20): ");
    scanf("%d", &length);

    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Invalid length. Exiting...\n");
        return 1;
    }

    char password[length + 1];

    srand(time(NULL)); // seed the random number generator

    generate_password(length, password);

    printf("Generated Password: %s\n", password);

    return 0;
}