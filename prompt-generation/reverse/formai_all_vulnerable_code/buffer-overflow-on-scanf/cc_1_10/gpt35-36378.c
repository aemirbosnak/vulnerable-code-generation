//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: scalable
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int length, num_count = 0, upper_count = 0, lower_count = 0, special_count = 0, score = 0;

    // Prompts the user to enter a password
    printf("Enter a password: ");
    scanf("%s", password);

    // Calculates the length of the password
    length = strlen(password);

    // Checks each character for type and adds to the count
    for(int i=0; i<length; i++) {
        if(isdigit(password[i])) {
            num_count++;
        } else if(isupper(password[i])) {
            upper_count++;
        } else if(islower(password[i])) {
            lower_count++;
        } else {
            special_count++;
        }
    }

    // Calculates password strength score based on counts and length
    if (length >= 8) {
        score += 25;
    }
    score += num_count*4;
    score += upper_count*3;
    score += lower_count*2;
    score += special_count*5;

    // Prints out password strength score and message based on score
    printf("Password strength score: %d\n", score);
    if(score >= 100) {
        printf("Your password is extremely strong!\n");
    } else if (score >= 80) {
        printf("Your password is very strong!\n");
    } else if (score >= 60) {
        printf("Your password is strong.\n");
    } else if (score >= 40) {
        printf("Your password is fair.\n");
    } else {
        printf("Your password is weak.\n");
    }

    return 0;
}