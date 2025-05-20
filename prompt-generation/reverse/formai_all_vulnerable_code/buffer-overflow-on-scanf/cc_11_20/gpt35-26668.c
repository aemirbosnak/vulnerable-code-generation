//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 20

int main()
{
    char password[MAX_LENGTH];
    int length, i, is_special_char = 0, is_capital_letter = 0, is_lower_case_letter = 0, is_digit = 0;
    srand(time(NULL));

    printf("Enter password length (max %d characters): ", MAX_LENGTH);
    scanf("%d", &length);

    if (length <= 0 || length > MAX_LENGTH)
    {
        printf("Invalid password length.\n");
        return 1;
    }

    while(1)
    {
        for(i = 0; i < length; i++)
        {
            int choice = rand() % 4;
            switch(choice)
            {
                case 0:
                    password[i] = rand() % 26 + 'a'; // Lower case letter
                    is_lower_case_letter = 1;
                    break;
                case 1:
                    password[i] = rand() % 26 + 'A'; // Capital letter
                    is_capital_letter = 1;
                    break;
                case 2:
                    password[i] = rand() % 10 + '0'; // Digit
                    is_digit = 1;
                    break;
                case 3:
                    password[i] = rand() % 15 + '!'; // Special character
                    is_special_char = 1;
                    break;
            }
        }

        password[length] = '\0';

        if(is_special_char && is_capital_letter && is_lower_case_letter && is_digit)
        {
            printf("Generated secure password: %s\n", password);
            break;
        }

        is_special_char = 0;
        is_capital_letter = 0;
        is_lower_case_letter = 0;
        is_digit = 0;
    }

    return 0;
}