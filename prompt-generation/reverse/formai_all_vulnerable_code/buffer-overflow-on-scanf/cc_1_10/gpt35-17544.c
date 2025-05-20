//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_PASSWORD_LENGTH 8 // minimum length of password
#define MAX_PASSWORD_LENGTH 20 // maximum length of password

// function to generate a random password
void generatePassword(char* password, int length)
{
    // define the character set to pick characters from
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";

    // seed random number generator
    srand((unsigned) time(NULL));

    // randomly pick characters from the character set to form the password
    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        password[i] = charset[index];
    }

    // add null terminator to the end of the password
    password[length] = '\0';
}

int main()
{
    int length = 0;
    char password[MAX_PASSWORD_LENGTH + 1];

    printf("Secure Password Generator\n");
    printf("-------------------------\n");

    // get length of password from user
    do {
        printf("Enter password length [%d-%d]: ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &length);

        if (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
            printf("Password length must be between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        }
    } while (length < MIN_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH);

    // generate and display password
    generatePassword(password, length);
    printf("\nGenerated Password: %s\n", password);

    return 0;
}