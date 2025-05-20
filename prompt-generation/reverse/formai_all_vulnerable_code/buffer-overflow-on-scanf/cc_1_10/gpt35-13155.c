//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//function to check if year is a leap year
int isLeapYear(int year) {
    if (year % 400 == 0)
        return 1;
    else if (year % 100 == 0)
        return 0;
    else if (year % 4 == 0)
        return 1;
    else
        return 0;
}

//function to convert date from YYYY-MM-DD format to C Natural Language 
void convertToCNL(char date[]) {
    //splitting year, month and day
    char year[5], month[3], day[3];
    strncpy(year, date, 4);
    year[4] = '\0';
    strncpy(month, date+5, 2);
    month[2] = '\0';
    strncpy(day, date+8, 2);
    day[2] = '\0';

    //converting to integers
    int y = atoi(year);
    int m = atoi(month);
    int d = atoi(day);

    //CNL strings
    char cnlYear[20], cnlMonth[20], cnlDay[20];

    //finding CNL year
    int diff = 2022 - y;
    switch(diff) {
        case 0:
            strcpy(cnlYear, "this year");
            break;
        case 1:
            strcpy(cnlYear, "last year");
            break;
        case -1:
            strcpy(cnlYear, "next year");
            break;
        default:
            if (diff > 0) {
                sprintf(cnlYear, "%d years ago", diff);
            } else {
                sprintf(cnlYear, "in %d years", -diff);
            }
            break;
    }

    //finding CNL month
    switch(m) {
        case 1:
            strcpy(cnlMonth, "January");
            break;
        case 2:
            strcpy(cnlMonth, "February");
            break;
        case 3:
            strcpy(cnlMonth, "March");
            break;
        case 4:
            strcpy(cnlMonth, "April");
            break;
        case 5:
            strcpy(cnlMonth, "May");
            break;
        case 6:
            strcpy(cnlMonth, "June");
            break;
        case 7:
            strcpy(cnlMonth, "July");
            break;
        case 8:
            strcpy(cnlMonth, "August");
            break;
        case 9:
            strcpy(cnlMonth, "September");
            break;
        case 10:
            strcpy(cnlMonth, "October");
            break;
        case 11:
            strcpy(cnlMonth, "November");
            break;
        case 12:
            strcpy(cnlMonth, "December");
            break;
    }

    //finding CNL day
    switch(d) {
        case 1:
        case 21:
        case 31:
            strcpy(cnlDay, "1st");
            break;
        case 2:
        case 22:
            strcpy(cnlDay, "2nd");
            break;
        case 3:
        case 23:
            strcpy(cnlDay, "3rd");
            break;
        default:
            sprintf(cnlDay, "%dth", d);
            break;
    }

    //printing CNL date
    printf("The date %s corresponds to %s %s %s.\n", date, cnlMonth, cnlDay, cnlYear);

    //checking for leap year
    if (isLeapYear(y)) {
        printf("This is a leap year.\n");
    } else {
        printf("This is not a leap year.\n");
    }
}

int main() {
    char input[11];
    printf("Enter date in YYYY-MM-DD format: ");
    scanf("%s", input);

    convertToCNL(input);

    return 0;
}