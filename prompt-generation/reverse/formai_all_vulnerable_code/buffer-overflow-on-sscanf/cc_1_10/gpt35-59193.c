//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: scalable
#include <stdio.h>
#include <string.h>

const char *months[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

int days_in_month(int month, int year) {
    switch (month) {
        case 2:
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

void print_date(int day, int month, int year) {
    printf("%d %s %d\n", day, months[month-1], year);
}

int main() {
    char input[50];
    int day, month, year;

    printf("Enter a date in the format DD/MM/YYYY: ");
    fgets(input, 50, stdin);
    sscanf(input, "%d/%d/%d", &day, &month, &year);

    int days_in_current_month = days_in_month(month, year);

    if (day < 1 || day > days_in_current_month) {
        printf("Error: Invalid day\n");
        return 1;
    }

    if (month < 1 || month > 12) {
        printf("Error: Invalid month\n");
        return 1;
    }

    print_date(day, month, year);

    return 0;
}