//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct user_details
{
    char username[50];
    char password[50];
};

int is_good_password(const char* password)
{
    int len = strlen(password);
    
    if (len < 6)
        return 0;

    int i;
    for (i = 0; i < len; ++i)
    {
        if (!isalpha(password[i]))
        {
            if (!isdigit(password[i]))
                return 0;
        }
    }

    return 1;
}

int main()
{
    struct user_details user;
    
    printf("Enter username: ");
    scanf("%s", user.username);

    printf("Enter password: ");
    scanf("%s", user.password);

    if (is_good_password(user.password))
    {
        printf("%s is a good password.\n", user.username);
    }
    else
    {
        printf("%s is not a good password.\n", user.username);
    }

    return 0;
}