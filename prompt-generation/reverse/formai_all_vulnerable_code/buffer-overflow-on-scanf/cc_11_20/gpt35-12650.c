//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 30

int main(){

    char password[MAX_LENGTH+1];
    int length;
    int i, digit_count, upper_count, lower_count, special_count;
    char digits[] = "0123456789";
    char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
    char special[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

    srand(time(0));

    printf("Enter desired password length (max %d): ", MAX_LENGTH);
    scanf("%d", &length);

    while(length > MAX_LENGTH || length < 1){
        printf("Invalid length. Please enter a value between 1 and %d: ", MAX_LENGTH);
        scanf("%d", &length);
    }

    // initialize counts
    digit_count = 0;
    upper_count = 0;
    lower_count = 0;
    special_count = 0;

    // fill password with random characters
    for(i = 0; i < length; i++){
        int r = rand() % 4;

        if(r == 0){ // add digit
            password[i] = digits[rand() % strlen(digits)];
            digit_count++;
        }
        else if(r == 1){ // add uppercase letter
            password[i] = uppercase[rand() % strlen(uppercase)];
            upper_count++;
        }
        else if(r == 2){ // add lowercase letter
            password[i] = lowercase[rand() % strlen(lowercase)];
            lower_count++;
        }
        else{ // add special character
            password[i] = special[rand() % strlen(special)];
            special_count++;
        }
    }

    // make sure password meets all requirements
    while(digit_count < 2 || upper_count < 2 || lower_count < 2 || special_count < 2){
        int r = rand() % 4;

        if(r == 0 && digit_count < 2){ // add digit
            password[rand() % length] = digits[rand() % strlen(digits)];
            digit_count++;
        }
        else if(r == 1 && upper_count < 2){ // add uppercase letter
            password[rand() % length] = uppercase[rand() % strlen(uppercase)];
            upper_count++;
        }
        else if(r == 2 && lower_count < 2){ // add lowercase letter
            password[rand() % length] = lowercase[rand() % strlen(lowercase)];
            lower_count++;
        }
        else if(special_count < 2){ // add special character
            password[rand() % length] = special[rand() % strlen(special)];
            special_count++;
        }
    }

    password[length] = '\0';

    printf("Your secure password is: %s\n", password);

    return 0;
}