//FormAI DATASET v1.0 Category: Password management ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct password{
    char username[50];
    char password[50];
};

void encrypt(char *str)
{
    //encryption function using simple substitution cipher
    while(*str)
    {
        if (*str=='a')
            *str='@';
        else if (*str=='e')
            *str='3';
        else if (*str=='i')
            *str='!';
        else if (*str=='o')
            *str='0';
        else if (*str=='u')
            *str='#';
        ++str;
    }
}

void decrypt(char *str)
{
    //decryption function for the above encryption
    while(*str)
    {
        if (*str=='@')
            *str='a';
        else if (*str=='3')
            *str='e';
        else if (*str=='!')
            *str='i';
        else if (*str=='0')
            *str='o';
        else if (*str=='#')
            *str='u';
        ++str;
    }
}

void generate_Password(char *password, int len)
{
    //Function to generate a unique password of length 'len'
    char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int charset_len = strlen(charset);
    srand(time(NULL));
    for(int i = 0; i < len; i++)
    {
        int index = rand() % charset_len;
        password[i] = charset[index];
    }
    password[len] = '\0';
}

int main()
{
    struct password pass[10];
    int i, option;
    char ch, confirm[50], loginuser[50], loginpass[50];
    const int password_len = 8;
    printf("Welcome! Let's manage your passwords.\n");
    do{
        printf("\n\n\t1-Create a new password\n\t2-Display passwords\n\t3-Login to a profile\n\t4-Exit\n\tEnter your choice: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                printf("\nEnter your username: ");
                scanf("%s",pass[i].username);
                ch = ' ';
                while (ch != 'y' && ch != 'n')
                {
                    printf("\nDo you want to generate a password? (y/n): ");
                    scanf(" %c",&ch);
                    if (ch == 'y')
                        generate_Password(pass[i].password, password_len);
                    else if (ch == 'n')
                    {
                        printf("\nEnter password: ");
                        scanf("%s",pass[i].password);
                        encrypt(pass[i].password);
                    }
                    else
                    {
                        printf("\nInvalid choice.\n");
                        ch = ' ';
                    }
                }
                printf("\nYour password is: %s\n",pass[i].password);
                printf("\nPlease confirm the password: ");
                scanf("%s",confirm);
                decrypt(pass[i].password);
                if(strcmp(pass[i].password, confirm) == 0)
                {
                    printf("\nPassword stored successfully!\n");
                    ++i;
                }
                else
                {
                    printf("\nPasswords don't match!\n");
                }
                break;
            
            case 2:
                if (i > 0)
                {
                    printf("\nYour passwords are:");
                    for(int j = 0; j < i ; j++)
                    {
                        printf("\n\tUsername: %s\n\tPassword: %s\n", pass[j].username, pass[j].password);
                    }
                }
                else
                {
                    printf("\nYou haven't stored any passwords yet!\n");
                }
                break;
            
            case 3:
                printf("\nPlease login to your profile.\n");
                printf("\nEnter your username: ");
                scanf("%s", loginuser);
                ch = ' ';
                while (ch != 'y' && ch != 'n')
                {
                    printf("\nDo you want to remember your password from past logins? (y/n): ");
                    scanf(" %c",&ch);
                    if (ch == 'y')
                    {
                        for (int j = 0; j < i; j++)
                        {
                            if(strcmp(pass[j].username, loginuser) == 0)
                            {
                                printf("\nYour password is: %s\n", pass[j].password);
                                decrypt(pass[j].password);
                                printf("\nWelcome back, %s!\n", loginuser);
                            }
                        }
                    }
                    else if (ch == 'n')
                    {
                        printf("\nEnter your password: ");
                        scanf("%s",loginpass);
                        encrypt(loginpass);
                        for (int j = 0; j < i; j++)
                        {
                            if(strcmp(pass[j].username, loginuser) == 0 && strcmp(pass[j].password, loginpass) == 0)
                            {
                                decrypt(pass[j].password);
                                printf("\nWelcome back, %s!\n", loginuser);
                            }
                            else if (strcmp(pass[j].username, loginuser) == 0 && strcmp(pass[j].password, loginpass) != 0)
                            {
                                printf("\nIncorrect password!\n");
                                ch = ' ';
                            }
                        }
                    }
                    else
                    {
                        printf("\nInvalid choice.\n");
                        ch = ' ';
                    }
                }
                break;
            
            case 4:
                break;

            default:
                printf("\nInvalid choice. Try Again.\n");
        }
    } while(option != 4);

    printf("\nExiting password manager!\n");

    return 0;
}