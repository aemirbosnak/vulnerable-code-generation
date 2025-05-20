//Falcon2-11B DATASET v1.0 Category: Natural Language Date Converter ; Style: lively
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main() {
    char input[MAX_LEN], output[MAX_LEN];
    char* month[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char* day[] = {"1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th", "9th", "10th", "11th", "12th", "13th", "14th", "15th", "16th", "17th", "18th", "19th", "20th", "21st", "22nd", "23rd", "24th", "25th", "26th", "27th", "28th", "29th", "30th", "31st"};
    char* year[] = {"19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52"};

    printf("Enter a date in the format MM DD, YYYY: ");
    fgets(input, MAX_LEN, stdin);
    int len = strlen(input);
    char* p = strtok(input, ",");
    int day_num = atoi(p);
    p = strtok(NULL, ",");
    int month_num = atoi(p);
    p = strtok(NULL, ",");
    int year_num = atoi(p);
    if (month_num < 1 || month_num > 12) {
        printf("Invalid month\n");
        return 1;
    }
    if (day_num < 1 || day_num > 31) {
        printf("Invalid day\n");
        return 1;
    }
    if (year_num < 1 || year_num > 9999) {
        printf("Invalid year\n");
        return 1;
    }
    char* month_str = month[month_num - 1];
    char* day_str = day[day_num - 1];
    char* year_str = year[year_num - 1];
    int day_num2 = day_num % 10;
    int month_num2 = month_num % 10;
    int year_num2 = year_num % 100;
    if (day_num2 == 0 && month_num2 == 0 && year_num2 == 0) {
        day_str = "0";
    }
    if (day_num2 == 0 && month_num2 == 0) {
        month_str = "0";
    }
    if (day_num2 == 0 && year_num2 == 0) {
        year_str = "0";
    }
    if (month_num2 == 0 && year_num2 == 0) {
        year_str = "0";
    }
    if (month_num2 == 0 && day_num2 == 0) {
        day_str = "0";
    }
    strcpy(output, month_str);
    strcat(output, day_str);
    strcat(output, year_str);
    printf("Converted date: %s\n", output);
    return 0;
}