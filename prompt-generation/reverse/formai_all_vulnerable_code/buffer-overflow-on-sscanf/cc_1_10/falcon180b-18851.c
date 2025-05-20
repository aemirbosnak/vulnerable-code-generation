//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <wchar.h>

#define MAX_DATE_LENGTH 20
#define MAX_MONTH_LENGTH 9
#define MAX_DAY_LENGTH 2
#define MAX_YEAR_LENGTH 4

typedef struct {
    char month[MAX_MONTH_LENGTH + 1];
    char day[MAX_DAY_LENGTH + 1];
    char year[MAX_YEAR_LENGTH + 1];
} Date;

void get_date(Date* date)
{
    char input[MAX_DATE_LENGTH + 1];
    printf("Enter the date in the format dd/mm/yyyy: ");
    scanf("%s", input);

    int i = 0;
    while (i < strlen(input)) {
        if (input[i] == '/') {
            date->month[0] = input[i + 1];
            date->month[1] = input[i + 2];
            date->day[0] = input[i + 3];
            date->day[1] = input[i + 4];
            date->year[0] = input[i + 5];
            date->year[1] = input[i + 6];
            date->year[2] = input[i + 7];
            date->year[3] = input[i + 8];
            break;
        }
        i++;
    }
}

int is_valid_date(Date* date)
{
    int month, day, year;
    if (sscanf(date->month, "%d", &month) == 0 || sscanf(date->day, "%d", &day) == 0 || sscanf(date->year, "%d", &year) == 0) {
        return 0;
    }

    if (month < 1 || month > 12) {
        return 0;
    }

    if (day < 1 || day > 31) {
        return 0;
    }

    if (year < 1000 || year > 9999) {
        return 0;
    }

    if (month == 2) {
        if (day > 29 && (year % 4!= 0 || (year % 100 == 0 && year % 400!= 0))) {
            return 0;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return 0;
        }
    } else {
        if (day > 31) {
            return 0;
        }
    }

    return 1;
}

void print_date(Date* date)
{
    printf("%s %d, %d\n", date->month, date->day, date->year);
}

int main()
{
    setlocale(LC_ALL, "en_US.utf8");
    Date date;

    while (1) {
        get_date(&date);
        if (is_valid_date(&date)) {
            print_date(&date);
            break;
        } else {
            printf("Invalid date\n");
        }
    }

    return 0;
}