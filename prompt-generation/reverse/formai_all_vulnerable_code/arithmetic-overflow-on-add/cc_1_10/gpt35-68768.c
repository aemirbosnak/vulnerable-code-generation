//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: active
#include <stdio.h>
#include <time.h>
#include <string.h>

// Function to convert date from Natural Language to Julian date
int convert_date(char* date_str) {
    int month, day, year;
    sscanf(date_str, "%d %*s %d %*s %d", &day, &month, &year);
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12*a - 3;
    int jd = day + (153*m + 2) / 5 + 365*y + y/4 - y/100 + y/400 - 32045;
    return jd;
}

// Function to convert Julian date to Natural Language date
char* convert_julian_date(int jd) {
    int a, b, c, d, e, month, day, year;
    if (jd > 2299160) {
        a = jd + 32044;
        b = (4*a + 3) / 146097;
        c = a - ((b * 146097) / 4);
    } else {
        b = 0;
        c = jd + 32082;
    }
    d = (4*c + 3) / 1461;
    e = c - ((1461 * d) / 4);
    month = (5*e + 2) / 153;
    day = e - ((153*month + 2) / 5) + 1;
    year = (b * 100) + d - 4800 + (month / 10);
    char* date_str = malloc(sizeof(char)*20);
    sprintf(date_str, "%d-%02d-%02d", year, month, day);
    return date_str;
}

int main() {
    // Get the current date in Natural Language format
    time_t t = time(NULL);
    struct tm* now = localtime(&t);
    char* current_date_str = asctime(now);
    
    // Convert the current date to Julian date
    int current_jd = convert_date(current_date_str);
    
    // Get 5 random dates in Natural Language format
    char* dates[5] = {
        "12th January 2022",
        "7th February 2022",
        "21st March 2022",
        "16th April 2022",
        "3rd May 2022"
    };
    
    // Convert each date to Julian date and print the difference from the current date
    printf("Dates:\n");
    for (int i = 0; i < 5; i++) {
        int jd = convert_date(dates[i]);
        int diff = jd - current_jd;
        printf("%s (%d days from today)\n", dates[i], diff);
    }
    printf("\n");
    
    // Get a Julian date from user input and convert it to Natural Language format
    printf("Enter a Julian date (e.g. 2459628): ");
    int jd_input;
    scanf("%d", &jd_input);
    char* date_str = convert_julian_date(jd_input);
    printf("%d is %s\n", jd_input, date_str);
    free(date_str);
    
    return 0;
}