//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main() {
    char password[100];
    int length;
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);

    //Check for length
    if(length < 8) {
        printf("Your password is too short. Please make it at least 8 characters long.\n");
        return 0;
    }

    //Check for special characters
    int special_count = 0;
    int has_digit = 0;
    int has_upper = 0;
    int has_lower = 0;
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            has_digit = 1;
        }
        else if(isupper(password[i])) {
            has_upper = 1;
        }
        else if(islower(password[i])) {
            has_lower = 1;
        }
        else {
            special_count++;
        }
    }
    if(!has_digit) {
        printf("Your password should contain at least one digit.\n");
        return 0;
    }
    if(!has_upper) {
        printf("Your password should contain at least one uppercase letter.\n");
        return 0;
    }
    if(!has_lower) {
        printf("Your password should contain at least one lowercase letter.\n");
        return 0;
    }

    //Check for common words
    char common_words[][20] = {"password", "123456", "qwerty", "letmein", "admin", "welcome", "monkey", "dragon", "sunshine", "iloveyou"};
    int common_words_count = 0;
    for(int i=0; i<10; i++) {
        if(strcmp(password, common_words[i]) == 0) {
            printf("Your password is too common. Please choose a more unique password.\n");
            return 0;
        }
    }

    //Calculate strength
    int strength = 0;
    if(length >= 8 && length <= 12) {
        strength = 1;
    }
    else if(length >= 13 && length <= 16) {
        strength = 2;
    }
    else if(length > 16) {
        strength = 3;
    }
    if(has_digit) {
        strength++;
    }
    if(has_upper) {
        strength++;
    }
    if(has_lower) {
        strength++;
    }
    if(special_count > 0) {
        strength++;
    }

    //Print strength
    if(strength <= 2) {
        printf("Your password is weak. Please choose a stronger password.\n");
    }
    else if(strength == 3) {
        printf("Your password is good. Keep it up!\n");
    }
    else {
        printf("Your password is strong. Nice work!\n");
    }

    return 0;
}