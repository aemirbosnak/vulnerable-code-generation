//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

int main() {
    char password[100];
    int length, i, j, sum = 0;
    float complexity = 0;
    
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);
    
    // Check for minimum length
    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }
    
    // Check for uppercase letters
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            sum++;
        }
    }
    
    // Check for lowercase letters
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            sum++;
        }
    }
    
    // Check for numbers
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            sum++;
        }
    }
    
    // Check for special characters
    for (i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            sum++;
        }
    }
    
    // Calculate complexity
    complexity = (float) sum / length;
    
    // Print results
    printf("Password Strength: ");
    if (complexity >= 0.8) {
        printf("Very Strong\n");
    }
    else if (complexity >= 0.6) {
        printf("Strong\n");
    }
    else if (complexity >= 0.4) {
        printf("Moderate\n");
    }
    else {
        printf("Weak\n");
    }
    
    return 0;
}