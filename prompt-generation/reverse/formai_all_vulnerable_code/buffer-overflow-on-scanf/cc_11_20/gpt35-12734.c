//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int length, i, choice;
    char password[50];

    srand(time(NULL));

    printf("Welcome to the C Secure Password Generator!\n\n");

    printf("Enter the desired length of the password: ");
    scanf("%d", &length);
    if(length < 8)
    {
        printf("\nPassword length should be at least 8 characters long.\n");
        exit(0);
    }

    printf("\nSelect from the following options:\n");
    printf("\n1. Only lowercase letters");
    printf("\n2. Only uppercase letters");
    printf("\n3. Lowercase and uppercase letters");
    printf("\n4. Lowercase, uppercase letters and numbers");
    printf("\n5. Lowercase, uppercase letters, numbers and special characters");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            for(i=0; i<length; i++)
            {
                password[i] = rand()%26 + 97;
            }
            break;
        case 2:
            for(i=0; i<length; i++)
            {
                password[i] = rand()%26 + 65;
            }
            break;
        case 3:
            for(i=0; i<length; i++)
            {
                if(i%2 == 0)
                {
                    password[i] = rand()%26 + 97;
                }
                else
                {
                    password[i] = rand()%26 + 65;
                }
            }
            break;
         case 4:
            for(i=0; i<length; i++)
            {
                int temp = rand()%3;
                if(temp == 0)
                {
                    password[i] = rand()%26 + 97;
                }
                else if(temp == 1)
                {
                    password[i] = rand()%26 + 65;
                }
                else
                {
                    password[i] = rand()%10 + 48;
                }
            }
            break;
         case 5:
            for(i=0; i<length; i++)
            {
                int temp = rand()%4;
                if(temp == 0)
                {
                    password[i] = rand()%26 + 97;
                }
                else if(temp == 1)
                {
                    password[i] = rand()%26 + 65;
                }
                else if(temp == 2)
                {
                    password[i] = rand()%10 + 48;
                }
                else
                {
                    password[i] = rand()%15 + 33;
                }
            }
            break;
         default:
            printf("\nInvalid choice entered.\n");
            exit(0);
    }

    printf("\nYour password is: ");
    for(i=0; i<length; i++)
    {
        printf("%c", password[i]);
    }

    printf("\n\nThank you for using the C Secure Password Generator.\n");
    return 0;
}