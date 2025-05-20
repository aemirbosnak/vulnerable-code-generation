//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    system("/bin/clear");
    system("/bin/pstree -c");
    char pass[256];

    printf("\n\tEnter your password:");
    scanf("%s", pass);

    int strength = strength_check(pass);

    switch(strength)
    {
        case 0:
            printf("\n\tPassword Strength: Weak\n\n");
            break;
        case 1:
            printf("\n\tPassword Strength: Moderate\n\n");
            break;
        case 2:
            printf("\n\tPassword Strength: Strong\n\n");
            break;
        case 3:
            printf("\n\tPassword Strength: Excellent\n\n");
            break;
    }

    return 0;
}

int strength_check(char *pass)
{
    int strength = 0;

    if(strlen(pass) >= 12)
    {
        strength++;
    }

    for(int i = 0; i < strlen(pass); i++)
    {
        if(pass[i] >= 'a' && pass[i] <= 'z')
        {
            strength++;
        }
        else if(pass[i] >= 'A' && pass[i] <= 'Z')
        {
            strength++;
        }
        else if(pass[i] >= '0' && pass[i] <= '9')
        {
            strength++;
        }
    }

    if(strength >= 3)
    {
        strength++;
    }

    return strength;
}