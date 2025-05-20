//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char *months[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int get_month(char *m) {
    int i;
    for (i = 1; i <= 12; i++) {
        if (strcmp(m, months[i]) == 0) {
            return i;
        }
    }
    return 0;
}

int is_leap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return 1;
    }
    return 0;
}

int get_days(int month, int year) {
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else if (month == 2) {
        if (is_leap(year) == 1) {
            return 29;
        }
        return 28;
    }
    else {
        return 31;
    }
}

void convert_date(char *date) {
    char day[3], month[10], year[5];
    char *token = strtok(date, "/");
    int i = 0;
    while (token != NULL) {
        if (i == 0) {
            strcpy(month, token);
        }
        else if (i == 1) {
            strcpy(day, token);
        }
        else if (i == 2) {
            strcpy(year, token);
        }
        token = strtok(NULL, "/");
        i++;
    }
    int m = get_month(month);
    int d = atoi(day);
    int y = atoi(year);
    if (m == 0 || d > get_days(m, y) || y < 0) {
        printf("Invalid date\n");
        return;
    }
    printf("%d %s %d\n", d, months[m], y);
}

int main() {
    char date[11];
    printf("Enter date in mm/dd/yyyy format: ");
    scanf("%s", date);
    convert_date(date);
    return 0;
}