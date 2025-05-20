//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
const char digits[] = "0123456789";
const char special[] = "!@#$%^&*()_+=-[]{}|;:',.<>?";

void generate_password(char *password, int length) {
    int uppercase_count = length / 4; // 25% uppercase
    int lowercase_count = length / 4; // 25% lowercase
    int digits_count = length / 4;     // 25% digits
    int special_count = length - (uppercase_count + lowercase_count + digits_count); // remaining special

    int index = 0;

    // Adding uppercase letters
    for (int i = 0; i < uppercase_count; i++) {
        password[index++] = uppercase[rand() % (sizeof(uppercase) - 1)];
    }

    // Adding lowercase letters
    for (int i = 0; i < lowercase_count; i++) {
        password[index++] = lowercase[rand() % (sizeof(lowercase) - 1)];
    }

    // Adding digits
    for (int i = 0; i < digits_count; i++) {
        password[index++] = digits[rand() % (sizeof(digits) - 1)];
    }

    // Adding special characters
    for (int i = 0; i < special_count; i++) {
        password[index++] = special[rand() % (sizeof(special) - 1)];
    }

    // Shuffle the password to avoid any pattern
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null terminate the password string
    password[length] = '\0';
}

int main() {
    srand(time(NULL));
   
    int length;
    char password[MAX_LENGTH + 1]; // +1 for null terminator

    printf("Welcome to the Secure Password Generator!\n");
    printf("Please enter the desired length of the password (minimum 8, maximum 128): ");
    scanf("%d", &length);

    if (length < 8 || length > MAX_LENGTH) {
        printf("Invalid length. Please enter a number between 8 and 128.\n");
        return 1;
    }

    generate_password(password, length);
   
    printf("Your secure password is: %s\n", password);

    return 0;
}