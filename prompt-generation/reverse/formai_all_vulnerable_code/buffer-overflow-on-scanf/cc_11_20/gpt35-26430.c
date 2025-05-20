//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: detailed
#include<stdio.h>
#include<string.h>

int check_strength(char* password);

int main()
{
    char password[50];
    printf("Enter password (at least 8 characters long, containing lowercase, uppercase letters, numbers and special characters): ");
    scanf("%s", password);
    int strength = check_strength(password);
    switch(strength)
    {
        case 0:
            printf("Very weak password.\n");
            break;
        case 1:
            printf("Weak password.\n");
            break;
        case 2:
            printf("Medium strength password.\n");
            break;
        case 3:
            printf("Strong password.\n");
            break;
        case 4:
            printf("Very strong password.\n");
            break;
    }
    return 0;
}

int check_strength(char* password)
{
    int len = strlen(password);
    int lowercase = 0, uppercase = 0, digit = 0, special = 0;
    for(int i = 0; i < len; i++)
    {
        if(password[i] >= 'a' && password[i] <= 'z')
            lowercase++;
        else if(password[i] >= 'A' && password[i] <= 'Z')
            uppercase++;
        else if(password[i] >= '0' && password[i] <= '9')
            digit++;
        else
            special++;
    }
    
    if(len < 8)
        return 0; // very weak
    
    if(lowercase && uppercase && digit && special)
        return 4; // very strong
    
    if((lowercase || uppercase) && digit && special)
        return 3; // strong
    
    if(lowercase && uppercase && digit)
        return 2; // medium strength
    
    return 1; // weak
}