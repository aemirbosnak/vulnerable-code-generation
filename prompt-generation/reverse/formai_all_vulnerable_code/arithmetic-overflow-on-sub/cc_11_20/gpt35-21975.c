//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Initialize variables
    int length, num, spec, upper, lower, range, i, r;
    char password[101];
    char symbols[] = "!@#$%^&*()_+-={}[]|:;<>,.?/";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";

    // Introduce the program and ask user for password length
    printf("Welcome to the Secure Password Generator!\n");
    printf("How many characters would you like your password to be? (between 10 and 100)\n");
    scanf("%d", &length);

    // Check for valid password length
    if (length < 10 || length > 100) {
        printf("Invalid password length.\n");
        return 1;
    }

    // Ask user for number of numbers, special characters, uppercase and lowercase letters
    printf("How many numbers would you like in your password?\n");
    scanf("%d", &num);

    printf("How many special characters would you like in your password?\n");
    scanf("%d", &spec);

    printf("How many uppercase letters would you like in your password?\n");
    scanf("%d", &upper);

    printf("How many lowercase letters would you like in your password?\n");
    scanf("%d", &lower);

    // Check for valid number of characters
    if (num + spec + upper + lower > length) {
        printf("Invalid number of characters.\n");
        return 1;
    }

    // Calculate range of random characters
    range = 3 * num + 4 * spec + 2 * upper + 2 * lower;

    // Generate the password
    srand(time(NULL));

    for (i = 0; i < num; i++) {
        r = rand() % 10;
        password[i] = r + '0';
    }

    for (i = num; i < num + spec; i++) {
        r = rand() % strlen(symbols);
        password[i] = symbols[r];
    }

    for (i = num + spec; i < num + spec + upper; i++) {
        r = rand() % strlen(uppercase);
        password[i] = uppercase[r];
    }

    for (i = num + spec + upper; i < length - lower; i++) {
        r = rand() % range;
        if (r < num) {
            password[i] = rand() % 10 + '0';
        }
        else if (r < num + spec) {
            password[i] = symbols[rand() % strlen(symbols)];
        }
        else if (r < num + spec + upper) {
            password[i] = uppercase[rand() % strlen(uppercase)];
        }
        else {
            password[i] = lowercase[rand() % strlen(lowercase)];
        }
    }

    for (i = length - lower; i < length; i++) {
        r = rand() % strlen(lowercase);
        password[i] = lowercase[r];
    }

    // Shuffle the password characters
    for (i = length - 1; i > 0; i--) {
        r = rand() % (i + 1);
        char temp = password[i];
        password[i] = password[r];
        password[r] = temp;
    }

    // Display the password
    printf("\nYour secure password is:\n%s\n", password);

    return 0;
}