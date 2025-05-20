//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <string.h>

/* function to convert month from word to number */
int monthConverter(char* month){
    char* monthList[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    int i, monthNum;
    for(i=0; i<12; i++){
        if(strcmp(month, monthList[i]) == 0){
            monthNum = i + 1;
            break;
        }
    }
    return monthNum;
}

/* function to convert date from string to integer */
int dateConverter(char* date){
    int i, len = strlen(date), num = 0, digit;
    for(i=0; i<len; i++){
        digit = (int)date[i] - 48;
        if(digit >= 0 && digit <= 9){
            num = num*10 + digit;
        }
    }
    return num;
}

int main(){
    char date[20], month[20], year[20]; /* input strings */
    int dateNum, monthNum, yearNum; /* converted integers */

    printf("Enter date in format: Month Date, Year (e.g. March 12, 2022): ");
    scanf("%s %d, %d", month, &dateNum, &yearNum);

    /* convert month and year to integers */
    monthNum = monthConverter(month);
    yearNum = dateConverter(year);

    /* print output */
    printf("\n%s %d, %d in natural language: ", month, dateNum, yearNum);

    /* switch statement to print month in word */
    switch (monthNum){
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;
        default:
            printf("Invalid month");
    }
    
    printf(" %d, %d", dateNum, yearNum);
    
    return 0;
}