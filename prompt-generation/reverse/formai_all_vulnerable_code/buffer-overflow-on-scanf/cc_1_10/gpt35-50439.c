//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void convertDate(char *input_date, char* converted_date) {

    int day, month, year;
    //parsing the input for day, month, and year using strtok()
    char* token = strtok(input_date,"-");
    day = atoi(token);
    token = strtok(NULL,"-");
    month = atoi(token);
    token = strtok(NULL,"-");
    year = atoi(token);

    //converting month number to month name using switch case
    char* month_name;
    switch(month) {
        case 1:
            month_name = "January";
            break;
        case 2:
            month_name = "February";
            break;
        case 3:
            month_name = "March";
            break;
        case 4:
            month_name = "April";
            break;
        case 5:
            month_name = "May";
            break;
        case 6:
            month_name = "June";
            break;
        case 7:
            month_name = "July";
            break;
        case 8:
            month_name = "August";
            break;
        case 9:
            month_name = "September";
            break;
        case 10:
            month_name = "October";
            break;
        case 11:
            month_name = "November";
            break;
        case 12:
            month_name = "December";
            break;
        default:
            printf("Invalid month in date!\n");
            exit(0);
    }

    //formatting the output in required format "Month Day, Year"
    sprintf(converted_date, "%s %d, %d", month_name, day, year);
}

int main() {
    char input_date[11];
    char converted_date[20];

    printf("Enter date in format 'DD-MM-YYYY': ");
    scanf("%s", input_date);

    convertDate(input_date, converted_date);

    printf("Converted date: %s\n", converted_date);

    return 0;
}