//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define PASSWORD_LENGTH 10

int main()
{
    srand((unsigned int) time(NULL));
    char password[PASSWORD_LENGTH+1];
    int i, choice;

    printf("Choose your password complexity level:\n");
    printf("1. Alphabets only\n");
    printf("2. Alphabets and digits\n");
    printf("3. Alphabets, digits, and special characters\n");

    while(1)
    {
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 3)
            break;
        else
            printf("Invalid choice. Try again.\n");
    }

    switch(choice)
    {
        case 1:
            for(i = 0; i < PASSWORD_LENGTH; i++)
            {
                password[i] = rand() % 26 + 'a';
            }
            break;

        case 2:
            for(i = 0; i < PASSWORD_LENGTH; i++)
            {
                if(rand() % 2)
                    password[i] = rand() % 10 + '0';
                else
                    password[i] = rand() % 26 + 'a';
            }
            break;

        case 3:
            for(i = 0; i < PASSWORD_LENGTH; i++)
            {
                int type = rand() % 3;

                if(type == 0)
                    password[i] = rand() % 26 + 'a';
                else if(type == 1)
                    password[i] = rand() % 10 + '0';
                else
                    password[i] = rand() % 15 + '!'; // Special characters from ASCII 33 to 47

            }
            break;
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("Your generated password is: %s\n", password);

    return 0; 
}