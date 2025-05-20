//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: shape shifting
// Time Travel Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int j = i + rand() / (RAND_MAX / (n - i) + 1);
        int t = arr[j];
        arr[j] = arr[i];
        arr[i] = t;
    }
}

// Function to check if a year is a leap year
int is_leap_year(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

// Function to get the number of days in a month
int days_in_month(int month, int year) {
    if (month == 2) {
        if (is_leap_year(year)) {
            return 29;
        } else {
            return 28;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else {
        return 31;
    }
}

// Function to get the number of weeks in a month
int weeks_in_month(int month, int year) {
    return days_in_month(month, year) / 7;
}

// Function to get the number of days in a year
int days_in_year(int year) {
    if (is_leap_year(year)) {
        return 366;
    } else {
        return 365;
    }
}

// Function to get the number of weeks in a year
int weeks_in_year(int year) {
    return days_in_year(year) / 7;
}

// Function to get the number of days between two dates
int days_between_dates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int total_days = 0;
    int current_year = year1;
    int current_month = month1;
    int current_day = day1;
    while (current_year < year2 || (current_year == year2 && current_month < month2) || (current_year == year2 && current_month == month2 && current_day <= day2)) {
        total_days += days_in_month(current_month, current_year);
        current_month++;
        if (current_month == 13) {
            current_month = 1;
            current_year++;
        }
    }
    return total_days;
}

// Function to get the number of weeks between two dates
int weeks_between_dates(int day1, int month1, int year1, int day2, int month2, int year2) {
    return days_between_dates(day1, month1, year1, day2, month2, year2) / 7;
}

// Function to get the number of years between two dates
int years_between_dates(int day1, int month1, int year1, int day2, int month2, int year2) {
    return year2 - year1;
}

// Function to print the output
void print_output(int day, int month, int year, int day2, int month2, int year2) {
    printf("The number of days between %d/%d/%d and %d/%d/%d is %d\n", day, month, year, day2, month2, year2, days_between_dates(day, month, year, day2, month2, year2));
    printf("The number of weeks between %d/%d/%d and %d/%d/%d is %d\n", day, month, year, day2, month2, year2, weeks_between_dates(day, month, year, day2, month2, year2));
    printf("The number of years between %d/%d/%d and %d/%d/%d is %d\n", day, month, year, day2, month2, year2, years_between_dates(day, month, year, day2, month2, year2));
}

int main() {
    int day, month, year, day2, month2, year2;
    printf("Enter the first date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);
    printf("Enter the second date (dd mm yyyy): ");
    scanf("%d %d %d", &day2, &month2, &year2);
    print_output(day, month, year, day2, month2, year2);
    return 0;
}