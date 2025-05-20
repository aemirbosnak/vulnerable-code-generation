//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: configurable
#include <stdio.h>

const char months[12][10] = {{"January"},
                             {"February"},
                             {"March"},
                             {"April"},
                             {"May"},
                             {"June"},
                             {"July"},
                             {"August"},
                             {"September"},
                             {"October"},
                             {"November"},
                             {"December"}};

const int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isLeap(int yy) {
    if((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0)
        return 1;
    else
        return 0;
}

int main() {
    int date, month, year;

    printf("Enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &date, &month, &year);

    // Check if the given date is valid
    if(month < 1 || month > 12) {
        printf("Invalid date!\n");
        return 0;
    }

    if(date < 1 || date > days[month-1] + (month == 2 ? isLeap(year) : 0)) {
        printf("Invalid date!\n");
        return 0;
    }

    // Convert to Natural Language date format
    printf("%d", date);
    switch(date) {
        case 1: case 21: case 31:
            printf("st ");
            break;

        case 2: case 22:
            printf("nd ");
            break;

        case 3: case 23:
            printf("rd ");
            break;

        default:
            printf("th ");
            break;
    }

    printf("%s, %d\n", months[month-1], year);

    return 0;
}