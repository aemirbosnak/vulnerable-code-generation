//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char* generate_password(int length);
void shuffle_array(char *array, int n);
int char_in_string(char c, char *s);

int main()
{
    int length;

    printf("Enter the length of the password: ");
    scanf("%d", &length);

    char* password = generate_password(length);
    
    printf("Your secure password is: %s\n", password);

    free(password);
}

char* generate_password(int length)
{
    char* password = malloc(length + 1);

    // Define all the possible characters that can be in the password
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_-+={}[]\\|;:'\",.<>/?";

    int lowercase_len = strlen(lowercase);
    int uppercase_len = strlen(uppercase);
    int numbers_len = strlen(numbers);
    int symbols_len = strlen(symbols);

    // Create an array to hold all the possible characters
    char all_chars[lowercase_len + uppercase_len + numbers_len + symbols_len];

    strncpy(all_chars, lowercase, lowercase_len);
    strncpy(all_chars + lowercase_len, uppercase, uppercase_len);
    strncpy(all_chars + lowercase_len + uppercase_len, numbers, numbers_len);
    strncpy(all_chars + lowercase_len + uppercase_len + numbers_len, symbols, symbols_len);

    // Shuffle the array of possible characters
    shuffle_array(all_chars, strlen(all_chars));
    
    srand(time(NULL)); // Seed the random number generator

    for (int i = 0; i < length; i++)
    {
        char c;

        // Randomly select a character from the array of possible characters
        do {
            c = all_chars[rand() % strlen(all_chars)];
        } while (char_in_string(c, password));

        password[i] = c;
    }

    password[length] = '\0';

    return password;
}

// Shuffle an array of characters
void shuffle_array(char *array, int n)
{
    if (n > 1) 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            char t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

// Check if a character is already in the given string
int char_in_string(char c, char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == c)
        {
            return 1;
        }
    }

    return 0;
}