//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert month name to number
int getMonthNum(char* month) {
    if (strcmp(month, "January") == 0)
        return 1;
    else if (strcmp(month, "February") == 0)
        return 2;
    else if (strcmp(month, "March") == 0)
        return 3;
    else if(strcmp(month, "April") == 0)
        return 4;
    else if(strcmp(month, "May") == 0)
        return 5;
    else if(strcmp(month, "June") == 0)
        return 6;
    else if(strcmp(month, "July") == 0)
        return 7;
    else if(strcmp(month, "August") == 0)
        return 8;
    else if(strcmp(month, "September") == 0)
        return 9;
    else if(strcmp(month, "October") == 0)
        return 10;
    else if(strcmp(month, "November") == 0)
        return 11;
    else if(strcmp(month, "December") == 0)
        return 12;
}

// function to convert date format e.g. "DD/MM/YYYY" to "Month DD, YYYY"
void convertDateFormat(char* date) {
    char month[10];
    
    // get day, month, year from input date
    int day = atoi(strtok(date, "/"));
    int monNum = atoi(strtok(NULL, "/"));
    int year = atoi(strtok(NULL, "/"));
    
    // convert month number to name
    switch(monNum) {
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "March");
            break;
        case 4:
            strcpy(month, "April");
            break;
        case 5:
            strcpy(month, "May");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
            break;
    }
    
    // print the converted date format
    printf("%s %02d, %04d\n", month, day, year);
}

int main() {
    char date[11];
    printf("Enter date in format \"DD/MM/YYYY\": ");
    scanf("%s", date);
    
    // check date format is valid
    if(strlen(date) != 10 || date[2] != '/' || date[5] != '/') {
        printf("Invalid date format entered!");
        return 0;
    }
    
    // convert date format and print
    convertDateFormat(date);
    
    return 0;
}