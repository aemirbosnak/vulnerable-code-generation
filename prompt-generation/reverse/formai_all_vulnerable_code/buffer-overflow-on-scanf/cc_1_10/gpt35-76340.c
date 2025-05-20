//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

int main()
{
    // Variable declaration
    int length;
    char password[MAX_PASSWORD_LENGTH];
    int random_index = 0;
    char random_char = ' ';
    int i = 0;
    int char_type_count[4] = {0, 0, 0, 0};
    char char_types[4][9] = {"abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", "0123456789", "!@#$%^&*()_+-="};

    // Seed for random number generation
    srand((unsigned) time(NULL));

    // Ask user for password length
    printf("Enter password length (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);

    // Validate password length
    if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH)
    {
        printf("Error: Invalid password length!\n");
        return 1;   // Exit program with error code
    }

    // Generate password
    while (i < length)
    {
        random_index = rand() % 4;  // Choose random character type
        if (char_type_count[random_index] < length / 4)
        {
            random_char = char_types[random_index][rand() % strlen(char_types[random_index])];  // Choose random character from chosen type
            password[i] = random_char;  // Store character in password array
            i++;
            char_type_count[random_index]++;  // Increment character type count
        }
    }
    password[length] = '\0';  // Add null terminator to end of password

    // Print password
    printf("Your secure password is: %s\n", password);

    return 0;   // Exit program successfully
}