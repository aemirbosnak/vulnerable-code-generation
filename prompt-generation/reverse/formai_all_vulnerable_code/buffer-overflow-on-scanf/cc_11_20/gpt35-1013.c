//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char password[100];
    int length, i, digits = 0, upper = 0, lower = 0, special = 0, score = 0;
    printf("Enter Password: ");
    scanf("%s", password);
    length = strlen(password);
    
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            digits++;
        } else if (isupper(password[i])) {
            upper++;
        } else if (islower(password[i])) {
            lower++;
        } else {
            special++;
        }
    }
    
    if (length >= 8 && length <= 16) {
        score += 25;
    } else if (length > 16) {
        score += 50;
    }
    
    if (digits > 0) {
        score += 10;
    }
    
    if (upper > 0) {
        score += 10;
    }
    
    if (lower > 0) {
        score += 10;
    }
    
    if (special > 0) {
        score += 10;
    }
    
    if (score == 100) {
        printf("\nExcellent Password!\n");
    } else if (score >= 70) {
        printf("\nGood Password!\n");
    } else if (score >= 50) {
        printf("\nAverage Password!\n");
    } else {
        printf("\nWeak Password!\n");
    }
    
    return 0;
}