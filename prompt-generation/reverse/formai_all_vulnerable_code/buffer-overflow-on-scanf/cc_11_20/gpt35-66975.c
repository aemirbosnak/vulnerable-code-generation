//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //initialize variables
    int passwordLength, i;
    char password[100];
    int characters[4] = {0};

    //seed the random number generator
    srand(time(0));

    //ask user for password length
    printf("How long would you like your password to be? (between 8 and 16)\n");
    scanf("%d", &passwordLength);

    //check if password length is within limits
    if(passwordLength < 8 || passwordLength > 16)
    {
        printf("Password length must be between 8 and 16 characters.\n");
    }
    else
    {
        //generate password
        for(i = 0; i < passwordLength; i++)
        {
            int category = rand() % 4; //determines character category
            
            //increment category counter
            characters[category]++;
            
            switch(category)
            {
                case 0:
                    password[i] = rand() % 10 + 48; //generate digit
                    break;
                case 1:
                    password[i] = rand() % 26 + 65; //generate uppercase letter
                    break;
                case 2:
                    password[i] = rand() % 26 + 97; //generate lowercase letter
                    break;
                case 3:
                    password[i] = rand() % 15 + 33; //generate special character
                    break;
            }
        }

        //check if all categories are present
        if(characters[0] == 0 || characters[1] == 0 || characters[2] == 0 || characters[3] == 0)
        {
            //generate new password until it includes all categories
            printf("Generated password does not contain all required categories. Regenerating...\n");

            main();
        }
        else
        {
            //print password
            printf("Your secure password is: %s\n", password);
        }
    }

    return 0;
}