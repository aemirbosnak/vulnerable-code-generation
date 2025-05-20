//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

// Function to validate integer input
bool validateInt(char input[]){
    int length = strlen(input);
    for(int i=0; i<length; i++){
        if(!isdigit(input[i])){
            return false;
        }
    }
    return true;
}

// Function to validate float input
bool validateFloat(char input[]){
    int dots = 0;
    int length = strlen(input);
    for(int i=0; i<length; i++){
        if(!isdigit(input[i])){
            if(input[i] == '.' && dots == 0){
                dots++;
            }
            else{
                return false;
            }
        }
    }
    return true;
}

int main(){
    char input[20];
    int intValue;
    float floatValue;
    
    // Validate integer input
    printf("Enter an integer value: ");
    scanf("%s", input);
    if(validateInt(input)){
        intValue = atoi(input);
        printf("The integer value entered is: %d\n", intValue);
    }
    else{
        printf("Invalid input. Please enter an integer value.\n");
    }
    
    // Validate float input
    printf("Enter a float value: ");
    scanf("%s", input);
    if(validateFloat(input)){
        floatValue = atof(input);
        printf("The float value entered is: %f\n", floatValue);
    }
    else{
        printf("Invalid input. Please enter a float value.\n");
    }

    return 0;
}