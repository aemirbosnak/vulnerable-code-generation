//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: post-apocalyptic
#include<stdio.h>
#include<string.h>

int main(){
    //declaring variables 
    char date[20];
    char newDate[20];
    char month[10];
    char day[3];
    char year[5];

    //prompting the user and getting input
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", date);

    //parsing the date string 
    strncpy(month, date, 2);
    month[2] = '\0';
    strncpy(day, date + 3, 2);
    day[2] = '\0';
    strncpy(year, date + 6, 4);
    year[4] = '\0';

    //converting the month string to integer value
    int monthInt = atoi(month);

    //checking if month is valid
    if(monthInt < 1 || monthInt > 12){
        printf("Invalid month\n");
        return 0;
    }

    //converting the year string to integer value
    int yearInt = atoi(year);

    //checking if year is valid
    if(yearInt < 0 || yearInt > 9999){
        printf("Invalid year\n");
        return 0;
    }

    //converting the day string to integer value
    int dayInt = atoi(day);

    //checking if day is valid
    int maxDay;
    if(monthInt == 2){
        //checking for leap year
        if(((yearInt % 4 == 0) && (yearInt % 100 != 0)) || (yearInt % 400 == 0)){
            maxDay = 29;
        }else{
            maxDay = 28;
        }
    }else if(monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12){
        maxDay = 31;
    }else{
        maxDay = 30;
    }

    if(dayInt < 1 || dayInt > maxDay){
        printf("Invalid day\n");
        return 0;
    }

    //generating new date string in the format "Month Day, Year"
    switch(monthInt){
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

    sprintf(newDate, "%s %s, %s", month, day, year);

    //printing the new date string
    printf("New date: %s\n", newDate);

    return 0;
}