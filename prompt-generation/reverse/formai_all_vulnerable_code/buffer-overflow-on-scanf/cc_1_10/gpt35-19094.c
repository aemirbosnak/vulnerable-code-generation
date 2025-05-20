//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

//function to generate random uppercase letter
char rand_uppercase(){
    return rand() % 26 + 'A'; //ASCII value of 'A' is 65
}

//function to generate random lowercase letter
char rand_lowercase(){
    return rand() % 26 + 'a'; //ASCII value of 'a' is 97
}

//function to generate random digit
char rand_digit(){
    return rand() % 10 + '0'; //ASCII value of '0' is 48
}

//function to generate random special character
char rand_special(){
    char special[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    return special[rand() % 12];
}

//main function
int main(){
    int length, uppercase, lowercase, digit, special;
    char password[50];
    
    //seed the random number generator with current time
    srand((unsigned int) time(NULL));
    
    //prompt user for password specifications
    printf("Enter password length (at least 8 characters): ");
    scanf("%d", &length);
    printf("Include uppercase letters? (0 for No, 1 for Yes): ");
    scanf("%d", &uppercase);
    printf("Include lowercase letters? (0 for No, 1 for Yes): ");
    scanf("%d", &lowercase);
    printf("Include digits? (0 for No, 1 for Yes): ");
    scanf("%d", &digit);
    printf("Include special characters? (0 for No, 1 for Yes): ");
    scanf("%d", &special);
    
    //validate input and generate password
    if(length < 8){
        printf("Password length should be at least 8 characters.");
    }
    else if(uppercase == 0 && lowercase == 0 && digit == 0 && special == 0){
        printf("At least one type of character should be included.");
    }
    else{
        int i;
        for(i = 0; i < length; i++){
            int choice = rand() % 4;
            if(uppercase == 1 && choice == 0){
                password[i] = rand_uppercase();
            }
            else if(lowercase == 1 && choice == 1){
                password[i] = rand_lowercase();
            }
            else if(digit == 1 && choice == 2){
                password[i] = rand_digit();
            }
            else if(special == 1 && choice == 3){
                password[i] = rand_special();
            }
            else{
                i--;
            }
        }
        password[length] = '\0';
        printf("Generated password: %s\n", password);
    }
    return 0;
}