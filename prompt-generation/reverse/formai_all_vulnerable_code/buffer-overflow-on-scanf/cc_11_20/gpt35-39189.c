//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: grateful
#include <stdio.h>

int main() {
    int day, month, year;
    printf("Welcome to the Natural Language Date Converter!\n");
    printf("Please enter a date in the format DD/MM/YYYY: ");
    scanf("%d/%d/%d", &day, &month, &year);

    char *months[] = {
        "",
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    char *ones[] = {
        "",
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine"
    };
    char *teens[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen"
    };
    char *tens[] = {
        "",
        "ten",
        "twenty",
        "thirty",
        "forty",
        "fifty",
        "sixty",
        "seventy",
        "eighty",
        "ninety"
    };

    if (day < 1 || day > 31 || month < 1 || month > 12) {
        printf("Invalid date!");
        return 1;
    }

    printf("Natural Language Date: ");

    if (day == 1) {
        printf("the first ");
    } else if (day == 2) {
        printf("the second ");
    } else if (day == 3) {
        printf("the third ");
    } else if (day >= 4 && day <= 9) {
        printf("the %s ", ones[day]);
    } else if (day >= 10 && day <= 19) {
        printf("%s ", teens[day - 10]);
    } else {
        printf("%s %s ", tens[day / 10], ones[day % 10]);
    }

    printf("of %s, %s", months[month], tens[year / 10]);
    if (year % 10 != 0) {
        printf("-%s\n", ones[year % 10]);
    } else {
        printf("\n");
    }

    return 0;
}