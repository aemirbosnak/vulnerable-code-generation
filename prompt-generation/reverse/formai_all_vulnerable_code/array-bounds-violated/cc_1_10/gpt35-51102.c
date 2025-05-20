//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complete
#include <stdio.h>
#include <string.h>

void dateConverter(char date[]);

int main()
{
    char date[11];
    
    printf("Enter a date in format 'YYYY-MM-DD': ");
    fgets(date, 11, stdin); // fgets reads input string as "YYYY-MM-DD\n" including newline
    
    // remove newline character from input string
    int len = strlen(date);
    if (date[len-1] == '\n') {
        date[len-1] = '\0';
    }
    
    dateConverter(date);
    
    return 0;
}

void dateConverter(char date[])
{
    char month[3], day[3], year[5];
    int i, j;
    
    // extract year
    j = 0;
    for (i = 0; i < 4; i++) {
        year[j] = date[i];
        j++;
    }
    year[4] = '\0';
    
    // extract month
    j = 0;
    for (i = 5; i < 7; i++) {
        month[j] = date[i];
        j++;
    }
    month[2] = '\0';
    
    // extract day
    j = 0;
    for (i = 8; i < 10; i++) {
        day[j] = date[i];
        j++;
    }
    day[2] = '\0';
    
    // convert month from string to int
    int m = atoi(month);
    
    // convert day from string to int
    int d = atoi(day);
    
    // convert year from string to int
    int y = atoi(year);
    
    // determine month name
    char* monthName;
    switch (m) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            printf("Invalid month");
            return;
    }
    
    // print date in natural language format
    printf("%s %d, %d", monthName, d, y);
}