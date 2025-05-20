//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int passwordLength; //length of generated password
    char password[100]; //array to store generated password
    srand(time(NULL)); //seed for random generator
    
    printf("Enter length of password: ");
    scanf("%d",&passwordLength);
    
    if(passwordLength < 6) { //password should be at least 6 characters long
        printf("Password length should be at least 6 characters.");
        exit(0);
    }
    
    printf("\nGenerated password: ");
    for(int i=0; i<passwordLength; i++) {
        int randomNum = rand() % 94 + 33; //generates a random number between 33 and 126 (ASCII table values)
        password[i] = randomNum;
        printf("%c", password[i]); //prints generated character
    }
    
    printf("\n\nPassword Strength:\n");
    printf("The password contains %d characters.\n", passwordLength);
    
    int uppercase = 0, lowercase = 0, digits = 0, special = 0; //variables to count number of uppercase letters, lowercase letters, digits and special characters
    
    for(int i=0; i<passwordLength; i++) {
        if(password[i] >= 'A' && password[i] <= 'Z') {
            uppercase++;
        }
        else if(password[i] >= 'a' && password[i] <= 'z') {
            lowercase++;
        }
        else if(password[i] >= '0' && password[i] <= '9') {
            digits++;
        }
        else if((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96) || (password[i] >= 123 && password[i] <= 126)) {
            special++;    
        }
    }
    
    printf("The password contains %d uppercase letters.\n", uppercase);
    printf("The password contains %d lowercase letters.\n", lowercase);
    printf("The password contains %d digits.\n", digits);
    printf("The password contains %d special characters.\n", special);
    
    int entropy = passwordLength * (log2(94)); //calculates password entropy using Shannon's formula
    printf("The password entropy is %d bits.\n", entropy);
    
    return 0;
}