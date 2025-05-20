//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: Cyberpunk
#include<stdio.h>
#include<string.h>

int main(){
    char password[50];
    int len, i, digit, upper, lower, special;
    digit = upper = lower = special = 0;

    printf("Enter password: ");
    scanf("%s", password);

    len = strlen(password);

    if(len < 8){
        printf("\nPassword must be at least 8 characters long.\n");
    }
    else{
        for(i=0;i<len;i++){
            if(password[i] >= '0' && password[i] <= '9'){
                digit++;
            }
            else if(password[i] >= 'A' && password[i] <= 'Z'){
                upper++;
            }
            else if(password[i] >= 'a' && password[i] <= 'z'){
                lower++;
            }
            else{
                special++;
            }
        }

        if(digit>=1 && upper>=1 && lower>=1 && special>=1){
            printf("\nPassword strength: VERY STRONG!\n");
            printf("This is not your mother's password!");
        }
        else if(digit>=1 && upper>=1 && lower>=1){
            printf("\nPassword strength: STRONG\n");
            printf("Nice, you got some numbers, letters, and caps in there. But where are the special characters?");
        }
        else if(upper>=1 && lower>=1){
            printf("\nPassword strength: MODERATE\n");
            printf("You're trying, but you need to spice it up with some numbers and special characters.");
        }
        else{
            printf("\nPassword strength: WEAK\n");
            printf("Are you even trying? Your password needs at least one uppercase letter, one lowercase letter, and one number.");
        }
    }

    return 0;
}