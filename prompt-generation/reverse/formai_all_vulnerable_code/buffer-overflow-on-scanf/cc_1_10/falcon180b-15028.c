//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char* month_str[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

struct tm parse_date(char* str) {
    struct tm date = {0};
    char* token;
    int year, month, day;
    char* ptr = strdup(str);
    token = strtok(ptr, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }
    if (strcasecmp(token, "today") == 0) {
        time_t now = time(NULL);
        localtime_r(&now, &date);
        return date;
    } else if (strcasecmp(token, "yesterday") == 0) {
        time_t now = time(NULL);
        localtime_r(&now, &date);
        date.tm_mday -= 1;
        return date;
    } else if (strcasecmp(token, "tomorrow") == 0) {
        time_t now = time(NULL);
        localtime_r(&now, &date);
        date.tm_mday += 1;
        return date;
    }
    year = atoi(token);
    token = strtok(NULL, " ");
    if (token == NULL) {
        printf("Invalid date format\n");
        exit(1);
    }
    month = 0;
    for (int i = 0; i < 12; i++) {
        if (strcasecmp(token, month_str[i]) == 0) {
            month = i + 1;
            break;
        }
    }
    if (month == 0) {
        printf("Invalid month\n");
        exit(1);
    }
    day = atoi(strtok(NULL, " "));
    if (day < 1 || day > 31) {
        printf("Invalid day\n");
        exit(1);
    }
    date.tm_year = year - 1900;
    date.tm_mon = month - 1;
    date.tm_mday = day;
    return date;
}

char* format_date(struct tm date) {
    char* str = malloc(30);
    strftime(str, 30, "%B %d, %Y", &date);
    return str;
}

int main() {
    char* input;
    struct tm date;
    printf("Enter a date (format: MM/DD/YYYY): ");
    scanf("%s", input);
    date = parse_date(input);
    printf("Formatted date: %s\n", format_date(date));
    return 0;
}