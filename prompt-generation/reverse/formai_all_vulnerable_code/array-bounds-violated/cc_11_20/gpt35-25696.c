//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: shocked
#include<stdio.h>
#include<string.h>

int main(){
    char date[15];
    printf("Enter the date in natural language format (Eg: December 31, 2022): ");
    fgets(date, 15, stdin);

    int index = 0;
    int month, day, year;
    char temp[10];

    //extracting month
    while(date[index] != ' '){
        temp[index] = date[index];
        index++;
    }
    temp[index] = '\0'; //inserting null character
    index++;
    if(strcmp(temp, "January") == 0){
        month = 1;
    } else if(strcmp(temp, "February") == 0){
        month = 2;
    } else if(strcmp(temp, "March") == 0){
        month = 3;
    } else if(strcmp(temp, "April") == 0){
        month = 4;
    } else if(strcmp(temp, "May") == 0){
        month = 5;
    } else if(strcmp(temp, "June") == 0){
        month = 6;
    } else if(strcmp(temp, "July") == 0){
        month = 7;
    } else if(strcmp(temp, "August") == 0){
        month = 8;
    } else if(strcmp(temp, "September") == 0){
        month = 9;
    } else if(strcmp(temp, "October") == 0){
        month = 10;
    } else if(strcmp(temp, "November") == 0){
        month = 11;
    } else if(strcmp(temp, "December") == 0){
        month = 12;
    } else {
        printf("Invalid input. Please try again with a valid natural language date format.\n");
        return 0;
    }

    //extracting day
    int i = 0;
    while(date[index] != ','){
        temp[i] = date[index];
        index++;
        i++;
    }
    temp[i] = '\0'; //inserting null character
    index += 2; //skipping comma and space
    day = atoi(temp);

    //extracting year
    i = 0;
    while(date[index] != '\n'){
        temp[i] = date[index];
        index++;
        i++;
    }
    temp[i] = '\0'; //inserting null character
    year = atoi(temp);

    printf("The date in integer format is: %d/%d/%d", month, day, year);
    return 0;
}