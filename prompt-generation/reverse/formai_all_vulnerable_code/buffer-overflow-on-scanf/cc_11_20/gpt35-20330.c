//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int length, i, option, countUpper = 0, countLower = 0, countDigit = 0, countSpecial = 0;
    char password[50];

    printf("Welcome to the Password Generator!\n");
    printf("----------------------------------\n");

    printf("Enter the length of your password (between 8 and 50): ");
    scanf("%d", &length);

    while(length > 50 || length < 8)
    {
        printf("Invalid length. Please enter a number between 8 and 50: ");
        scanf("%d", &length);
    }

    printf("Select your password complexity:\n");
    printf("1. Low (only lowercase letters)\n");
    printf("2. Medium (lowercase letters and digits)\n");
    printf("3. High (lowercase and uppercase letters, digits and special characters)\n");
    printf("Option: ");
    scanf("%d", &option);

    srand(time(NULL));

    switch(option)
    {
        case 1:
            for(i = 0; i < length; i++)
            {
                password[i] = rand()%26 + 97;
                countLower++;
            }
            break;
        case 2:
            for(i = 0; i < length; i++)
            {
                int choice = rand()%2;
                if(choice == 0)
                {
                    password[i] = rand()%26 + 97;
                    countLower++;
                }
                else
                {
                    password[i] = rand()%10 + 48;
                    countDigit++;
                }
            }
            break;
        case 3:
            for(i = 0; i < length; i++)
            {
                int choice = rand()%4;
                if(choice == 0)
                {
                    password[i] = rand()%26 + 97;
                    countLower++;
                }
                else if(choice == 1)
                {
                    password[i] = rand()%26 + 65;
                    countUpper++;
                }
                else if(choice == 2)
                {
                    password[i] = rand()%10 + 48;
                    countDigit++;
                }
                else
                {
                    password[i] = rand()%15 + 33;
                    countSpecial++;
                }
            }
            break;
        default:
            printf("Invalid option selected.\n");
            return 0;
    }

    printf("\nYour password is: ");
    for(i = 0; i < length; i++)
    {
        printf("%c", password[i]);
    }

    printf("\n");
    printf("Password Complexity:\n");
    printf("Lowercase Letters: %d\n", countLower);
    printf("Uppercase Letters: %d\n", countUpper);
    printf("Digits: %d\n", countDigit);
    printf("Special Characters: %d\n", countSpecial);

    return 0;
}