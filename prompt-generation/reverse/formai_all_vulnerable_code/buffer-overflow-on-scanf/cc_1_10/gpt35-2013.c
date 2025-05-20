//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: artistic
//ARTISTIC INTRUSION DETECTION SYSTEM

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

//function to generate random number between range
int rand_gen(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

//function to check for invalid characters
int check_chars(char word[])
{
    for(int i=0; i<strlen(word); i++)
    {
        if(!isalpha(word[i]) && !isdigit(word[i]) && word[i] != '.' && word[i] != '_')
            return 0;
    }
    return 1;
}

//function to check dictionary attack
int dict_attack(char* username, char* password)
{
    char dictionary[100][100] = {"password", "admin", "root", "123456", "qwerty", "letmein", "iloveyou", "monkey", "sunshine", "football", "baseball", "welcome", "trustno1"};
    for(int i=0; i<13; i++)
    {
        if(strcmp(dictionary[i], password) == 0 || strcmp(dictionary[i], username) == 0)
            return 1;
    }
    return 0;
}

//function to check brute force attack
int brute_force(char* username, char* password)
{
    int attempts = 0;
    int rand_num;
    while(attempts < 5)
    {
        for(int i=0; i<strlen(password); i++)
        {
            rand_num = rand_gen(33, 126);
            if(rand_num != password[i])
                break;
            else if(i == strlen(password)-1)
                return 1;
        }
        attempts++;
    }
    return 0;
}

//function to check for repeated characters in password
int repeat_chars(char password[])
{
    int repeat = 0;
    for(int i=0; i<strlen(password)-2; i++)
    {
        if(password[i] == password[i+1] && password[i] == password[i+2])
            repeat = 1;
    }
    return repeat;
}

int main()
{
    char username[20], password[20];
    int invalid_char, dict, brute, repeat, flag;
    srand(time(0));

    printf("\nINTRUSION DETECTION SYSTEM\n");

    while(1)
    {
        flag = 1;

        printf("\nEnter username: ");
        scanf("%s", username);

        printf("Enter password: ");
        scanf("%s", password);

        invalid_char = check_chars(username) && check_chars(password);

        dict = dict_attack(username, password);

        brute = brute_force(username, password);

        repeat = repeat_chars(password);

        if(invalid_char == 0)
        {
            printf("\nERROR: Invalid characters in username and/or password.\n");
            flag = 0;
        }

        if(dict == 1)
        {
            printf("\nALERT: Dictionary attack detected!\n");
            flag = 0;
        }

        if(brute == 1)
        {
            printf("\nALERT: Brute force attack detected!\n");
            flag = 0;
        }

        if(repeat == 1)
        {
            printf("\nERROR: Password contains repeated characters.\n");
            flag = 0;
        }

        if(flag == 1)
        {
            printf("\nLogin successful!\n");
            break;
        }
    }
    return 0;
}