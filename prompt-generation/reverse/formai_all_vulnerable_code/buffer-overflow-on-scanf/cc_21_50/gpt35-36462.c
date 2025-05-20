//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include<stdio.h>
#include<string.h>
 
int main() {
    char password[50];
    int i, length;
    int upper = 0, lower = 0, num = 0, special = 0;
 
    printf("Enter the password: ");
    scanf("%s", password);
 
    length = strlen(password);
 
    for(i=0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z')
            upper++;
        else if(password[i] >= 'a' && password[i] <= 'z')
            lower++;
        else if(password[i] >= '0' && password[i] <= '9')
            num++;
        else
            special++;
    }
 
    printf("\nPassword Strength Checker Results\n");
    printf("------------------------------------\n");
 
    // Password length check
    if(length < 8) {
        printf("Password length is weak.\n");
        printf("Must be at least 8 characters long.\n");
    }
    else if(length >= 8 && length <= 12) {
        printf("Password length is moderate.\n");
        printf("Ideally a password between 13-24 digits are safe.\n");
    }
    else {
        printf("Password length is strong.\n");
        printf("Great! But remember to avoid sharing it with others.\n");
    }
 
    // Checking password complexity
    if(upper == 0 || lower == 0 || num == 0 || special == 0) {
        printf("Password complexity is weak.\n");
        printf("Mix of upper and lowercase, digits, and special characters is recommended.\n");
    }
    else if((upper >= 1 && lower >= 1 && num >= 1 && special == 0)
            || (upper >= 1 && lower >= 1 && num == 0 && special >= 1)
            || (upper >= 1 && lower == 0 && num >= 1 && special >= 1)
            || (upper == 0 && lower >= 1 && num >= 1 && special >= 1)) {
        printf("Password complexity is moderate.\n");
        printf("A little more improvement is recommended.\n");
    }
    else {
        printf("Password complexity is strong.\n");
        printf("Congratulations! You have a strong password.\n");
    }
 
    return 0;
}