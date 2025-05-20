//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

//function to generate random uppercase letter
char randomUpper(){
    return rand() % 26 + 'A'; 
}

//function to generate random lowercase letter
char randomLower(){
    return rand() % 26 + 'a'; 
}

//function to generate random number
char randomNumber(){
    return rand() % 10 + '0'; 
}

//function to generate random special character
char randomSpecial(){
    //list of special characters to choose from
    char specialCharacters[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+', '[', ']', '{', '}', ';', ':', ',', '.', '/', '<', '>'};
    int numOfSpecial = sizeof(specialCharacters) / sizeof(specialCharacters[0]);
    return specialCharacters[rand() % numOfSpecial];
}

int main(){
    int passwordLength;
    int numUpper, numLower, numNum, numSpecial;
    char password[50];
    srand(time(0)); //seed time to get different random numbers every time program runs
    
    printf("Welcome to the Password Generator!\n");
    printf("How long would you like your password to be? (Enter a number between 8 and 50): ");
    scanf("%d", &passwordLength);
    
    //check if password length is within range
    while(passwordLength < 8 || passwordLength > 50){
        printf("Invalid length entered. Please enter a number between 8 and 50: ");
        scanf("%d", &passwordLength);
    }
    
    printf("How many uppercase letters do you want in your password? (Enter a number between 0 and %d): ", passwordLength);
    scanf("%d", &numUpper);
    
    printf("How many lowercase letters do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper);
    scanf("%d", &numLower);
    
    printf("How many numbers do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper-numLower);
    scanf("%d", &numNum);
    
    printf("How many special characters do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper-numLower-numNum);
    scanf("%d", &numSpecial);
    
    //check if total number of characters matches password length
    while(numUpper+numLower+numNum+numSpecial != passwordLength){
        printf("Total number of characters does not match password length.\n");
        printf("Please re-enter the number of characters for each type.\n");
        
        printf("How many uppercase letters do you want in your password? (Enter a number between 0 and %d): ", passwordLength);
        scanf("%d", &numUpper);
        
        printf("How many lowercase letters do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper);
        scanf("%d", &numLower);
        
        printf("How many numbers do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper-numLower);
        scanf("%d", &numNum);
        
        printf("How many special characters do you want in your password? (Enter a number between 0 and %d): ", passwordLength-numUpper-numLower-numNum);
        scanf("%d", &numSpecial);
    }
    
    //generate random characters
    for(int i=0; i<numUpper; i++){
        password[i] = randomUpper();
    }
    
    for(int i=numUpper; i<numUpper+numLower; i++){
        password[i] = randomLower();
    }
    
    for(int i=numUpper+numLower; i<numUpper+numLower+numNum; i++){
        password[i] = randomNumber();
    }
    
    for(int i=numUpper+numLower+numNum; i<numUpper+numLower+numNum+numSpecial; i++){
        password[i] = randomSpecial();
    }
    
    //shuffle the characters in the password
    int n = strlen(password);
    for(int i=0; i<n-1; i++){
        int j = rand() % (n-i-1) + i+1;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    
    //output password
    printf("\nYour random generated password is: ");
    for(int i=0; i<n; i++){
        printf("%c", password[i]);
    }
    
    printf("\n");
    
    return 0;
}