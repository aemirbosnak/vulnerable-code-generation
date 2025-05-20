//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));  //seed the random number generator with current time

    //define variables for password generation
    int length, i, option;
    char password[50];

    //ask the user for password length and complexity level
    printf("Enter the password length: ");
    scanf("%d", &length);
    printf("Enter the complexity level (1-3):\n");
    printf("1. Only lowercase letters\n2. Lowercase and uppercase letters\n3. Lowercase, uppercase and digits\n");
    scanf("%d", &option);

    //generate the password based on user requirements
    switch (option)
    {
        case 1: //only lowercase letters
            for (i = 0; i < length; i++)
            {
                password[i] = rand() % 26 + 97; //ASCII code for lowercase letters
            }
            break;
        case 2: //lowercase and uppercase letters
            for (i = 0; i < length; i++)
            {
                int type = rand() % 2; //randomly select lowercase or uppercase letter
                if (type == 0) 
                {
                    password[i] = rand() % 26 + 65; //ASCII code for uppercase letters
                }
                else 
                {
                    password[i] = rand() % 26 + 97; //ASCII code for lowercase letters
                }
            }
            break;
        case 3: //lowercase, uppercase and digits
            for (i = 0; i < length; i++)
            {
                int type = rand() % 3; //randomly select lowercase, uppercase or digit
                if (type == 0) 
                {
                    password[i] = rand() % 26 + 65; //ASCII code for uppercase letters
                }
                else if (type == 1)
                {
                    password[i] = rand() % 26 + 97; //ASCII code for lowercase letters
                }
                else
                {
                    password[i] = rand() % 10 + 48; //ASCII code for digits
                }
            }
            break;
        default:
            printf("Invalid option!\n");
            return 0;
    }

    //print the generated password
    printf("Your randomly generated password is: ");
    for (i = 0; i < length; i++)
    {
        printf("%c", password[i]);
    }
    printf("\n");

    return 0;
}