//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>

int main(){
    int month, day, year;
    printf("Welcome to the Date Converter Program!\n");
    printf("Please enter the month (in numeric format): ");
    scanf("%d", &month);
    printf("Please enter the day: ");
    scanf("%d", &day);
    printf("Please enter the year (in four digits): ");
    scanf("%d", &year);
    if(month < 1 || month > 12 || day < 1 || day > 31 || year < 1000 || year > 9999){
        printf("Invalid input! Please enter proper values.\n");
        exit(0);
    }
    char monthString[10];
    switch(month){
        case 1:
            sprintf(monthString, "January");
            break;
        case 2:
            sprintf(monthString, "February");
            break;
        case 3:
            sprintf(monthString, "March");
            break;
        case 4:
            sprintf(monthString, "April");
            break;
        case 5:
            sprintf(monthString, "May");
            break;
        case 6:
            sprintf(monthString, "June");
            break;
        case 7:
            sprintf(monthString, "July");
            break;
        case 8:
            sprintf(monthString, "August");
            break;
        case 9:
            sprintf(monthString, "September");
            break;
        case 10:
            sprintf(monthString, "October");
            break;
        case 11:
            sprintf(monthString, "November");
            break;
        default:
            sprintf(monthString, "December");
            break;
    }
    printf("The date you entered is: %s %d, %d.\n", monthString, day, year);
    return 0;
}