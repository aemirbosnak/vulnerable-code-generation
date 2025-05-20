//FormAI DATASET v1.0 Category: Data validation ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STR_LEN 100

int validate_int_range(int value, int min, int max){
    if(value<min || value>max){
        return 0;
    }
    return 1;
}

int validate_float_range(float value, float min, float max){
    if(value<min || value>max){
        return 0;
    }
    return 1;
}

int validate_string_length(char *str, int max_len){
    if(strlen(str)>max_len){
        return 0;
    }
    return 1;
}

int validate_string_alpha(char *str){
    int i;
    for(i=0; i<strlen(str); i++){
        if(!isalpha(str[i]) && !isspace(str[i])){
            return 0;
        }
    }
    return 1;
}

int validate_string_num(char *str){
    int i;
    for(i=0; i<strlen(str); i++){
        if(!isdigit(str[i]) && !isspace(str[i])){
            return 0;
        }
    }
    return 1;
}

int main(){
    int age;
    float height, weight;
    char name[MAX_STR_LEN], address[MAX_STR_LEN];
    
    // Age validation
    do{
        printf("Enter your age (must be within 18 and 60): ");
        scanf("%d", &age);
    }while(!validate_int_range(age, 18, 60));
    
    // Height validation
    do{
        printf("Enter your height in meters (must be within 1 and 2): ");
        scanf("%f", &height);
    }while(!validate_float_range(height, 1.0, 2.0));
    
    // Weight validation
    do{
        printf("Enter your weight in kilograms (must be within 30 and 150): ");
        scanf("%f", &weight);
    }while(!validate_float_range(weight, 30.0, 150.0));
    
    // Name validation
    do{
        printf("Enter your name (must not exceed %d characters and contain only alphabets): ", MAX_STR_LEN);
        scanf("%s", name);
    }while(!validate_string_length(name, MAX_STR_LEN) || !validate_string_alpha(name));
    
    // Address validation
    do{
        printf("Enter your address (must not exceed %d characters and contain only numbers and spaces): ", MAX_STR_LEN);
        scanf("%s", address);
    }while(!validate_string_length(address, MAX_STR_LEN) || !validate_string_num(address));
    
    printf("\nYour details are:\nAge: %d\nHeight: %.2f meters\nWeight: %.2f kilograms\nName: %s\nAddress: %s\n", age, height, weight, name, address);
    
    return 0;
}