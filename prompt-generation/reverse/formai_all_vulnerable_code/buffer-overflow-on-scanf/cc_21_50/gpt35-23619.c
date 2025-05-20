//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int length, i, randNum;
    char password[20];

    printf("Welcome to the exciting new Secure Password Generator!\n");
    printf("Please enter the length of the password you would like to generate (between 8 and 20 characters): ");
    scanf("%d", &length);

    while(length < 8 || length > 20)
    {
        printf("Oops! Please enter a number between 8 and 20: ");
        scanf("%d", &length);
    }

    srand(time(0)); //initialize random number generator with current time

    for (i = 0; i < length; i++) //generate each character one at a time
    {
        randNum = rand() % 74; //generate a random number between 0 and 73

        //map randNum to a corresponding ASCII character
        if (randNum < 10) //numbers 0-9
        {
            password[i] = randNum + '0';
        }
        else if (randNum < 36) //capital letters A-Z
        {
            password[i] = randNum - 10 + 'A';
        }
        else if (randNum < 62) //lowercase letters a-z
        {
            password[i] = randNum - 36 + 'a';
        }
        else //special characters
        {
            int specCharNum = randNum - 62 + 1; //offset by one to avoid null terminator

            switch(specCharNum)
            {
                case 1:
                    password[i] = '!';
                    break;
                case 2:
                    password[i] = '@';
                    break;
                case 3:
                    password[i] = '#';
                    break;
                case 4:
                    password[i] = '$';
                    break;
                case 5:
                    password[i] = '%';
                    break;
                case 6:
                    password[i] = '^';
                    break;
                case 7:
                    password[i] = '&';
                    break;
                case 8:
                    password[i] = '*';
                    break;
                case 9:
                    password[i] = '(';
                    break;
                case 10:
                    password[i] = ')';
                    break;
                case 11:
                    password[i] = '-';
                    break;
                case 12:
                    password[i] = '_';
                    break;
                case 13:
                    password[i] = '+';
                    break;
                case 14:
                    password[i] = '=';
                    break;
                case 15:
                    password[i] = '{';
                    break;
                case 16:
                    password[i] = '}';
                    break;
                case 17:
                    password[i] = '[';
                    break;
                case 18:
                    password[i] = ']';
                    break;
                case 19:
                    password[i] = '|';
                    break;
                case 20:
                    password[i] = '\\';
                    break;
                case 21:
                    password[i] = ';';
                    break;
                case 22:
                    password[i] = ':';
                    break;
                case 23:
                    password[i] = '"';
                    break;
                case 24:
                    password[i] = '<';
                    break;
                case 25:
                    password[i] = '>';
                    break;
                case 26:
                    password[i] = ',';
                    break;
                case 27:
                    password[i] = '.';
                    break;
                case 28:
                    password[i] = '?';
                    break;
            }
        }
    }

    printf("\nYour exciting new password is: %s\n", password);

    return 0;
}