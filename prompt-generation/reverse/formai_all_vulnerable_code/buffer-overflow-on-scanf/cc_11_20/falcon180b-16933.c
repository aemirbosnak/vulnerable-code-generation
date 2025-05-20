//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

int main() {
    char password[100];
    int length, i, sum = 0;
    char ch;
    
    printf("Enter password: ");
    scanf("%s", password);
    length = strlen(password);
    
    printf("\nStrength of password: ");
    
    if (length < 8) {
        printf("Weak\n");
        exit(0);
    }
    
    for (i = 0; i < length; i++) {
        ch = tolower(password[i]);
        if (isalpha(ch)) {
            sum += 1;
        }
        else if (isdigit(ch)) {
            sum += 2;
        }
        else if (ch == '!' || ch == '@' || ch == '#' || ch == '$' || ch == '%' || ch == '^' || ch == '&' || ch == '*') {
            sum += 3;
        }
        else {
            sum += 4;
        }
    }
    
    if (sum < 16) {
        printf("Weak\n");
    }
    else if (sum < 24) {
        printf("Fair\n");
    }
    else if (sum < 32) {
        printf("Good\n");
    }
    else {
        printf("Strong\n");
    }
    
    return 0;
}