//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    // Set random seed
    srand(time(NULL));

    // Define password characters
    char lower[] = "abcdefghijklmnopqrstuvwxyz";
    char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char digits[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+";

    // Get password length from user
    int len;
    printf("\nWelcome to the Post-Apocalyptic Password Generator 2.0!\n\n");
    printf("Enter desired password length (min. 8, max. 32): ");
    scanf("%d", &len);

    // Ensure password length is within range
    while (len < 8 || len > 32) {
        printf("Invalid length. Please enter a value between 8 and 32: ");
        scanf("%d", &len);
    }

    // Generate random password
    char password[len + 1]; // +1 for null terminator

    for (int i = 0; i < len; i++) {
        int type = rand() % 4; // 0: lower, 1: upper, 2: digit, 3: symbol
        switch (type) {
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
                password[i] = symbols[rand() % strlen(symbols)];
                break;
        }
    }

    password[len] = '\0'; // Null terminate password

    // Print generated password
    printf("\nYour post-apocalyptic password: %s\n", password);

    // Ask user to save password
    char choice;
    printf("\nSave password to your survival bunker (Y/N)? ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        FILE *file = fopen("apocalypse_passwords.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s\n", password);
            fclose(file);
            printf("Password saved to bunker.\n");
        } else {
            printf("Error saving password to bunker.\n");
        }
    }

    return 0;
}