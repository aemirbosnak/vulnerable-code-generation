//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>
#include <string.h>

char* dateConverter(char* date, int targetYear) {
    int year, month, day;
    sscanf(date, "%d-%d-%d", &year, &month, &day);
    int newYear = targetYear;
    if (year < newYear) {
        newYear -= year;
    } else {
        newYear -= year + 1;
        newYear += targetYear;
    }
    int newMonth = month;
    switch (newYear % 100) {
        case 0:
            newMonth -= 2;
            if (newMonth < 0) {
                newMonth += 12;
                newYear--;
            }
            break;
        case 3:
            newMonth -= 4;
            if (newMonth < 0) {
                newMonth += 12;
                newYear--;
            }
            break;
        case 5:
            newMonth--;
            if (newMonth < 0) {
                newMonth += 12;
                newYear--;
            }
            break;
        default:
            // No adjustment needed for other years
            break;
    }
    char newDate[11];
    sprintf(newDate, "%d-%02d-%02d", newYear, newMonth, day);
    return strdup(newDate);
}

int main() {
    char dateString[11] = "2000-02-29";
    int targetYear = 2022;
    char* newDate = dateConverter(dateString, targetYear);
    printf("%s\n", newDate);
    free(newDate);
    return 0;
}