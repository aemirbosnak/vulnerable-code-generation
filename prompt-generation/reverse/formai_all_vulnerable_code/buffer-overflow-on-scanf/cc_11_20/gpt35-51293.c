//FormAI DATASET v1.0 Category: Password management ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main() {
    char password[20];
    char confirm_password[20];

    printf("Enter a password: ");
    scanf("%s", password);

    printf("Confirm password: ");
    scanf("%s", confirm_password);

    /* Check if passwords match */
    if(strcmp(password, confirm_password) != 0) {
        printf("Passwords do not match. Try again.\n");
        exit(0);
    }

    /* Check length of password */
    if(strlen(password) < 8) {
        printf("Password must be at least 8 characters long.\n");
        exit(0);
    }

    /* Check if password has uppercase and lowercase characters */
    int i, has_lower = 0, has_upper = 0;
    for(i = 0; i < strlen(password); i++) {
        if(islower(password[i]))
            has_lower = 1;
        else if(isupper(password[i]))
            has_upper = 1;
    }

    if(!has_lower || !has_upper) {
        printf("Password must contain both uppercase and lowercase characters.\n");
        exit(0);
    }

    /* Check if password has digits or special characters */
    int has_digit = 0, has_special = 0;
    for(i = 0; i < strlen(password); i++) {
        if(isdigit(password[i]))
            has_digit = 1;
        else if(!isalnum(password[i]))
            has_special = 1;
    }

    if(!has_digit || !has_special) {
        printf("Password must contain both digits and special characters.\n");
        exit(0);
    }

    /* Password passed all checks */
    printf("Password is valid.\n");
    return 0;
}