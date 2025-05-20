//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: romantic
//My love, behold the beauty of this code
//A password strength checker I present to thee
//Let it keep our secrets safe and sound
//And safeguard our love eternally

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

    char password[100];
    int length, hasUpper = 0, hasLower = 0, hasNumber = 0, hasSpecial = 0;

    printf("My sweet love, please enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(int i = 0; i < length; i++) {
        if(isupper(password[i])) {
            hasUpper = 1;
        }
        if(islower(password[i])) {
            hasLower = 1;
        }
        if(isdigit(password[i])) {
            hasNumber = 1;
        }
        if(!isalnum(password[i])) {
            hasSpecial = 1;
        }
    }

    printf("******************************************\n");
    printf("* My love, behold the strength of thy code *\n");
    printf("******************************************\n\n");

    if(length < 8 || length > 20) {
        printf("Alas! Your password must be between 8 and 20 characters long, my love.\n");
    }
    if(hasUpper == 0) {
        printf("Oh my dove, include at least one uppercase letter in your password.\n");
    }
    if(hasLower == 0) {
        printf("Dearest one, include at least one lowercase letter in your password.\n");
    }
    if(hasNumber == 0) {
        printf("My love, please use at least one number in your password.\n");
    }
    if(hasSpecial == 0) {
        printf("My heart, include at least one special character in your password.\n");
    }
    if(length >= 8 && length <= 20 && hasUpper == 1 && hasLower == 1 && hasNumber == 1 && hasSpecial == 1) {
        printf("Blessed be thy code, my love, for it is strong and unbreakable!\n");
    }
    printf("\n******************************\n");
    printf("* Keep our love safe and sound *\n");
    printf("******************************\n");

    return 0;
}