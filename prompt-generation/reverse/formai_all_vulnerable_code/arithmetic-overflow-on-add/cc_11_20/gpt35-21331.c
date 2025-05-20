//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const char *lower_alphabets = "abcdefghijklmnopqrstuvwxyz";
const char *upper_alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *numbers = "0123456789";
const char *special_chars = "!@#$%^&*";

const int lower_alphabets_size = 26;
const int upper_alphabets_size = 26;
const int numbers_size = 10;
const int special_chars_size = 8;

int main()
{
    int length, i, j;
    char *password;
    int password_strength;
    int lower_alphabets_flag = 0, upper_alphabets_flag = 0, numbers_flag = 0, special_chars_flag = 0;

    printf("Enter the length of the password (at least 8 characters): ");
    scanf("%d", &length);

    if (length < 8)
    {
        printf("Password length should be at least 8 characters.\n");
        return 0;
    }

    password = (char*) malloc(sizeof(char) * (length + 1));

    srand(time(NULL));
    for (i = 0; i < length; i++)
    {
        j = rand() % 4;
        switch (j)
        {
            case 0:
                password[i] = lower_alphabets[rand() % lower_alphabets_size];
                lower_alphabets_flag = 1;
                break;
            case 1:
                password[i] = upper_alphabets[rand() % upper_alphabets_size];
                upper_alphabets_flag = 1;
                break;
            case 2:
                password[i] = numbers[rand() % numbers_size];
                numbers_flag = 1;
                break;
            case 3:
                password[i] = special_chars[rand() % special_chars_size];
                special_chars_flag = 1;
                break;
        }
    }

    if (lower_alphabets_flag == 0)
    {
        i = rand() % length;
        password[i] = lower_alphabets[rand() % lower_alphabets_size];
    }

    if (upper_alphabets_flag == 0)
    {
        i = rand() % length;
        password[i] = upper_alphabets[rand() % upper_alphabets_size];
    }

    if (numbers_flag == 0)
    {
        i = rand() % length;
        password[i] = numbers[rand() % numbers_size];
    }

    if (special_chars_flag == 0)
    {
        i = rand() % length;
        password[i] = special_chars[rand() % special_chars_size];
    }

    password[length] = '\0';

    printf("Your generated password is: %s\n", password);

    free(password);

    return 0;
}