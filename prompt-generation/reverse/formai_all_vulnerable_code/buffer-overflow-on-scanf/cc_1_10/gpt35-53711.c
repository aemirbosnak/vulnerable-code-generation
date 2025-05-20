//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* months[12] = {"January", "February", "March", "April", "May", "June",
                    "July", "August", "September", "October", "November", "December"};

int get_month_days(int month, int year) {
    if (month == 2) {
        if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
            return 29;
        else
            return 28;
    } else if ((month <= 7 && month % 2 != 0) || (month > 7 && month % 2 == 0))
        return 31;
    else
        return 30;
}

void convert_date(int day, int month, int year) {
    char buf[20];
    sprintf(buf, "%d", day);

    char suffix[3];
    if (day == 1 || day == 21 || day == 31)
        strcpy(suffix, "st");
    else if (day == 2 || day == 22)
        strcpy(suffix, "nd");
    else if (day == 3 || day == 23)
        strcpy(suffix, "rd");
    else
        strcpy(suffix, "th");

    printf("%s%s %s %d\n", buf, suffix, months[month - 1], year);
}

int main() {
    char date_str[20];
    printf("Enter a date (dd/mm/yyyy): ");
    scanf("%s", date_str);

    int day, month, year;

    char* token = strtok(date_str, "/");
    day = atoi(token);

    token = strtok(NULL, "/");
    month = atoi(token);

    token = strtok(NULL, "/");
    year = atoi(token);

    int total_days = 0;
    for (int i = 1; i < month; i++)
        total_days += get_month_days(i, year);

    total_days += day;

    printf("The date %s converted to natural language is: ", date_str);
    convert_date(day, month, year);

    printf("The total days from the beginning of the year is: %d\n", total_days);

    return 0;
}