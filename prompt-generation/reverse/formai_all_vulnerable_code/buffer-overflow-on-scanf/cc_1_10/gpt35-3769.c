//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int containsSpecialCharacters(char *password);
int containsUpperCase(char *password);
int containsNumbers(char *password);
int passwordLength(char *password);

int main(){
    char password[50];
    printf("Enter a password to check its strength: ");
    scanf("%s",password);
    int passwordLengthResult=passwordLength(password);
    int containsUpperCaseResult=containsUpperCase(password);
    int containsNumbersResult=containsNumbers(password);
    int containsSpecialCharactersResult=containsSpecialCharacters(password);
    printf("Password strength analysis:\n");
    printf("Password Length: ");
    if (passwordLengthResult<=6){
        printf("Weak\n");
    }
    else if (passwordLengthResult>6 && passwordLengthResult<10){
        printf("Moderate\n");
    }
    else{
        printf("Strong\n");
    }
    printf("Contains uppercase characters: ");
    if (containsUpperCaseResult==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    printf("Contains digits: ");
    if (containsNumbersResult==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    printf("Contains special characters: ");
    if (containsSpecialCharactersResult==0){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }
    return 0;
}

int containsSpecialCharacters(char *password){
    int length=strlen(password);
    for (int i=0;i<length;i++){
        if ((password[i]<65 || password[i]>90) && (password[i]<97 || password[i]>122) && (password[i]<48 || password[i]>57)){
            return 1;
        }
    }
    return 0;
}

int containsUpperCase(char *password){
    int length=strlen(password);
    for (int i=0;i<length;i++){
        if (password[i]>=65 && password[i]<=90){
            return 1;
        }
    }
    return 0;
}

int containsNumbers(char *password){
    int length=strlen(password);
    for (int i=0;i<length;i++){
        if (password[i]>=48 && password[i]<=57){
            return 1;
        }
    }
    return 0;
}

int passwordLength(char *password){
    int length=strlen(password);
    return length;
}