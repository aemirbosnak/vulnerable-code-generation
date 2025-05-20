//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

/* function prototype */
void generate_password(char password[], int length);

int main()
{
    int password_length;
    char password[20];

    printf("Welcome to our Secure Password Generator!\n");
    printf("Please enter the desired length of your password (up to 20 characters): ");
    scanf("%d", &password_length);

    /* validate input */
    while (password_length < 1 || password_length > 20)
    {
        printf("Invalid length. Please enter a number between 1 and 20: ");
        scanf("%d", &password_length);
    }

    /* generate and print password */
    generate_password(password, password_length);
    printf("Your secure password is: %s\n", password);

    return 0;
}

/* function to generate a secure password */
void generate_password(char password[], int length)
{
    char symbols[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '\\', '|', ';', ':', '\'', '\"', ',', '<', '.', '>', '/', '?'};    /* array of symbols */
    char numbers[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};    /* array of numbers */
    char lowercase_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};    /* array of lowercase alphabets */
    char uppercase_alphabet[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};    /* array of uppercase alphabets */
    int num_symbols = sizeof(symbols) / sizeof(char);    /* number of symbols in symbols array */
    int num_numbers = sizeof(numbers) / sizeof(char);    /* number of numbers in numbers array */
    int num_lower = sizeof(lowercase_alphabet) / sizeof(char);    /* number of lowercase alphabets in lowercase_alphabet array */
    int num_upper = sizeof(uppercase_alphabet) / sizeof(char);    /* number of uppercase alphabets in uppercase_alphabet array */
    int i, random_num, random_index;

    /* seed random number generator */
    srand(time(0));

    /* generate random password */
    for (i = 0; i < length; i++)
    {
        random_num = rand() % 4;
        switch (random_num)
        {
        case 0:
            random_index = rand() % num_symbols;
            password[i] = symbols[random_index];
            break;
        case 1:
            random_index = rand() % num_numbers;
            password[i] = numbers[random_index];
            break;
        case 2:
            random_index = rand() % num_lower;
            password[i] = lowercase_alphabet[random_index];
            break;
        case 3:
            random_index = rand() % num_upper;
            password[i] = uppercase_alphabet[random_index];
            break;
        }
    }

    /* add random symbols to password until length is met */
    while (i < 20)
    {
        random_index = rand() % num_symbols;
        password[i] = symbols[random_index];
        i++;
    }

    /* shuffle the password */
    for (i = 0; i < length; i++)
    {
        random_index = rand() % length;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }
}