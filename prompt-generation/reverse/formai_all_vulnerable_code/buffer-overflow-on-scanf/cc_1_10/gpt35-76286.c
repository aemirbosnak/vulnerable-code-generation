//FormAI DATASET v1.0 Category: Data validation ; Style: thoughtful
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int is_int(char* str){
    //check if the given string is an integer
    for(int i=0;i<strlen(str);i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

int is_float(char* str){
    int dot_count=0;
    //check if the given string is a float
    for(int i=0;i<strlen(str);i++){
        if(str[i]=='.'){
            dot_count++;
            if(dot_count>1){
                return 0;
            }
        }else if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

int is_valid_date(int day, int month, int year){
    //check if the given date is valid or not
    if(year<0){
        return 0;
    }else if(month<1 || month>12){
        return 0;
    }else if(day<1 || day>31){
        return 0;
    }else if(month==2){
        if(year%4 == 0){
            if(day>29){
                return 0;
            }
        }else{
            if(day>28){
                return 0;
            }
        }
    }else if(month==4 || month==6 || month==9 || month==11){
        if(day>30){
            return 0;
        }
    }
    return 1;
}

int main(){
    char option;
    do{
        printf("Enter the type of data to be validated:\n1. Integer\n2. Float\n3. Date\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:{
                printf("Enter an integer: ");
                char input[20];
                scanf("%s",input);
                if(is_int(input)){
                    printf("Valid Integer\n");
                }else{
                    printf("Invalid Integer\n");
                }
                break;
            }
            case 2:{
                printf("Enter a float: ");
                char input[20];
                scanf("%s",input);
                if(is_float(input)){
                    printf("Valid Float\n");
                }else{
                    printf("Invalid Float\n");
                }
                break;
            }
            case 3:{
                int day,month,year;
                printf("Enter the day, month and year (in YYYY format) separated by spaces:");
                scanf("%d %d %d",&day,&month,&year);
                if(is_valid_date(day,month,year)){
                    printf("Valid Date\n");
                }else{
                    printf("Invalid Date\n");
                }
                break;
            }
            default:{
                printf("Invalid option\n");
                break;
            }
        }
        printf("Do you want to validate another data? (y/n)\n");
        scanf(" %c",&option);
    }while(option=='y' || option=='Y');
    return 0;
}