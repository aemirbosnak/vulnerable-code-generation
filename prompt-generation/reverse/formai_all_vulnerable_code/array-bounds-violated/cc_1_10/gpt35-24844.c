//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>

#define MIN_YEAR 1753
#define DAYS_IN_WEEK 7

struct Date {
    int day;
    int month;
    int year;
};

void print_day_of_week(int day_index) {
    switch (day_index) {
        case 0:
            printf("Sunday");
            break;
        case 1:
            printf("Monday");
            break;
        case 2:
            printf("Tuesday");
            break;
        case 3:
            printf("Wednesday");
            break;
        case 4:
            printf("Thursday");
            break;
        case 5:
            printf("Friday");
            break;
        case 6:
            printf("Saturday");
            break;
        default:
            printf("Invalid day index");
    }
}

int is_leap_year(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0 && year % 400 != 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int get_days_in_month(int month, int year) {
    int days_in_month[12] = {31, 28 + is_leap_year(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days_in_month[month - 1];
}

int get_day_of_week(struct Date date) {
    int a = (14 - date.month) / 12;
    int y = date.year - a;
    int m = date.month + 12 * a - 2;
    int d = (date.day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % DAYS_IN_WEEK;
    return d;
}

void print_date(struct Date date) {
    printf("%d-%02d-%02d\n", date.year, date.month, date.day);
}

struct Date get_date_from_julian(int julian) {
    struct Date date;
    int a = julian + 32044;
    int b = (4 * a + 3) / 146097;
    int c = a - (146097 * b) / 4;
    int d = (4 * c + 3) / 1461;
    int e = c - (1461 * d) / 4;
    int m = (5 * e + 2) / 153;
    date.day = e - (153 * m + 2) / 5 + 1;
    date.month = m + 3 - 12 * (m / 10);
    date.year = 100 * b + d - 4800 + (m / 10);
    return date;
}

int get_julian_from_date(struct Date date) {
    int a = (14 - date.month) / 12;
    int y = date.year + 4800 - a;
    int m = date.month + 12 * a - 3;
    int julian = date.day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
    return julian;
}

struct Date add_days(struct Date date, int days) {
    for (int i = 0; i < days; i++) {
        if (date.day < get_days_in_month(date.month, date.year)) {
            date.day++;
        } else {
            if (date.month == 12) {
                date.year++;
                date.month = 1;
                date.day = 1;
            } else {
                date.month++;
                date.day = 1;
            }
        }
    }
    return date;
}

struct Date subtract_days(struct Date date, int days) {
    for (int i = 0; i < days; i++) {
        if (date.day > 1) {
            date.day--;
        } else {
            if (date.month == 1) {
                date.year--;
                date.month = 12;
                date.day = get_days_in_month(date.month, date.year);
            } else {
                date.month--;
                date.day = get_days_in_month(date.month, date.year);
            }
        }
    }
    return date;
}

void print_julian_date(int julian) {
    struct Date date = get_date_from_julian(julian);
    print_date(date);
    printf("Day of week: ");
    print_day_of_week(get_day_of_week(date));
}

void print_date_difference(struct Date date1, struct Date date2) {
    int julian1 = get_julian_from_date(date1);
    int julian2 = get_julian_from_date(date2);
    int difference = julian2 - julian1;
    if (difference >= 0) {
        printf("%d days between ", difference);
        print_date(date1);
        printf(" and ");
        print_date(date2);
    } else {
        printf("%d days between ", -difference);
        print_date(date2);
        printf(" and ");
        print_date(date1);
    }
}

int main() {
    printf("Welcome to the Natural Language Date Converter\n");
    printf("Please enter the starting date (in YYYY-MM-DD format): ");
    char date_string[11];
    fgets(date_string, 11, stdin);
    int year, month, day;
    sscanf(date_string, "%d-%d-%d", &year, &month, &day);
    struct Date start_date = {day, month, year};
    printf("Please enter the number of days to add/subtract: ");
    int days;
    scanf("%d", &days);
    printf("Would you like to add or subtract days? (+/-): ");
    char operation;
    scanf(" %c", &operation);
    struct Date end_date;
    if (operation == '+') {
        end_date = add_days(start_date, days);
    } else if (operation == '-') {
        end_date = subtract_days(start_date, days);
    } else {
        printf("Invalid operation: %c\n", operation);
        return 1;
    }
    printf("The resulting date is: ");
    print_date(end_date);
    printf("It is a ");
    print_day_of_week(get_day_of_week(end_date));
    printf("\n");
    print_date_difference(start_date, end_date);
    printf("\n");
}