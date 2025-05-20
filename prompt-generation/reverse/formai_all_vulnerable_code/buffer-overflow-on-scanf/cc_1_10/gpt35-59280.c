//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

char* month_name(int month_number){
    char* month;
    switch(month_number){
        case 1:
            month = "January";
            break;
        case 2:
            month = "February";
            break;
        case 3:
            month = "March";
            break;
        case 4:
            month = "April";
            break;
        case 5:
            month = "May";
            break;
        case 6:
            month = "June";
            break;
        case 7:
            month = "July";
            break;
        case 8:
            month = "August";
            break;
        case 9:
            month = "September";
            break;
        case 10:
            month = "October";
            break;
        case 11:
            month = "November";
            break;
        case 12:
            month = "December";
            break;
        default:
            month = "Unknown";
            break;
    }
    return month;
}

void convert_date(int date_int){
    int day = date_int % 100;
    int month = (date_int / 100) % 100;
    int year = date_int / 10000;
    printf("The converted date is: %s %d, %d\n", month_name(month), day, year);
}

int main(){
    int date_int;
    printf("Enter the date in the format MMDDYYYY (e.g. 12192020): ");
    if(scanf("%d", &date_int) != 1){
        printf("Invalid input! Please enter numbers only.\n");
        return 1;
    }
    convert_date(date_int);
    return 0;
}