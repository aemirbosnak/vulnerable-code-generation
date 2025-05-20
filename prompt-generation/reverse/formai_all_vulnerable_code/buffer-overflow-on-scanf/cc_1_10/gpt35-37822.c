//FormAI DATASET v1.0 Category: Data validation ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

int validateInteger(char* input);
int validateFloat(char* input);
int validateChar(char input);

int main(){

    char input1[50], input2[50];
    int num1, num2;
    float float1, float2;
    char char1, char2;

    printf("Welcome to the data validation program!\n");

    //Validate first integer
    printf("Please enter the first integer: ");
    scanf("%s", input1);
    num1 = validateInteger(input1);
    while(num1 == -1){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the first integer: ");
        scanf("%s", input1);
        num1 = validateInteger(input1);
    }

    //Validate second integer
    printf("Please enter the second integer: ");
    scanf("%s", input2);
    num2 = validateInteger(input2);
    while(num2 == -1){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the second integer: ");
        scanf("%s", input2);
        num2 = validateInteger(input2);
    }

    //Validate first float
    printf("Please enter the first float: ");
    scanf("%s", input1);
    float1 = validateFloat(input1);
    while(float1 == -1.0){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the first float: ");
        scanf("%s", input1);
        float1 = validateFloat(input1);
    }

    //Validate second float
    printf("Please enter the second float: ");
    scanf("%s", input2);
    float2 = validateFloat(input2);
    while(float2 == -1.0){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the second float: ");
        scanf("%s", input2);
        float2 = validateFloat(input2);
    }

    //Validate first character
    printf("Please enter the first character: ");
    scanf(" %c", &char1);
    while(validateChar(char1) == -1){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the first character: ");
        scanf(" %c", &char1);
    }

    //Validate second character
    printf("Please enter the second character: ");
    scanf(" %c", &char2);
    while(validateChar(char2) == -1){
        printf("Invalid input. Please try again.\n");
        printf("Please enter the second character: ");
        scanf(" %c", &char2);
    }

    printf("Congratulations! All inputs are valid!\n");
    printf("Integer 1: %d\n", num1);
    printf("Integer 2: %d\n", num2);
    printf("Float 1: %.2f\n", float1);
    printf("Float 2: %.2f\n", float2);
    printf("Character 1: %c\n", char1);
    printf("Character 2: %c\n", char2);
    return 0;
}

int validateInteger(char* input){
    for(int i=0; input[i]!='\0'; i++){
        if(input[i]<'0' || input[i]>'9'){
            return -1;
        }
    }
    return atoi(input);
}

int validateFloat(char* input){
    int count = 0;
    for(int i=0; input[i]!='\0'; i++){
        if(input[i] == '.'){
            count++;
        }
        else if(input[i]<'0' || input[i]>'9'){
            return -1.0;
        }
    }
    if(count == 1){
        return atof(input);
    }
    else{
        return -1.0;
    }
}

int validateChar(char input){
    if((input>='a' && input<='z') || (input>='A' && input<='Z')){
        return 1;
    }
    else{
        return -1;
    }
}