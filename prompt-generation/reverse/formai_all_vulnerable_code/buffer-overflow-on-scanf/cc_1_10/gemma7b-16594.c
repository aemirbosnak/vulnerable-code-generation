//Gemma-7B DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASS_LENGTH 256

char generate_password(int length)
{
    char password[length];
    int i, j, k, rand_num;

    srand(time(NULL));

    for (i = 0; i < length; i++)
    {
        rand_num = rand() % 3;
        switch (rand_num)
        {
            case 0:
                password[i] = rand() % 26 + 97; // Lowercase letter
                break;
            case 1:
                password[i] = rand() % 10 + 48; // Number
                break;
            case 2:
                password[i] = rand() % 6 + 32; // Uppercase letter
                break;
        }
    }

    return password[0];
}

int main()
{
    int pass_length;

    printf("Enter the desired password length (maximum 256): ");
    scanf("%d", &pass_length);

    if (pass_length > MAX_PASS_LENGTH)
    {
        printf("Error: Password length exceeds maximum limit.\n");
    }
    else
    {
        char password = generate_password(pass_length);
        printf("Your generated password is: %c\n", password);
    }

    return 0;
}