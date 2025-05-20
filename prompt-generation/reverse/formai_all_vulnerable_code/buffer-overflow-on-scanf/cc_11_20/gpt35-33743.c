//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[50];
    int length, i;
    int upper = 0, lower = 0, digit = 0, symbol = 0;
    
    printf("Enter your password: ");
    scanf("%s", password);
    length = strlen(password);
    
    if (length < 8) {
        printf("\nPassword must be at least 8 characters long.\n");
    } else {
        for (i = 0; i < length; i++) {
            if (isupper(password[i])) {
                upper++;
            } else if (islower(password[i])) {
                lower++;
            } else if (isdigit(password[i])) {
                digit++;
            } else {
                symbol++;
            }
        }
        
        if (upper && lower && digit && symbol) {
            printf("\nYour password is strong!\n");
        } else {
            printf("\nYour password is weak!\n");
            printf("Here are some tips to make it stronger:\n");
            
            if (upper == 0) {
                printf("- Add at least one uppercase letter.\n");
            }
            
            if (lower == 0) {
                printf("- Add at least one lowercase letter.\n");
            }
            
            if (digit == 0) {
                printf("- Add at least one digit.\n");
            }
            
            if (symbol == 0) {
                printf("- Add at least one symbol.\n");
            }
        }
    }
    
    return 0;
}