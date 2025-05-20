#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
    char password[256];
    int length = 0;

    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);

    if (length < 8)
    {
        printf("Password too short. Minimum 8 characters required.\n");
    }
    else if (!((password[0] >= 'a' && password[0] <= 'z') || (password[0] >= 'A' && password[0] <= 'Z')))
    {
        printf("Password must contain a letter.\n");
    }
    else if (!((password[0] >= '0' && password[0] <= '9') || (password[0] >= '!' && password[0] <= '@')))
    {
        printf("Password must contain a number or special character.\n");
    }
    else
    {
        printf("Password is strong.\n");
    }

    return 0;
}
