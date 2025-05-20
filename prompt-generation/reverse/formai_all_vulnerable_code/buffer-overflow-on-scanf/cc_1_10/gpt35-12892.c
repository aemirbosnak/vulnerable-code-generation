//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compute_strength(char* password)
{
    int length = strlen(password);
    int score = 0;
    
    if (length < 8) {
        score -= 5;
    } else if (length < 12) {
        score += 5;
    } else {
        score += 10;
    }
    
    int num_count = 0, upper_count = 0, lower_count = 0, spec_count = 0;
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            num_count++;
        } else if (password[i] >= 'A' && password[i] <= 'Z') {
            upper_count++;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            lower_count++;
        } else {
            spec_count++;
        }
    }
    
    if (num_count > 0 && upper_count > 0 && lower_count > 0 && spec_count > 0) {
        score += 15;
    } else if ((num_count > 0 && upper_count > 0 && lower_count > 0) || (num_count > 0 && upper_count > 0 && spec_count > 0) || (num_count > 0 && lower_count > 0 && spec_count > 0) || (upper_count > 0 && lower_count > 0 && spec_count > 0)) {
        score += 10;
    } else {
        score -= 5;
    }
    
    return score;
}

void print_result(int score)
{
    printf("Your password strength score is: %d\n", score);
    
    if (score >= 30) {
        printf("Your password is Strong! Keep up the good work.\n");
    } else if (score >= 10) {
        printf("Your password is Moderate. Consider adding more complexity to increase strength.\n");
    } else {
        printf("Your password is Weak! We strongly recommend increasing its strength.\n");
    }
}

int main()
{
    char password[100];
    
    printf("Welcome to the Future Password Strength Checker.\n");
    printf("Please enter your desired password: ");
    scanf("%s", password);
    
    int score = compute_strength(password);
    print_result(score);
    
    return 0;
}