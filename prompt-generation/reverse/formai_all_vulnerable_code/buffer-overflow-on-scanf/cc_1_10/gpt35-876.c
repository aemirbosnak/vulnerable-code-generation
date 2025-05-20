//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 16

char *generate_password(int length);

int main()
{
    int password_length;
    char *password;

    srand(time(NULL)); //set the seed for random number generation

    printf("Enter the length of password (minimum %d and maximum %d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &password_length);

    if(password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH)
    {
        printf("\nInvalid password length!\n");
        exit(EXIT_FAILURE);
    }

    password = generate_password(password_length); //generate the password

    printf("\nYour secure password is: %s\n", password);

    free(password); //de-allocate memory allocated for password

    return 0;
}

char *generate_password(int length)
{
    char *password = (char*)malloc((length+1) * sizeof(char)); //allocate memory for password

    if(!password) //if allocation fails
    {
        printf("\nMemory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i=0; i<length; i++)
    {
        int random_number = rand() % 72 + 48; //generate random number between 48 and 119 (excluding special characters)
        if(random_number > 57 && random_number < 65) //prevent special characters between 58 and 64
        {
            random_number += 7;
        }
        else if(random_number > 90 && random_number < 97) //prevent special characters between 91 and 96
        {
            random_number += 6;
        }
        password[i] = (char)random_number; //convert integer to character
    }

    password[length] = '\0'; //add null terminator

    return password;
}