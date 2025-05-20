//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASS_LEN 128

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Prompt the user for the desired password length
    int pass_len;
    printf("Enter the desired password length (max %d): ", MAX_PASS_LEN);
    scanf("%d", &pass_len);

    // Validate the user input
    if (pass_len <= 0 || pass_len > MAX_PASS_LEN) {
        printf("Invalid password length. Please enter a value between 1 and %d.\n", MAX_PASS_LEN);
        return 1;
    }

    // Create an array to store the password
    char pass[MAX_PASS_LEN + 1];

    // Generate the password
    for (int i = 0; i < pass_len; i++) {
        // Generate a random character from the set of lowercase letters, uppercase letters, digits, and special characters
        int rand_idx = rand() % 94;
        char rand_char;
        if (rand_idx < 26) {
            rand_char = 'a' + rand_idx;
        } else if (rand_idx < 52) {
            rand_char = 'A' + rand_idx - 26;
        } else if (rand_idx < 78) {
            rand_char = '0' + rand_idx - 52;
        } else {
            rand_char = "!@#$%^&*()_+=-{}[]|:;<>,.?/`~"[rand_idx - 78];
        }

        // Append the random character to the password
        pass[i] = rand_char;
    }

    // Null-terminate the password
    pass[pass_len] = '\0';

    // Display the generated password to the user
    printf("Generated password: %s\n", pass);

    return 0;
}