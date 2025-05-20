//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int password_length, num_uppercase, num_lowercase, num_numbers, num_symbols, i, j, k;
    char password[128];
    char uppercase_characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase_characters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-={}|[]\\:\";'<>?,./";

    srand(time(0));

    printf("Welcome to the Secure Password Generator 3000. \n");
    printf("Please enter the length of your desired password: ");
    scanf("%d", &password_length);

    printf("Please enter the number of uppercase letters you'd like in your password: ");
    scanf("%d", &num_uppercase);

    printf("Please enter the number of lowercase letters you'd like in your password: ");
    scanf("%d", &num_lowercase);

    printf("Please enter the number of numbers you'd like in your password: ");
    scanf("%d", &num_numbers);

    printf("Please enter the number of symbols you'd like in your password: ");
    scanf("%d", &num_symbols);

    // Generate the uppercase characters
    for(i = 0; i < num_uppercase; i++) {
        password[i] = uppercase_characters[rand() % 26];
    }

    // Generate the lowercase characters
    for(j = i; j < i + num_lowercase; j++) {
        password[j] = lowercase_characters[rand() % 26];
    }

    // Generate the numbers
    for(k = j; k < j + num_numbers; k++) {
        password[k] = numbers[rand() % 10];
    }

    // Generate the symbols
    for(i = k; i < k + num_symbols; i++) {
        password[i] = symbols[rand() % 29];
    }

    // Shuffle the password array
    for(i = 0; i < password_length; i++) {
        int random_idx = rand() % password_length;
        char temp = password[i];
        password[i] = password[random_idx];
        password[random_idx] = temp;
    }

    // Print out the password
    printf("Your secure password is: %s\n", password);
    printf("Thank you for using the Secure Password Generator 3000!\n");

    return 0;
}