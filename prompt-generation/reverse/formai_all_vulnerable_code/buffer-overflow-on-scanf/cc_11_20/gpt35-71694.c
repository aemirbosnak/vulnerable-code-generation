//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char password[100];
    int length, digits = 0, lowercase = 0, uppercase = 0, special = 0, i;

    printf("Enter your password: ");
    scanf("%s", password);

    length = strlen(password);

    for(i = 0; i < length; i++){
        if(isdigit(password[i])){
            digits++;
        }
        else if(islower(password[i])){
            lowercase++;
        }
        else if(isupper(password[i])){
            uppercase++;
        }
        else{
            special++;
        }
    }

    printf("\nPassword Strength Meter\n");

    if(length < 6){
        printf("[ ] Length: %d/10\n", length);
    }
    else if(length < 10){
        printf("[+] Length: %d/10\n", length);
    }
    else{
        printf("[+] Length: 10/10\n");
    }

    if(digits < 2){
        printf("[ ] Digits: %d/2\n", digits);
    }
    else{
        printf("[+] Digits: 2/2\n");
    }

    if(lowercase < 2){
        printf("[ ] Lowercase: %d/2\n", lowercase);
    }
    else{
        printf("[+] Lowercase: 2/2\n");
    }

    if(uppercase < 2){
        printf("[ ] Uppercase: %d/2\n", uppercase);
    }
    else{
        printf("[+] Uppercase: 2/2\n");
    }

    if(special < 1){
        printf("[ ] Special: %d/1\n", special);
    }
    else{
        printf("[+] Special: 1/1\n");
    }

    return 0;
}