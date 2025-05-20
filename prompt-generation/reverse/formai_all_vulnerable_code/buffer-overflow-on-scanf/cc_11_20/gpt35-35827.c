//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void print_strength(int score) {
    if(score < 30) {
        printf("Password strength: Weak\n");
    } else if(score < 60) {
        printf("Password strength: Medium\n");
    } else {
        printf("Password strength: Strong\n");
    }
}
 
int main() {
    char password[100];
    int score = 0, length = 0;
    printf("Enter password:\n");
    scanf("%s", password);
    length = strlen(password);
    
    if(length < 8) {
        printf("Password must be at least 8 characters long.\n");
        exit(0);
    }
    
    // check for lowercase characters
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'a' && password[i] <= 'z') {
            score += 10;
            break;
        }
    }
    
    // check for uppercase characters
    for(int i = 0; i < length; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            score += 10;
            break;
        }
    }
    
    // check for numbers
    for(int i = 0; i < length; i++) {
        if(password[i] >= '0' && password[i] <= '9') {
            score += 10;
            break;
        }
    }
    
    // check for special characters
    for(int i = 0; i < length; i++) {
        if((password[i] >= '!' && password[i] <= '/') ||
           (password[i] >= ':' && password[i] <= '@') ||
           (password[i] >= '[' && password[i] <= '`') ||
           (password[i] >= '{' && password[i] <= '~')) {
            score += 10;
            break;
        }
    }
    
    // check for repeated characters
    for(int i = 0; i < length; i++) {
        int count = 0;
        for(int j = 0; j < length; j++) {
            if(i != j && password[i] == password[j]) {
                count++;
            }
        }
        if(count > 0) {
            score -= 5 * count;
        }
    }
    
    // check for consecutive characters
    for(int i = 0; i < length - 1; i++) {
        if((password[i] + 1 == password[i+1]) || (password[i] - 1 == password[i+1])) {
            score -= 5;
        }
    }
    
    // print password strength
    print_strength(score);
 
    return 0;
}