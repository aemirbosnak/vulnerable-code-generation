//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set up the different character sets
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char special[] = "!#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    // Prompt the user for password length
    int length;
    printf("Enter desired password length: ");
    scanf("%d", &length);

    // Seed the random number generator
    srand(time(NULL));

    // Set up the password array
    char password[length];

    // Ensure password has at least one character from each set
    password[0] = lower[rand() % strlen(lower)];
    password[1] = upper[rand() % strlen(upper)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill rest of password array with random characters from all sets
    for (int i = 4; i < length; i++) {
        int set = rand() % 4;
        switch (set) {
            case 0:
                password[i] = lower[rand() % strlen(lower)];
                break;
            case 1:
                password[i] = upper[rand() % strlen(upper)];
                break;
            case 2:
                password[i] = digits[rand() % strlen(digits)];
                break;
            case 3:
                password[i] = special[rand() % strlen(special)];
                break;
        }
    }

    // Randomize the order of the characters in the password
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Print the generated password
    printf("Generated Password: %s\n", password);

    return 0;
}