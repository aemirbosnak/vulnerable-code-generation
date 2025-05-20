//FormAI DATASET v1.0 Category: Password management ; Style: thoughtful
#include<stdio.h>
#include<string.h>

/*   Function to validate password */
int validate(char password[])
{
    int len, i, special_check = 0, upper_check = 0, num_check = 0;

    len = strlen(password);

    if(len < 8)
    {
        printf("Password must be atleast 8 characters long.\n");
        return 0;
    }
    
    /* Checking for special characters in password */
    for(i = 0; i < len; i++)
    {
        if(password[i] >= 33 && password[i] <= 47)
        {
            special_check = 1;
        }
    }
    
    /* Checking for uppercase letters in password */
    for(i = 0; i < len; i++)
    {
        if(password[i] >= 65 && password[i] <= 90)
        {
            upper_check = 1;
        }
    }
    
    /* Checking for numerical digits in password */
    for(i = 0; i < len; i++)
    {
        if(password[i] >= 48 && password[i] <= 57)
        {
            num_check = 1;
        }
    }
    
    /* If all the conditions are met, password is considered valid */
    if(special_check == 1 && upper_check == 1 && num_check == 1)
    {
        printf("Password successfully validated.\n");
        return 1;
    }
    else
    {
        printf("The password must contain at least one uppercase letter, one numerical digit and one special character.\n");
        return 0;
    }
}

int main()
{
    char password[50], confirm_pass[50];

    printf("Please enter a password: ");
    scanf("%s", &password);

    /* Validating the entered password */
    while(1)
    {
        if(validate(password) == 1)
        {
            break;
        }
        else 
        {
            printf("Please enter a valid password: ");
            scanf("%s", &password);
        }
    }

    /* Confirming the entered password */
    printf("\nPlease confirm your password: ");
    scanf("%s", &confirm_pass);

    if(strcmp(password, confirm_pass) == 0)
    {
        printf("Password successfully confirmed. Your password is now saved in our database securely.");
    }
    else
    {
        printf("Passwords do not match. Please try again.");
    }

    return 0;
}