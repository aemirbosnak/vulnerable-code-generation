//FormAI DATASET v1.0 Category: Spam Detection System ; Style: grateful
#include <stdio.h>
#include <string.h>

int main()
{
    char email[1000];
    int i, j, len, flag;
    
    printf("Enter an email: ");
    scanf("%s", email);
    
    len = strlen(email);
    
    flag = 0;
    
    for(i = 0; i < len; i++)
    {
        if(email[i] == ' ')
        {
            flag = 1;
            break;
        }
    }
    
    if(flag == 1)
    {
        printf("This email contains a space and is likely spam.\n");
    }
    else
    {
        for(i = 0; i < len-1; i++)
        {
            if(email[i] == '.' && email[i+1] == '.')
            {
                flag = 1;
                break;
            }
        }
        
        if(flag == 1)
        {
            printf("This email contains consecutive dots and is likely spam.\n");
        }
        else
        {
            j = 0;
            for(i = 0; i < len; i++)
            {
                if(email[i] == '@')
                {
                    j++;
                }
            }
            
            if(j != 1)
            {
                printf("This email contains an incorrect number of '@' symbols and is likely spam.\n");
            }
            else
            {
                j = 0;
                flag = 0;
                
                for(i = 0; i < len; i++)
                {
                    if(email[i] == '@')
                    {
                        j = 1;
                    }
                    else if(j == 1)
                    {
                        if(email[i] == '.')
                        {
                            flag = 1;
                            j = 0;
                            break;
                        }
                    }
                }
                
                if(flag == 1)
                {
                    printf("This email contains an '@' symbol followed by a '.' symbol and is likely valid.\n");
                }
                else
                {
                    printf("This email does not contain an '@' symbol followed by a '.' symbol and is likely spam.\n");
                }
            }
        }
    }
    
    return 0;
}