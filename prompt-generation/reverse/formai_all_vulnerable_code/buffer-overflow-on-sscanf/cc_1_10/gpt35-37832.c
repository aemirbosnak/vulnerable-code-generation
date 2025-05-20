//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const char* months[] = {"January", "February", "March",
                        "April", "May", "June",
                        "July", "August", "September",
                        "October", "November", "December"};

char* month_regex = "(jan(uary)?|feb(ruary)?|mar(ch)?|apr(il)?|may|june?|july?|aug(ust)?|sep(t(ember)?)?|oct(ober)?|nov(ember)?|dec(ember)?)";
char* date_regex = "(0?[1-9]|[1-2][0-9]|3[0-1])";
char* year_regex = "(\\d{4})";

void convert_date(char* date_string) {
    char* month_str;
    char month[10];
    int date;
    int year;
    sscanf(date_string, "%s %d, %d", month, &date, &year);

    for (int i = 0; i < 12; ++i) {
        if (strstr(month, months[i])) {
            month_str = months[i];
            break;
        }
    }
    printf("%s %d, %d\n", month_str, date, year);
}

void convert_date_regex(char* date_string) {
    int date, year;
    char* month_str;
    char month[10];
    if (sscanf(date_string, "%[^\n] %d, %d", month, &date, &year) &&
        sscanf(month, "%[^\n]s", month)) {
        for (int i = 0; i < strlen(month); ++i) {
            month[i] = tolower(month[i]);
        }
        if (sscanf(month, "%s", month)) {
            if (sscanf(month, "%s", month)) {
                if (sscanf(date_string, "%*[^\n]%*3c %s %d %s %d", 
                            month, &date, year_regex, &year) == 4) {
                    for (int i = 0; i < 12; ++i) {
                        if (strstr(month, months[i])) {
                            month_str = months[i];
                            break;
                        }
                    }
                    printf("%s %d, %d\n", month_str, date, year);
                    return;
                }
            }
        }
    }
    printf("Invalid date format.\n");
}

int main() {
    char* date_string = "July 4, 1776";
    convert_date(date_string); // Output: July 4, 1776

    date_string = "March 16, 2021";
    convert_date(date_string); // Output: March 16, 2021

    date_string = "Sept. 3, 2022";
    convert_date_regex(date_string); // Output: September 3, 2022

    date_string = "12/31/1999";
    convert_date_regex(date_string); // Output: Invalid date format.

    date_string = "Jan. 1 2022";
    convert_date_regex(date_string); // Output: January 1, 2022

    date_string = "November 11, 1918";
    convert_date(date_string); // Output: November 11, 1918
    
    return 0;
}