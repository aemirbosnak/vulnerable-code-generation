//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: portable
#include<stdio.h>
#include<string.h>

/*Function to check password strength*/
int checkPasswordStrength(char* password)
{
    int len = strlen(password);
    int score = 0;
    
    /*Scoring rules*/ 
    if (len >= 8) {
        score++;
    }
    if (len >= 12) {
        score++;
    }
    if (len >= 14) {
        score++;
    }
    if (len >= 16) {
        score++;
    }
    
    int hasDigit = 0;
    int hasLower = 0;
    int hasUpper = 0;
    int hasSpecial = 0;
    
    for (int i = 0; i < len; i++)
    {
        /*Counting digits*/ 
        if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
            continue;
        }
        
        /*Counting lowercase letters*/
        if (password[i] >= 'a' && password[i] <= 'z') {
            hasLower = 1;
            continue;
        }
        
        /*Counting uppercase letters*/
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUpper = 1;
            continue;
        }
        
        /*Counting special characters*/
        if ((password[i] >= ' ' && password[i] <= '/') || 
            (password[i] >= ':' && password[i] <= '@') || 
            (password[i] >= '[' && password[i] <= '`') || 
            (password[i] >= '{' && password[i] <= '~'))
        {
            hasSpecial = 1;
        }
    }
    
    /*Adding scores as per rules*/
    if (hasDigit == 1) {
        score++;
    }
    if (hasLower == 1) {
        score++;
    }
    if (hasUpper == 1) {
        score++;
    }
    if (hasSpecial == 1) {
        score++;
    }
    
    return score;
}

int main() 
{
    char password[50];
    printf("Enter password to check strength:\n");
    scanf("%s", password);
    
    int score = checkPasswordStrength(password);
    printf("Password strength score: %d\n", score);
    
    /*Password score description*/
    if (score == 0) {
        printf("Very weak\n");
    }
    else if (score == 1) {
        printf("Weak\n");
    }
    else if (score == 2) {
        printf("Moderate\n");
    }
    else if (score == 3) {
        printf("Strong\n");
    }
    else {
        printf("Very strong\n");
    }
    return 0;
}