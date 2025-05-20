//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_digits(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(isdigit(password[i])){
            count++;
        }
    }
    return count;
}

int count_uppercase(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(isupper(password[i])){
            count++;
        }
    }
    return count;
}

int count_lowercase(char* password){
    int count = 0;
    for(int i=0; i<strlen(password); i++){
        if(islower(password[i])){
            count++;
        }
    }
    return count;
}

int count_special(char* password){
    int count = 0;
    char special_chars[] = "!@#$%^&*()_+-=[];':\"<>,.?/\\";
    for(int i=0; i<strlen(password); i++){
        for(int j=0; j<strlen(special_chars); j++){
            if(password[i] == special_chars[j]){
                count++;
            }
        }
    }
    return count;
}

int calculate_strength(char* password){
    int strength = 0;
    int digit_count = count_digits(password);
    int uppercase_count = count_uppercase(password);
    int lowercase_count = count_lowercase(password);
    int special_count = count_special(password);

    if(strlen(password) >= 8){
        strength++;
    }
    if(digit_count >= 2){
        strength++;
    }
    if(uppercase_count >= 2){
        strength++;
    }
    if(lowercase_count >= 2){
        strength++;
    }
    if(special_count >= 2){
        strength++;
    }

    return strength;
}

int main(){
    char password[100];
    printf("Enter your password: ");
    scanf("%s", password);

    int strength = calculate_strength(password);

    printf("Your password strength is %d out of 5\n", strength);

    return 0;
}