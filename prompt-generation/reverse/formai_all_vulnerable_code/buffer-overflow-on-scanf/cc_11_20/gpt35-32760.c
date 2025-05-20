//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char password[16];
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char numbers[] = "0123456789";
    char symbols[] = "!@#$%^&*()_+-={}[]\\|:;\"'<>,.?/";

    srand(time(NULL));

    printf("Welcome to the Secure Password Generator!\n\n");
    printf("Please select your preferences:\n");
    printf("1. Include lowercase letters\n");
    printf("2. Include uppercase letters\n");
    printf("3. Include numbers\n");
    printf("4. Include symbols\n");
    printf("5. Include all of the above\n\n");

    int choice;
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    int index;
    switch (choice)
    {
        case 1:
            for (int i = 0; i < 16; i++)
            {
                index = rand() % strlen(lowercase);
                password[i] = lowercase[index];
            }
            break;

        case 2:
            for (int i = 0; i < 16; i++)
            {
                index = rand() % strlen(uppercase);
                password[i] = uppercase[index];
            }
            break;

        case 3:
            for (int i = 0; i < 16; i++)
            {
                index = rand() % strlen(numbers);
                password[i] = numbers[index];
            }
            break;

        case 4:
            for (int i = 0; i < 16; i++)
            {
                index = rand() % strlen(symbols);
                password[i] = symbols[index];
            }
            break;

        case 5:
            for (int i = 0; i < 4; i++)
            {
                index = rand() % strlen(lowercase);
                password[i] = lowercase[index];
            }

            for (int i = 4; i < 8; i++)
            {
                index = rand() % strlen(uppercase);
                password[i] = uppercase[index];
            }

            for (int i = 8; i < 12; i++)
            {
                index = rand() % strlen(numbers);
                password[i] = numbers[index];
            }

            for (int i = 12; i < 16; i++)
            {
                index = rand() % strlen(symbols);
                password[i] = symbols[index];
            }
            break;

        default:
            printf("Invalid choice!");
            return 0;
    }

    printf("\nYour password is: %s\n", password);

    return 0;
}