//Falcon-180B DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PASSWORD_LENGTH 20
#define PASSWORD_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_-+={}[]|;:,.<>/?\\"

// Function to generate a random password
char* generate_password(int length)
{
    char* password = (char*)malloc(length+1);
    if (password == NULL)
    {
        printf("Error: Failed to allocate memory\n");
        exit(1);
    }
    srand(time(NULL));
    for (int i=0; i<length; i++)
    {
        password[i] = PASSWORD_CHARS[rand() % strlen(PASSWORD_CHARS)];
    }
    password[length] = '\0';
    return password;
}

int main()
{
    char* password = NULL;
    int password_length = 0;

    // Get password length from user
    printf("Enter password length (1-20): ");
    scanf("%d", &password_length);

    // Validate password length
    if (password_length < 1 || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("Error: Invalid password length\n");
        exit(1);
    }

    // Generate password
    password = generate_password(password_length);

    // Display password
    printf("Your password is: %s\n", password);

    // Free memory
    free(password);

    return 0;
}