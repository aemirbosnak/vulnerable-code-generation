//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: relaxed
// C Natural Language Date Converter Example Program
// By [Your Name]

#include<stdio.h>
#include<string.h>

int main(){
    int month;
    int day;
    char monthName[10];
    char suffix[5];
    int year;

    printf("Please enter the date in natural language: ");
    scanf("%d %s %s %d", &day, monthName, suffix, &year);

    // Convert month name to month number
    if(strcmp(monthName, "January")==0){
        month = 1;
    }else if(strcmp(monthName, "February")==0){
        month = 2;
    }else if(strcmp(monthName, "March")==0){
        month = 3;
    }else if(strcmp(monthName, "April")==0){
        month = 4;
    }else if(strcmp(monthName, "May")==0){
        month = 5;
    }else if(strcmp(monthName, "June")==0){
        month = 6;
    }else if(strcmp(monthName, "July")==0){
        month = 7;
    }else if(strcmp(monthName, "August")==0){
        month = 8;
    }else if(strcmp(monthName, "September")==0){
        month = 9;
    }else if(strcmp(monthName, "October")==0){
        month = 10;
    }else if(strcmp(monthName, "November")==0){
        month = 11;
    }else if(strcmp(monthName, "December")==0){
        month = 12;
    }else{
        printf("\nInvalid month name!\n");
        return 0;
    }

    // Remove the suffix and convert day to integer
    day = atoi(strtok(suffix, ","));

    // Print the converted date in DD-MM-YYYY format
    printf("\n%d-%02d-%d\n", day, month, year);

    return 0;
}