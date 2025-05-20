//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to convert julian day number to date
void julian_to_date(int jdn, int *year, int *month, int *day) {
    int l, n, i, j, k;

    l = jdn + 68569;
    n = (4 * l) / 146097;
    l = l - ((146097 * n + 3) / 4);
    i = (4000 * (l + 1)) / 1461001;
    l = l - (1461 * i) / 4 + 31;
    j = (80 * l) / 2447;
    k = l - (2447 * j) / 80;
    l = j / 11;
    j = j + 2 - (12 * l);
    i = 100 * (n - 49) + i + l;

    *year = i;
    *month = j;
    *day = k;
}

// function to convert date to julian day number
int date_to_julian(int year, int month, int day) {
    int a, b, c, d, e, jd;

    if (month < 3) {
        year--;
        month += 12;
    }
    a = year / 100;
    b = a / 4;
    c = 2 - a + b;
    d = 365.25 * (year + 4716);
    e = 30.6001 * (month + 1);

    jd = c + day + d + e - 1524.5;

    return jd;
}

int main() {
    int year, month, day;
    int jdn, choice;

    printf("Select operation: \n");
    printf("1. Convert Julian day number to date \n");
    printf("2. Convert date to Julian day number \n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter Julian day number: ");
        scanf("%d", &jdn);

        julian_to_date(jdn, &year, &month, &day);

        printf("Date: %d/%d/%d\n", day, month, year);
    } else if (choice == 2) {
        printf("Enter date (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &day, &month, &year);

        jdn = date_to_julian(year, month, day);

        printf("Julian day number: %d\n", jdn);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }

    return 0;
}