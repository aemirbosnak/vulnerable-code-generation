//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert date string to natural language
char* natLangDateConverter(char* dateStr){
    char* result = malloc(sizeof(char)*50);
    char month[20] = "", day[5] = "", year[10] = "";

    // extract month, day and year from date string
    sscanf(dateStr, "%s %s %s", day, month, year);

    // convert month to natural language
    if(strcmp(month, "01") == 0){
        strcpy(month, "January");
    } else if(strcmp(month, "02") == 0){
        strcpy(month, "February");
    } else if(strcmp(month, "03") == 0){
        strcpy(month, "March");
    } else if(strcmp(month, "04") == 0){
        strcpy(month, "April");
    } else if(strcmp(month, "05") == 0){
        strcpy(month, "May");
    } else if(strcmp(month, "06") == 0){
        strcpy(month, "June");
    } else if(strcmp(month, "07") == 0){
        strcpy(month, "July");
    } else if(strcmp(month, "08") == 0){
        strcpy(month, "August");
    } else if(strcmp(month, "09") == 0){
        strcpy(month, "September");
    } else if(strcmp(month, "10") == 0){
        strcpy(month, "October");
    } else if(strcmp(month, "11") == 0){
        strcpy(month, "November");
    } else if(strcmp(month, "12") == 0){
        strcpy(month, "December");
    }

    // convert day to natural language
    if(day[0] == '0'){
        sprintf(day, "%c", day[1]);
    }

    // concatenate result string
    sprintf(result, "%s %s, %s", month, day, year);

    return result;
}

int main(){
    char dateStr[20], *result;

    printf("Enter date in the format 'DD MM YYYY': ");
    fgets(dateStr, 20, stdin);
    dateStr[strcspn(dateStr, "\n")] = 0; // remove newline character from input

    result = natLangDateConverter(dateStr);

    printf("Natural language date: %s\n", result);

    free(result);

    return 0;
}