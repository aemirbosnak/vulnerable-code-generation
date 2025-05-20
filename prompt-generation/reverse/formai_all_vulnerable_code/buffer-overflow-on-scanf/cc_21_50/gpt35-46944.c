//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main() 
{
    int length = 0, uppercase = 0, lowercase = 0, numbers = 0, specialchars = 0;
    char password[100] = {'\0'}; //initialize the password with null characters
    char choices[4] = {'\0'}; //choices will be used to determine which type of character to add to password
    int i;

    printf("Welcome to Secure Password Generator!\n");
    printf("-------------------------------------\n");

    //get user input for password criteria
    printf("How long would you like your password to be? (min 8)\n");
    scanf("%d", &length);

    printf("Would you like Uppercase letters? (y/n)\n");
    scanf(" %c", &choices[0]);

    printf("Would you like Lowercase letters? (y/n)\n");
    scanf(" %c", &choices[1]);

    printf("Would you like Numbers? (y/n)\n");
    scanf(" %c", &choices[2]);

    printf("Would you like Special Characters? (y/n)\n");
    scanf(" %c", &choices[3]);

    //check if user has entered at least one type of character
    if(!('y' == choices[0] || 'y' == choices[1] || 'y' == choices[2] || 'y' == choices[3])) 
    {
        printf("You did not select any character types. Exiting program...\n");
        return 0;
    }

    srand(time(0)); //set seed for rand() function using system time

    while(1) //loop until all criteria are met for password
    {
        i = rand() % 4; //choose a random index from choices array

        if(choices[i] == 'y') //if chosen character type is required, add it to password
        {
            if(i == 0) //uppercase
            {
                password[length] = rand() % (90 - 65 + 1) + 65; 
                uppercase++;

                if(uppercase == 2) //if two uppercase letters have been added, remove uppercase choice from choices array
                {
                    choices[0] = 'n';
                }
            }
            else if(i == 1) //lowercase
            {
                password[length] = rand() % (122 - 97 + 1) + 97; 
                lowercase++;

                if(lowercase == 2) //if two lowercase letters have been added, remove lowercase choice from choices array
                {
                    choices[1] = 'n';
                }
            }
            else if(i == 2) //numbers
            {
                password[length] = rand() % (57 - 48 + 1) + 48; 
                numbers++;

                if(numbers == 2) //if two numbers have been added, remove numbers choice from choices array
                {
                    choices[2] = 'n';
                }
            }
            else if(i == 3) //special characters
            {
                password[length] = rand() % (126 - 33 + 1) + 33; 
                specialchars++;

                if(specialchars == 2) //if two special characters have been added, remove special characters choice from choices array
                {
                    choices[3] = 'n';
                }
            }

            length++;

            if(length == 8 && (uppercase || lowercase || numbers || specialchars)) //check if password meets minimum length and has at least one type of character
            {
                break;
            }
        }
    }

    //if password length still needs to be met, add random characters until criteria are met
    while(length < 20) 
    {
        i = rand() % 4;

        if(choices[i] == 'y') //if chosen character type is required, add it to password
        {
            if(i == 0) //uppercase
            {
                password[length] = rand() % (90 - 65 + 1) + 65; 
                uppercase++;
            }
            else if(i == 1) //lowercase
            {
                password[length] = rand() % (122 - 97 + 1) + 97; 
                lowercase++;
            }
            else if(i == 2) //numbers
            {
                password[length] = rand() % (57 - 48 + 1) + 48; 
                numbers++;
            }
            else if(i == 3) //special characters
            {
                password[length] = rand() % (126 - 33 + 1) + 33; 
                specialchars++;
            }

            length++;

            if(uppercase == 2 && lowercase == 2 && numbers == 2 && specialchars == 2) //break loop if all criteria have been met
            {
                break;
            }
        }
    }

    //shuffle password array
    for(i = 0; i < length; i++) 
    {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    //print out final password
    printf("Your secure password is: ");
    for(i = 0; i < length; i++)
    {
        printf("%c", password[i]);
    }

    printf("\n");

    return 0;
}