//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convertDate(char inputDate[]) {
    char months[12][10] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    char *day, *month, *year;
    int d, m, y, numOfDays;

    day = strtok(inputDate,"-");
    month = strtok(NULL,"-");
    year = strtok(NULL,"-");

    d = atoi(day);
    y = atoi(year);

    for(int i = 0; i < 12; i++) {
        if(strcmp(month, months[i]) == 0) {
            m = i + 1;
            numOfDays = daysInMonth[i];
            break;
        }
    }

    // Check for leap year
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
        if(numOfDays == 28) {
            numOfDays++;
        }
    }

    // Check for valid input date
    if(d < 1 || d > numOfDays || m < 1 || m > 12) {
        printf("Invalid input date!\n");
        return;
    }

    // Calculate Julian day
    int a = (14 - m) / 12;
    int yyyymm = (y + 4800 - a) * 372;
    int mm = m * 31;
    int julianDay = d + (yyyymm - mm) / 122 + (y - y / 4);

    printf("\nOutput: Julian Day = %d\n", julianDay);
}

int main() {
    char inputDate[20];

    printf("Welcome to the Cheerful Natural Language Date Converter!\n");
    printf("Enter the date in this format DD-MMM-YYYY: ");
    scanf("%[^\n]s", inputDate);

    convertDate(inputDate);

    return 0;
}