//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 8
#define CHARACTER_SET "!@#$%^&*()_+-=`~[{]}\\|;:\'\",<.>/?0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

char* generate_password(int length)
{
    char* password = (char*) malloc(sizeof(char) * (length + 1)); // allocating memory for the password

    int i;
    for(i = 0; i < length; i++)
    {
        int random_index = rand() % strlen(CHARACTER_SET); //selecting a random index for the character set
        password[i] = CHARACTER_SET[random_index]; //copying the character at the randomly chosen index to the password
    }
    password[length] = '\0'; //adding a null terminator to the end of the password to indicate the end of the string

    return password; //returning the generated password
}

int main()
{
    int length;
    srand(time(NULL)); //seeding the random number generator with the current time

    printf("Welcome to the Secure Password Generator\n\n");

    while(1)
    {
        printf("Enter the length of the password(min %d, max %d): ", MIN_LENGTH, MAX_LENGTH);
        scanf("%d", &length);

        if(length < MIN_LENGTH || length > MAX_LENGTH)
        {
            printf("Invalid length. Please enter a length between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
            continue;
        }

        char* password = generate_password(length);

        printf("\nYour generated password is: %s\n\n", password);

        free(password); //freeing the memory allocated for the password

        break; //exit the while loop since a valid password has been generated
    }

    return 0;
}