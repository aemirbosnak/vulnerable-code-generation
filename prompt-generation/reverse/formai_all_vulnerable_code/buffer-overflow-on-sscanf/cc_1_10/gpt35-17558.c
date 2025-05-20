//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: peaceful
#include <stdio.h>
#include <string.h>

char *months[] = {"January", "February", "March", "April", "May", "June", 
                  "July", "August", "September", "October", "November", "December"};

int days_in_month[] = {31,28,31,30,31,30,31,31,30,31,30,31};

struct Date {
    int day;
    int month;
    int year;
};

int is_leap_year(int year) {
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return 1;
    else
        return 0;
}

int calculate_days(struct Date date) {
    int sum = 0;
    int i;
    
    for(i = 0; i < date.month - 1; i++) {
        sum += days_in_month[i];
    }
    
    if(date.month > 2 && is_leap_year(date.year)) 
        sum += 1;
        
    sum += date.day;
    
    return sum;
}

void calculate_date(int total_days, struct Date *date) {
    int i;
    
    for(i = 0; i < 12; i++) {
        if(total_days > days_in_month[i]) {
            total_days -= days_in_month[i];
        }
        else {
            break;
        }
    }
    
    date->day = total_days;
    date->month = i + 1;
    date->year = 1;
}

void print_date(struct Date date) {
    printf("%s %d, %d\n", months[date.month - 1], date.day, date.year);
}

int main() {
    struct Date date;
    char input[100];
    
    printf("Enter date in the format of MM/DD/YYYY: ");
    fgets(input, 100, stdin);
    sscanf(input, "%d/%d/%d", &date.month, &date.day, &date.year);
    
    int total_days = calculate_days(date);
    
    printf("Total number of days in the year: %d\n", is_leap_year(date.year) ? 366 : 365);
    printf("Total number of days in the given date: %d\n", total_days);
    
    calculate_date(total_days, &date);
    
    print_date(date);
    
    return 0;
}