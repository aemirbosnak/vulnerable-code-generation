//FormAI DATASET v1.0 Category: Data validation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool validateName(char name[]) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return false;
        }
    }
    return true;
}

bool validateAge(int age) {
    if (age < 0 || age > 120) {
        return false;
    }
    return true;
}

bool validateEmail(char email[]) {
    int atCount = 0;
    int dotCount = 0;
    for (int i = 0; i < strlen(email); i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        }
    }
    if (atCount != 1 || dotCount <= 0) {
        return false;
    }
    return true;
}

int main() {
    char name[50];
    int age;
    char email[50];
    
    // Get user input
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    printf("Please enter your email: ");
    scanf("%s", email);
    
    // Validate input
    bool isValidName = validateName(name);
    bool isValidAge = validateAge(age);
    bool isValidEmail = validateEmail(email);
    
    // Output validation results
    if (isValidName && isValidAge && isValidEmail) {
        printf("Congratulations! Your information has been validated.\n");
    } else {
        printf("Sorry, your input is invalid. Please double check your name, age, and email.\n");
    }
    
    return 0;
}