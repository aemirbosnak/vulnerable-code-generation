//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: artistic
#include<stdio.h>
#include<string.h>

//Function to calculate password strength 
int passwordStrength(char *password){

    int length=strlen(password);
    int specialChar=0, upperCase=0, lowerCase=0, number=0;

    //Loop through each character of the password
    for(int i=0;i<length;i++){
        if(isdigit(password[i])){
            number++;
        }
        else if(isupper(password[i])){
            upperCase++;
        }
        else if(islower(password[i])){
            lowerCase++;
        }
        else{
            specialChar++;
        }
    }

    //Calculate password strength
    int strength=0;
    if(length>=8){
        strength++;
    }
    if(number>0){
        strength++;
    }
    if(upperCase>0){
        strength++;
    }
    if(lowerCase>0){
        strength++;
    }
    if(specialChar>0){
        strength++;
    }

    return strength;
}

int main(){

    char password[20];
    printf("Enter your password: ");
    scanf("%s",password);

    int strength=passwordStrength(password);

    switch (strength){
        case 1:
            printf("Your password is weak!\n");
            break;
        case 2:
            printf("Your password is moderate!\n");
            break;
        case 3:
            printf("Your password is strong!\n");
            break;
        case 4:
            printf("Your password is very strong!\n");
            break;
        case 5:
            printf("Your password is extremely strong!\n");
            break;
        default:
            printf("Invalid password!\n");
    }

    return 0;
}