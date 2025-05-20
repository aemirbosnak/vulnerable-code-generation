//FormAI DATASET v1.0 Category: Spam Detection System ; Style: ephemeral
#include <stdio.h>
#include <string.h>
 
int main()
{
    char email[1000], temp[30], *ptr;
    int i, j, k, len, flag;
 
    printf("Enter email: ");
    gets(email);
 
    len = strlen(email);
 
    for (i = 0; i < len; i++)
    {
        if (email[i] == '@')
            break;
    }
 
    ptr = strchr(email, '@');
 
    k = 0;
    for (i = i+1; i < len; i++)
    {
        if (email[i] == '.')
        {
            flag = 1;
            temp[k] = '\0';
            if (strcmp(temp, "c") == 0)
            {
                printf("The email contains spam.");
                return 0;
            }
            k = 0;
        }
        else
        {
            temp[k++] = email[i];
        }
    }
 
    if (flag == 0)
    {
        printf("Invalid email!");
        return 0;
    }
 
    printf("The email is safe.");
 
    return 0;
}