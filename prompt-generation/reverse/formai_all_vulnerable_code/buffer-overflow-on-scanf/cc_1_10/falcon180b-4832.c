//Falcon-180B DATASET v1.0 Category: Password management ; Style: modular
/*This is a modular C program for password management*/

#include<stdio.h>
#include<string.h>

/*Function for password creation*/
void createPassword(char *password, int length)
{
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789@#$%^&*()_+-=[]{}|;:,.<>/?\\";
    int i;
    for(i=0; i<length; i++)
    {
        password[i] = charset[rand()%strlen(charset)];
    }
    password[i] = '\0';
}

/*Function for password verification*/
int verifyPassword(char *password, char *verifyPassword)
{
    int i;
    for(i=0; i<strlen(password); i++)
    {
        if(password[i]!= verifyPassword[i])
        {
            return 0;
        }
    }
    return 1;
}

/*Function for password storage*/
void storePassword(char *password)
{
    FILE *file;
    file = fopen("passwords.txt", "a");
    if(file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }
    fprintf(file, "%s\n", password);
    fclose(file);
}

/*Function for password retrieval*/
char *retrievePassword(char *username)
{
    FILE *file;
    char line[100];
    char *password = NULL;
    file = fopen("passwords.txt", "r");
    if(file == NULL)
    {
        printf("Error: Could not open file\n");
        exit(1);
    }
    while(fgets(line, 100, file)!= NULL)
    {
        if(strstr(line, username)!= NULL)
        {
            password = strtok(line, "\n");
            break;
        }
    }
    fclose(file);
    return password;
}

/*Main function*/
int main()
{
    char username[20];
    char password[20];
    int length;
    printf("Enter the username: ");
    scanf("%s", username);
    printf("Enter the password length: ");
    scanf("%d", &length);
    createPassword(password, length);
    printf("Your password is: %s\n", password);
    printf("Do you want to store the password? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y')
    {
        storePassword(password);
        printf("Password stored successfully\n");
    }
    else
    {
        printf("Password not stored\n");
    }
    printf("Do you want to retrieve the password? (y/n): ");
    scanf("%c", &choice);
    if(choice == 'y' || choice == 'Y')
    {
        char *retrievedPassword = retrievePassword(username);
        if(retrievedPassword!= NULL)
        {
            printf("Your password is: %s\n", retrievedPassword);
        }
        else
        {
            printf("Password not found\n");
        }
    }
    return 0;
}