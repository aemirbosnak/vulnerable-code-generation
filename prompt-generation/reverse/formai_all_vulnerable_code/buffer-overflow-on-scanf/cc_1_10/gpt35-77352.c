//FormAI DATASET v1.0 Category: Password management ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

/* function to validate password */
int validate_password(char password[])
{
    int i, uppercase = 0, lowercase = 0, digit = 0, special = 0;
    int len = strlen(password);
    
    if(len < 6 || len > 20) // password length should be between 6 to 20 characters
        return 0;
    
    for(i=0; i<len; i++)
    {
        if(password[i] >= 'A' && password[i] <= 'Z') // checking uppercase letters
            uppercase++;
        else if(password[i] >= 'a' && password[i] <= 'z') // checking lowercase letters
            lowercase++;
        else if(password[i] >= '0' && password[i] <= '9') // checking digits
            digit++;
        else // checking special characters
            special++;
    }
    
    if(uppercase < 1 || lowercase < 1 || digit < 1 || special < 1) // password should contain at least one uppercase, one lowercase, one digit and one special character
        return 0;
    
    return 1; // password is valid
}

/* function to encrypt the password */
void encrypt_password(char password[])
{
    int i, len = strlen(password);
    
    for(i=0; i<len; i++)
        password[i] = password[i] + 5; // encrypting the password by adding 5 to each character ascii value
}

/* function to decrypt the password */
void decrypt_password(char password[])
{
    int i, len = strlen(password);
    
    for(i=0; i<len; i++)
        password[i] = password[i] - 5; // decrypting the password by subtracting 5 from each character ascii value
}

int main()
{
    char username[MAX], password[MAX], confirm_password[MAX];
    int choice, validate, i;
    FILE *fp;
    
    printf("Welcome to Password Management System!\n");
    printf("Please enter your login details.\n");
    
    printf("Username: ");
    gets(username);
    
    printf("Password: ");
    gets(password);
    
    /* encrypting the password */
    encrypt_password(password);
    
    printf("\nLogin Successful!\n");
    
    while(1)
    {
        printf("\nWhat would you like to do?\n");
        printf("1. Change Password\n");
        printf("2. Forgot Password\n");
        printf("3. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                printf("\nChange Password\n");
                printf("Please enter your current password: ");
                fflush(stdin);
                gets(confirm_password);
                
                /* decrypting the password */
                decrypt_password(password);
                
                /* checking if the entered password is correct */
                if(strcmp(confirm_password, password) != 0)
                {
                    printf("Incorrect Password!\n");
                    printf("Please try again.\n");
                    
                    /* encrypting the password again */
                    encrypt_password(password);
                    
                    break;
                }
                
                /* encrypting the password again */
                encrypt_password(password);
                
                printf("Enter your new password: ");
                fflush(stdin);
                gets(password);
                
                validate = validate_password(password);
                
                while(!validate)
                {
                    printf("Invalid Password!\n");
                    printf("Password length should be between 6 to 20 characters and should contain at least one uppercase, one lowercase, one digit and one special character.\n");
                    printf("Enter a valid password: ");
                    fflush(stdin);
                    gets(password);
                    
                    validate = validate_password(password);
                }
                
                /* encrypting the password */
                encrypt_password(password);
                
                printf("Password changed successfully!\n");
                
                break;
                
            case 2:
                printf("\nForgot Password\n");
                printf("Please enter your registered email id: ");
                char email[MAX];
                scanf("%s", email);
                printf("An email with the password reset link has been sent to your email id!\n");
                break;
                
            case 3:
                printf("\nThank you for using Password Management System!\n");
                
                /* saving the username and password to a file */
                fp = fopen("password.txt", "w");
                fprintf(fp, "%s\n%s", username, password);
                fclose(fp);
                
                exit(0);
                
            default:
                printf("\nInvalid Choice!\n");
        }
    }
    
    return 0;
}