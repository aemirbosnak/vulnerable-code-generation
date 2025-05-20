//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert months abbreviation to a number
int monthToNum(char* month){
    if(strcmp(month, "Jan") == 0)
        return 1;
    else if(strcmp(month, "Feb") == 0)
        return 2;
    else if(strcmp(month, "Mar") == 0)
        return 3;
    else if(strcmp(month, "Apr") == 0)
        return 4;
    else if(strcmp(month, "May") == 0)
        return 5;
    else if(strcmp(month, "Jun") == 0)
        return 6;
    else if(strcmp(month, "Jul") == 0)
        return 7;
    else if(strcmp(month, "Aug") == 0)
        return 8;
    else if(strcmp(month, "Sep") == 0)
        return 9;
    else if(strcmp(month, "Oct") == 0)
        return 10;
    else if(strcmp(month, "Nov") == 0)
        return 11;
    else if(strcmp(month, "Dec") == 0)
        return 12;
    else
        return -1;
}

//Function to convert dates from string to integer
int dateToNum(char* date){
    int len = strlen(date);
    int d = 0, m = 0, y = 0;
    int i, j;

    for(i = 0; i < len; i++){
        if(date[i] == ' ')
            break;
        d = d * 10 + (date[i] - '0');
    }
    i++;

    for(j = 0; j < 3; j++){
        if(date[i] == ' ')
            break;
        m = m * 10 + (date[i] - '0');
        i++;
    }
    i++;

    for(j = 0; j < 4; j++){
        y = y * 10 + (date[i] - '0');
        i++;
    }

    return (d * 10000 + m * 100 + y);
}

//Function to convert dates from integer to string
void numToDate(int num, char* date){
    int y = num % 10000;
    num /= 10000;
    int m = num % 100;
    num /= 100;
    int d = num;

    sprintf(date, "%02d/%02d/%04d", d, m, y);
}

//Main function
int main(){
    char inDate[50], outDate[50];
    int numDate;

    //Reading input date from user
    printf("Enter date in format (dd mmm yyyy): ");
    fgets(inDate, 50, stdin);
    int len = strlen(inDate);
    if(len > 0 && inDate[len-1] == '\n')
        inDate[len-1] = '\0';

    //Converting input date to integer format
    numDate = dateToNum(inDate);

    //Converting integer date to string format
    numToDate(numDate, outDate);

    //Printing output date
    printf("Output date is: %s\n", outDate);

    return 0;
}