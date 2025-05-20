//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int passLength, i, num, choice;
    char password[100];
    
    printf("*** Welcome to the C Secure Password Generator ***\n\n");

    printf("How long would you like your password to be? ");
    scanf("%d", &passLength);

    srand((unsigned) time(NULL));

    printf("Choose a password format:\n");
    printf("\t1. Alphabetic characters only\n");
    printf("\t2. Alphabetic characters and numbers\n");
    printf("\t3. Alphabetic characters, numbers, and special symbols\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i = 0; i < passLength; i++)
            {
                password[i] = 'a' + (rand() % 26);
            }
            break;

        case 2:
            for(i = 0; i < passLength; i++)
            {
                num = rand() % 3;

                if(num == 0)
                    password[i] = 'a' + (rand() % 26);
                else
                    password[i] = '0' + (rand() % 10);
            }
            break;

        case 3:
            for(i = 0; i < passLength; i++)
            {
                num = rand() % 4;

                if(num == 0)
                    password[i] = 'a' + (rand() % 26);
                else if(num == 1)
                    password[i] = '0' + (rand() % 10);
                else if(num == 2)
                    password[i] = '!' + (rand() % 15);
                else
                    password[i] = '#' + (rand() % 6);
            }
            break;

        default:
            printf("Invalid input. Please choose 1, 2, or 3.\n");
            exit(0);
    }

    printf("Your password is: %s\n", password);

    printf("\nThank you for using the C Secure Password Generator!\n");

    return 0;
}