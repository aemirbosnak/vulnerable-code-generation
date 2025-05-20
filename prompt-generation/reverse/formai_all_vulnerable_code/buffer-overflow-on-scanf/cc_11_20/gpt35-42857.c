//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_PASS_LEN 8 //minimum length of password
#define MAX_PASS_LEN 20 //maximum length of password

int main()
{
    char password[MAX_PASS_LEN + 1]; //the password string
    int length; //the length of the password
    int lowercase, uppercase, digits, symbols; //flags for character types
    int i; //loop variable

    srand(time(NULL)); //seed the randomizer

    do {
        //initialize variables to zero
        lowercase = uppercase = digits = symbols = 0;

        //ask the user for a length
        printf("How long would you like your password to be? (must be between %d and %d characters): ", MIN_PASS_LEN, MAX_PASS_LEN);
        scanf("%d", &length);

        //make sure the length is valid
        if (length < MIN_PASS_LEN || length > MAX_PASS_LEN) {
            printf("Invalid length!\n"); //error message
            continue; //restart the loop
        }

        for (i = 0; i < length; i++) {
            switch (rand() % 4) { //choose a character type at random
                case 0: //lowercase letter
                    password[i] = 'a' + rand() % 26;
                    lowercase = 1;
                    break;

                case 1: //uppercase letter
                    password[i] = 'A' + rand() % 26;
                    uppercase = 1;
                    break;

                case 2: //digit
                    password[i] = '0' + rand() % 10;
                    digits = 1;
                    break;

                case 3: //symbol
                    password[i] = "!@#$%^&*()_+-=,./<>?;:'\"[]{}\\|~`" [rand() % 28];
                    symbols = 1;
                    break;
            }
        }

        //make sure every character type is represented
        if (!lowercase || !uppercase || !digits || !symbols) {
            continue;
        }

        //add a null terminator to the end of the string
        password[length] = '\0';

        //print the password to the user
        printf("Your password is: %s\n", password);

        //ask the user if they want to generate another password
        printf("Would you like to generate another password? (y/n): ");
        getchar(); //clear the input buffer
    } while (tolower(getchar()) == 'y');

    return 0;
}