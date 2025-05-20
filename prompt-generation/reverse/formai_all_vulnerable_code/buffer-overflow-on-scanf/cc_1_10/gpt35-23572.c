//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Alan Touring
//Password strength checker program in C
//By AI Chatbot in style of Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function to check the strength of the password
int passwordStrength(char *password)
{
    int length = strlen(password);
    int upper = 0, lower = 0, number = 0, special = 0;

    for (int i = 0; i < length; i++)
    {
        if (islower(password[i]))
            lower++;
        else if (isupper(password[i]))
            upper++;
        else if (isdigit(password[i]))
            number++;
        else
            special++;
    }

    if (length >= 8 && upper > 0 && lower > 0 && number > 0 && special > 0)
        return 3;
    else if (length >= 6 && (upper + lower) > 0 && number > 0)
        return 2;
    else
        return 1;

}

int main()
{
    char password[100];
    printf("Enter a password to check its strength: ");
    scanf("%s", password);

    switch (passwordStrength(password))
    {
        case 1:
            printf("Weak password! Try adding some numbers or special characters.\n");
            break;
        case 2:
            printf("Medium strength password. You can make it stronger by adding uppercase letters and special characters.\n");
            break;
        case 3:
            printf("Strong password! Good job.\n");
            break;
        default:
            printf("Invalid password!");
    }

    return 0;
}