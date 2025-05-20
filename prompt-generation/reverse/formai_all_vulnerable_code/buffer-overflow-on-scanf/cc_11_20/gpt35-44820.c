//FormAI DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// define maximum length of password
#define MAX_PASSWORD_LENGTH 20

bool checkPassword(char password[])
{
    // check if password is too short
    if (strlen(password) < 8) {
        printf("Password is too short.\n");
        return false;
    }
    
    // check if password contains uppercase letters
    bool uppercase = false;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            uppercase = true;
            break;
        }
    }
    if (!uppercase) {
        printf("Password must contain at least one uppercase letter.\n");
        return false;
    }
    
    // check if password contains lowercase letters
    bool lowercase = false;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            lowercase = true;
            break;
        }
    }
    if (!lowercase) {
        printf("Password must contain at least one lowercase letter.\n");
        return false;
    }
    
    // check if password contains digits
    bool digits = false;
    for (int i = 0; i < strlen(password); i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            digits = true;
            break;
        }
    }
    if (!digits) {
        printf("Password must contain at least one digit (0-9).\n");
        return false;
    }
    
    // check if password contains special characters
    bool special = false;
    for (int i = 0; i < strlen(password); i++) {
        if (!(password[i] >= 'a' && password[i] <= 'z')
            && !(password[i] >= 'A' && password[i] <= 'Z')
            && !(password[i] >= '0' && password[i] <= '9')) {
            special = true;
            break;
        }
    }
    if (!special) {
        printf("Password must contain at least one special character (such as !,@,#,$,%,^,&,*,(,)).\n");
        return false;
    }
    
    // password is valid
    printf("Password is valid.\n");
    return true;
}

int main()
{
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter password: ");
    scanf("%s", password);
    checkPassword(password);
    return 0;
}