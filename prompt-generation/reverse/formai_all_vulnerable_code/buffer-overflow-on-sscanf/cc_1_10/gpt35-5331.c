//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: intelligent
#include <stdio.h>
#include <string.h>

// function to convert date from natural language to date format
void convertDate(char date[]) {
    char months[12][10] = {"January", "February", "March", "April", "May", "June", "July",
                            "August", "September", "October", "November", "December"};
    int days_in_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    char month[10], day[3], year[5]; // variables to store month, day and year

    // splitting the natural language date into month, day and year
    sscanf(date, "%s %s %s", month, day, year);

    int m, d, y; // variables to store the numeric value of month, day and year
    
    // converting month to its numeric value
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i]) == 0) {
            m = i + 1;
            break;
        }
    }
    
    d = atoi(day); // converting day to its numeric value
    y = atoi(year); // converting year to its numeric value

    // checking for leap year
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        days_in_month[1] = 29;

    // checking if day is within the range for the given month and year
    if (d < 1 || d > days_in_month[m-1]) {
        printf("Invalid date!");
        return;
    }

    // printing the date in mm/dd/yyyy format
    printf("%02d/%02d/%04d", m, d, y);
}

int main() {
    char date[20];

    printf("Enter the date in natural language (e.g. January 1 2022): ");
    fgets(date, 20, stdin);

    // removing the newline character from the string obtained from fgets()
    if (date[strlen(date)-1] == '\n')
        date[strlen(date)-1] = '\0';

    convertDate(date);

    return 0;
}