//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: mind-bending
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* 
This program is a password strength checker that evaluates the complexity of a password based on various factors such as length, use of numbers, uppercase and lowercase letters, special characters, and overall uniqueness. 
*/

int main() {

    char password[50];
    int length, num_count, upper_count, lower_count, special_count, unique_count;
    int score = 0;

    printf("Welcome to Password Strength Checker!\n");
    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password); //calculate length of password
    printf("\nPassword Length: %d\n", length);

    //check for lowercase letters
    for(int i=0; i<length; i++) {
        if(islower(password[i])) {
            lower_count++;
        }
    }

    //check for uppercase letters
    for(int i=0; i<length; i++) {
        if(isupper(password[i])) {
            upper_count++;
        }
    }

    //check for numbers
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            num_count++;
        }
    }

    //check for special characters
    for(int i=0; i<length; i++) {
        if(ispunct(password[i])) {
            special_count++;
        }
    }

    //check for uniqueness
    for(int i=0; i<length; i++) {
        for(int j=0; j<i; j++) {
            if(password[i] == password[j]) {
                unique_count++;
                break;
            }
        }
    }

    //calculate password score
    if(length >= 8) {
        score++;
    }

    if(upper_count > 0 && lower_count > 0) {
        score++;
    }

    if(num_count > 0) {
        score++;
    }

    if(special_count > 0) {
        score++;
    }

    if(unique_count == length) {
        score++;
    }

    //print results
    printf("\nPassword Score: %d/5", score);

    if(score < 3) {
        printf("\nWeak Password. Please try again with a stronger password!\n");
    } else if(score == 3) {
        printf("\nModerate Password. Consider making it stronger!\n");
    } else if(score == 4) {
        printf("\nStrong Password. Great job!\n");
    } else if(score == 5) {
        printf("\nUltra Strong Password. You're a security master!\n");
    }

    return 0;
}