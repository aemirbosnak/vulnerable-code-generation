//Falcon-180B DATASET v1.0 Category: Password management ; Style: recursive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_SIZE 100
#define MIN_SIZE 8

//function to check if password is valid or not
int is_valid_password(char* password)
{
    int i, j, k, flag = 0;
    char temp[100] = "";
    
    //check for minimum length
    if(strlen(password) < MIN_SIZE)
        return 0;
    
    //check for maximum length
    if(strlen(password) > MAX_SIZE)
        return 0;
    
    //check for special characters
    for(i = 0; i < strlen(password); i++)
    {
        if(!isalpha(password[i]))
        {
            flag = 1;
            break;
        }
    }
    if(!flag)
        return 0;
    
    //check for consecutive characters
    for(i = 0; i < strlen(password); i++)
    {
        for(j = i + 1; j < strlen(password); j++)
        {
            if(password[i] == password[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag)
            break;
    }
    if(flag)
        return 0;
    
    return 1;
}

//recursive function to generate random password
void generate_password(char* password, int length)
{
    if(length == 0)
    {
        password[0] = '\0';
        return;
    }
    
    //generate random character
    int random_char = rand() % 26 + 65; //A to Z
    password[length - 1] = random_char;
    
    //recursive call to generate remaining password
    generate_password(password, length - 1);
}

//main function
int main()
{
    char password[MAX_SIZE];
    int length = 0;
    
    printf("Enter the length of password (between %d and %d): ", MIN_SIZE, MAX_SIZE);
    scanf("%d", &length);
    
    //generate random password
    generate_password(password, length);
    
    //check if password is valid or not
    if(is_valid_password(password))
        printf("Valid password: %s\n", password);
    else
        printf("Invalid password\n");
    
    return 0;
}