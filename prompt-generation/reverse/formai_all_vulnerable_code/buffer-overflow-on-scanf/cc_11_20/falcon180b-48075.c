//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DATE_LENGTH 50
#define MONTH_NAMES "January February March April May June July August September October November December"

const struct {
    const char *name;
    int length;
} month_lengths[] = {
    {"January", 31},
    {"February", 28},
    {"March", 31},
    {"April", 30},
    {"May", 31},
    {"June", 30},
    {"July", 31},
    {"August", 31},
    {"September", 30},
    {"October", 31},
    {"November", 30},
    {"December", 31}
};

int main() {
    char date_str[MAX_DATE_LENGTH];
    char month_str[20];
    char day_str[20];
    char year_str[20];
    int day, month, year;
    int i;
    
    printf("Enter a date in MM/DD/YYYY format: ");
    scanf("%s", date_str);
    
    sscanf(date_str, "%s/%s/%s", month_str, day_str, year_str);
    
    day = atoi(day_str);
    month = atoi(month_str);
    year = atoi(year_str);
    
    if (day < 1 || day > 31) {
        printf("Invalid day.\n");
        return 1;
    }
    
    if (month < 1 || month > 12) {
        printf("Invalid month.\n");
        return 1;
    }
    
    if (year < 1000 || year > 9999) {
        printf("Invalid year.\n");
        return 1;
    }
    
    for (i = 0; i < 12; i++) {
        if (strcmp(month_str, MONTH_NAMES + (i * 3)) == 0) {
            if (month > month_lengths[i].length) {
                printf("Invalid day for %s.\n", month_str);
                return 1;
            }
            break;
        }
    }
    
    if (i == 12) {
        printf("Invalid month.\n");
        return 1;
    }
    
    if (month == 2) {
        if (day > 29) {
            printf("Invalid day for February.\n");
            return 1;
        }
    }
    
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        printf("Invalid day.\n");
        return 1;
    }
    
    printf("The date %s/%s/%d is valid.\n", month_str, day_str, year);
    
    return 0;
}