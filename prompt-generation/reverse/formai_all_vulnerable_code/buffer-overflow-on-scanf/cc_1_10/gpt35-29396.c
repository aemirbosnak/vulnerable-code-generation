//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: accurate
#include <stdio.h> 
#include <ctype.h> 

// Function to check for uppercase letters 
int hasUpper(char* str) 
{ 
    for(int i = 0; str[i] != '\0'; i++) 
    { 
        if (isupper(str[i])) 
            return 1; 
    } 
    return 0; 
} 

// Function to check for lowercase letters 
int hasLower(char* str) 
{ 
    for(int i = 0; str[i] != '\0'; i++) 
    { 
        if (islower(str[i])) 
            return 1; 
    } 
    return 0; 
} 

// Function to check for digits 
int hasDigit(char* str) 
{ 
    for(int i = 0; str[i] != '\0'; i++) 
    { 
        if (isdigit(str[i])) 
            return 1; 
    } 
    return 0; 
} 

// Function to check for special characters 
int hasSpecial(char* str) 
{ 
    for(int i = 0; str[i] != '\0'; i++) 
    { 
        if (!(isdigit(str[i]) || isalpha(str[i]))) 
            return 1; 
    } 
    return 0; 
} 

// Function to check password strength 
int passwordStrength(char* str) 
{ 
    int len = 0, strength = 0; 
    
    // Calculate password length 
    for(int i = 0; str[i] != '\0'; i++) 
    { 
        len++; 
    } 
    
    // Calculate password strength based on length 
    if(len <= 6) 
    { 
        strength = 0; 
    } 
    else if(len <= 10) 
    { 
        strength = 1; 
    } 
    else if(len <= 14) 
    { 
        strength = 2; 
    } 
    else 
    { 
        strength = 3; 
    } 
    
    // Check for uppercase letters 
    if(hasUpper(str)) 
    { 
        strength++; 
    } 
    
    // Check for lowercase letters 
    if(hasLower(str)) 
    { 
        strength++; 
    } 
    
    // Check for digits 
    if(hasDigit(str)) 
    { 
        strength++; 
    } 
    
    // Check for special characters 
    if(hasSpecial(str)) 
    { 
        strength++; 
    } 
    
    return strength; 
} 

int main() 
{ 
    char password[20]; 
    
    // Get password input from user 
    printf("Enter Password: "); 
    scanf("%s", password); 
    
    // Check password strength 
    int strength = passwordStrength(password); 
    
    // Output password strength 
    if(strength == 0) 
    { 
        printf("Password Strength: Very Weak"); 
    } 
    else if(strength == 1) 
    { 
        printf("Password Strength: Weak"); 
    } 
    else if(strength == 2) 
    { 
        printf("Password Strength: Moderate"); 
    } 
    else if(strength == 3) 
    { 
        printf("Password Strength: Strong"); 
    } 
    else if(strength == 4) 
    { 
        printf("Password Strength: Very Strong"); 
    } 
    
    return 0; 
}