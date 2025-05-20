//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: high level of detail
#include <stdio.h>
#include <string.h>

char* get_month(int m) {
    switch(m) {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "";
    }
}

int is_leap_year(int y) {
     return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int day_of_year(int d, int m, int y) {
    int daysinmonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (is_leap_year(y)) {
        daysinmonth[1] = 29;
    }

    int days = d;

    for (int i=0; i<m-1; i++) {
        days += daysinmonth[i];
    }

    return days;
}

void date_converter(int d, int m, int y) {
    printf("The date you entered is %d %s %d.\n", d, get_month(m), y);
    printf("It is the %d day of the year.\n", day_of_year(d, m, y));
}

int main() {
    int d, m, y;
    printf("Please enter the date in DD/MM/YYYY format: ");
    scanf("%d/%d/%d", &d, &m, &y);
    date_converter(d, m, y);
    return 0;
}