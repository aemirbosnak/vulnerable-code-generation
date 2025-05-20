//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: thoughtful
#include <stdio.h>
#include <string.h>

// Function to check the password's strength
int check_password_strength(char password[]) {
    
    int len = strlen(password);    
    int score = 0;
    int uppercase = 0;
    int lowercase = 0;
    int numbers = 0;
    int symbols = 0;
    
    // Calculating score for each password component
    for (int i = 0; i < len; i++) {
        
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score++;
            uppercase++;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            score++;
            lowercase++;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            score++;
            numbers++;
        }
        else {
            symbols++;
        }
    }
    
    // Checking strength based on score and password components
    if (len > 15 && score > 15 && uppercase > 1 && lowercase > 1 && numbers > 1 && symbols > 1) {
        return 4; // Strong Password
    }
    else if (len > 10 && score > 10 && uppercase > 0 && lowercase > 0 && numbers > 0 && symbols > 0) {
        return 3; // Moderate Password
    }
    else if (len > 6 && score > 6 && ((uppercase > 0 && lowercase > 0 && numbers > 0) || (symbols > 0))) {
        return 2; // Weak Password
    }
    else {
        return 1; // Very Weak Password
    }
}

int main() {
    
    char password[30];
    
    printf("Enter password: ");
    scanf("%s", password);
    
    int strength = check_password_strength(password);
    
    if (strength == 4) {
        printf("Strong Password\n");
    }
    else if (strength == 3) {
        printf("Moderate Password\n");
    }
    else if (strength == 2) {
        printf("Weak Password\n");
    }
    else {
        printf("Very Weak Password\n");
    }
    
    return 0;
}