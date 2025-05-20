//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert month name to number
int get_month_number(char* month_name) {
    if(strcmp(month_name,"January") == 0) {
        return 1;
    } else if(strcmp(month_name,"February") == 0) {
        return 2;
    } else if(strcmp(month_name,"March") == 0) {
        return 3;
    } else if(strcmp(month_name,"April") == 0) {
        return 4;
    } else if(strcmp(month_name,"May") == 0) {
        return 5;
    } else if(strcmp(month_name,"June") == 0) {
        return 6;
    } else if(strcmp(month_name,"July") == 0) {
        return 7;
    } else if(strcmp(month_name,"August") == 0) {
        return 8;
    } else if(strcmp(month_name,"September") == 0) {
        return 9;
    } else if(strcmp(month_name,"October") == 0) {
        return 10;
    } else if(strcmp(month_name,"November") == 0) {
        return 11;
    } else if(strcmp(month_name,"December") == 0) {
        return 12;
    } else {
        printf("Invalid month name!\n");
        exit(1);
    }
}

// Function to convert date to Julian Day
long get_julian_day(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    long jd = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return jd;
}

// Function to convert Julian Day to date
void julian_day_to_date(long jd, int* year, int* month, int* day) {
    int a,b,c,d,e;

    if(jd > 2299160) {
        a = (int)((jd - 1867216.25) / 36524.25);
        a = jd + 1 + a - a / 4;
    } else {
        a = jd;
    }

    b = a + 1524;
    c = (int)((b - 122.1) / 365.25);
    d = (int)(365.25 * c);
    e = (int)((b - d) / 30.6001);
    
    *day = b - d - (int)(30.6001 * e);
    *month = e - (e > 13.5 ? 13 : 1);
    *year = c - (*month < 2.5 ? 4715 : 4716);
}

// Main function to convert date
void convert_date(char* date_str) {
    int year, month, day;
    long jd;
    char month_name[10];
    sscanf(date_str,"%[^ ] %d, %d",month_name,&day,&year);
    month = get_month_number(month_name);
    jd = get_julian_day(year,month,day);
    julian_day_to_date(jd,&year,&month,&day);
    printf("%04d-%02d-%02d\n",year,month,day);
}

// Test function to show the usage of the program
void test() {
    convert_date("December 22, 2020");
    convert_date("September 1, 2024");
    convert_date("June 5, 2001");
    convert_date("February 29, 2000");
}

// Main function
int main() {
    test();
    return 0;
}