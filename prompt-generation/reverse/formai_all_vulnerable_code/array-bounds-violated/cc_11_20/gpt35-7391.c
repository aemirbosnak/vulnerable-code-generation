//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define PASSWORD_LENGTH 16 

int main() 
{
    srand((unsigned int) time(NULL)); 

    const char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char numbers[] = "0123456789";
    const char special_chars[] = "!@#$%^&*()_+-=";

    int password_len, lowercase_len, uppercase_len, numbers_len, special_chars_len, i;
    char password[PASSWORD_LENGTH];

    password_len = 0; 
    lowercase_len = sizeof(lowercase)-1; 
    uppercase_len = sizeof(uppercase)-1; 
    numbers_len = sizeof(numbers)-1; 
    special_chars_len = sizeof(special_chars)-1; 

    while(password_len < PASSWORD_LENGTH) 
    {
        int char_type = rand() % 4; // pick a random character type
        switch(char_type) {
            case 0:
                if(password_len == 0 || (rand() % 2 == 0)) { // make sure at least 1 lowercase letter is present
                    password[password_len++] = lowercase[rand() % lowercase_len];
                }
                break;

            case 1:
                if(rand() % 2 == 0) { // randomly include uppercase letters
                    password[password_len++] = uppercase[rand() % uppercase_len];
                }
                break;

            case 2:
                if(rand() % 2 == 0) { // randomly include numbers
                    password[password_len++] = numbers[rand() % numbers_len];
                }
                break;

            case 3:
                if(rand() % 2 == 0) { // randomly include special characters
                    password[password_len++] = special_chars[rand() % special_chars_len];
                }
                break;
        }
    }

    password[password_len] = '\0'; // terminate string
    printf("Your secure password is: %s\n", password);

    return 0;
}