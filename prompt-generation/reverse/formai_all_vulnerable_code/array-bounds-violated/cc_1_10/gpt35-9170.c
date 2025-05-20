//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LEN 20 // Maximum length of generated password
#define MIN_PASSWORD_LEN 8 // Minimum length of generated password
#define SPECIAL_CHARACTERS "!@#$%^&*()_+-=[]{}|;':\",./<>?" // String containing special characters

void generatePassword(int length, char* password);

int main()
{
    int length = 0;
    char password[MAX_PASSWORD_LEN + 1]; // +1 is for null terminator character.

    srand((unsigned int) time(NULL)); // Seed with current time.

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);

    // Check if length is in between minimum and maximum allowed length.
    if(length >= MIN_PASSWORD_LEN && length <= MAX_PASSWORD_LEN)
    {
        generatePassword(length, password);
        printf("Generated Password: %s\n", password);
    }
    else
    {
        printf("Length should be between %d and %d\n", MIN_PASSWORD_LEN, MAX_PASSWORD_LEN);
    }

    return 0;
}

void generatePassword(int length, char* password)
{
    int i, random_index;
    char temp_char;

    for(i = 0; i < length; i++)
    {
        random_index = rand() % 93; // Generate index between 0 and 92 (total number of special characters + alphabets + digits)
        if(random_index < 26) // If random index is less than 26, select a random uppercase alphabet.
        {
            temp_char = 'A' + random_index;
        }
        else if(random_index < 52) // If random index is less than 52, select a random lowercase alphabet.
        {
            temp_char = 'a' + random_index - 26;
        }
        else if(random_index < 62) // If random index is less than 62, select a random digit.
        {
            temp_char = '0' + random_index - 52;
        }
        else // If random index is greater than or equal to 62, select a random special character.
        {
            temp_char = SPECIAL_CHARACTERS[random_index - 62];
        }
        password[i] = temp_char;
    }
    password[i] = '\0'; // Add null terminator at the end of password.
}