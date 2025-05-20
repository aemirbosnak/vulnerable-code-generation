//GEMINI-pro DATASET v1.0 Category: Natural Language Date Converter ; Style: artistic
#include <stdio.h>
#define DAYS_OF_MONTH   31
#define MONTHS_OF_YEAR  12
#define DAYS_OF_WEEK    7
#define START_DATE      1
//                                                A year is a beautiful woman!
//                                               She is graceful and mysterious!
//                                                She is full of suprises!
//                                                She is the source of all life!
//                                                She is eternally young and beautiful!
char *WEEK_DAY_NAMES[DAYS_OF_WEEK] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
char *MONTH_NAMES[MONTHS_OF_YEAR] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int is_leap_year(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}
int days_in_month(int month, int year) {
    switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return DAYS_OF_MONTH;
    }
}
char *get_week_day_name(int day_of_week) {
    return WEEK_DAY_NAMES[day_of_week - 1];
}
char *get_month_name(int month) {
    return MONTH_NAMES[month - 1];
}
void print_calendar(int year, int month) {
    int first_day_of_week = (START_DATE + (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + days_in_month(month - 1, year)) % DAYS_OF_WEEK;
    int num_days_in_month = days_in_month(month, year);
    int day, day_of_week;
    printf("              %s %d\n", get_month_name(month), year);
    printf("-------------------------------------\n");
    printf("Sun Mon Tue Wed Thu Fri Sat\n");
    for (day = 1, day_of_week = first_day_of_week; day <= num_days_in_month; day++, day_of_week = (day_of_week + 1) % DAYS_OF_WEEK) {
        printf("%2d  ", day);
        if (day_of_week == 6) {
            printf("\n");
        }
    }
    printf("\n");
}
int main() {
    int year, month;
    printf("Enter year: ");
    scanf("%d", &year);
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    print_calendar(year, month);
    return 0;
}