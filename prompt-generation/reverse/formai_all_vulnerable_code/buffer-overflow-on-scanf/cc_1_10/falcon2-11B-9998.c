//Falcon2-11B DATASET v1.0 Category: Password Strength Checker ; Style: shocked
#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int strength = 0;
    printf("Enter a password: ");
    scanf("%s", password);
    int len = strlen(password);
    
    // Check for length
    if (len < 8) {
        printf("Password length is too short.\n");
        return 0;
    }
    
    // Check for uppercase
    if (strspn(password, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == len) {
        printf("Password contains all uppercase letters.\n");
        strength += 1;
    }
    
    // Check for lowercase
    if (strspn(password, "abcdefghijklmnopqrstuvwxyz") == len) {
        printf("Password contains all lowercase letters.\n");
        strength += 1;
    }
    
    // Check for digits
    if (strspn(password, "0123456789") == len) {
        printf("Password contains all digits.\n");
        strength += 1;
    }
    
    // Check for special characters
    if (strspn(password, "!@#$%^&*()_+-=[]{}|;:,.<>?/") == len) {
        printf("Password contains all special characters.\n");
        strength += 1;
    }
    
    // Calculate strength
    strength += (len - strlen(password) - 3) / 2;
    
    if (strength >= 7) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }
    
    return 0;
}