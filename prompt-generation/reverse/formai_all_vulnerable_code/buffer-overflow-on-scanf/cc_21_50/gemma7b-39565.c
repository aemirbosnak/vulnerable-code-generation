//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    char password[256];
    int i, strength = 0, min_length = 8, max_repeat = 3;
    printf("Enter a password: ");
    scanf("%s", password);

    // Check password length
    if (strlen(password) < min_length)
    {
        printf("Password too short! Minimum %d characters required.\n", min_length);
        return 1;
    }

    // Check for repeated characters
    for (i = 0; i < strlen(password); i++)
    {
        int count = 0;
        for (int j = 0; j < strlen(password); j++)
        {
            if (password[i] == password[j])
            {
                count++;
            }
        }

        if (count > max_repeat)
        {
            printf("Password has too many repeated characters.\n");
            return 1;
        }
    }

    // Calculate password strength
    for (i = 0; i < strlen(password); i++)
    {
        switch (password[i])
        {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                strength++;
                break;
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '0':
                strength++;
                break;
            default:
                strength--;
                break;
        }
    }

    // Print password strength
    printf("Password strength: ");
    switch (strength)
    {
        case 0:
            printf("Weak\n");
            break;
        case 1:
            printf("Fair\n");
            break;
        case 2:
            printf("Good\n");
            break;
        case 3:
            printf("Strong\n");
            break;
        case 4:
            printf("Excellent\n");
            break;
    }

    return 0;
}