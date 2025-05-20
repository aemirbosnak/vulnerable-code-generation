//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: optimized
#define MONTHS_IN_YEAR 12
#define LEAP_YEAR(y) (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0))

int main(int argC, char* argV[]) {
    int day, month, year, totalDays;
    
    if (argC != 4) {
        printf("Usage: %s <dd/mm/yyyy>\n", argV[0]);
        return 1;
    }

    sscanf(argV[1], "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > MONTHS_IN_YEAR || day < 1) {
        printf("Invalid date.\n");
        return 1;
    }

    // Calculate total days from 01/01/0001 to given date
    totalDays = 0;
    for (int y = 1; y < year; y++) {
        totalDays += LEAP_YEAR(y) ? 366 : 365;
    }
    for (int m = 1; m < month; m++) {
        int daysInMonth = LEAP_YEAR(year) && m == 2 ? 29 : (month % 2 == 0 ? 28 : 31);
        totalDays += daysInMonth;
    }
    totalDays += day;

    printf("Total days: %d\n", totalDays);

    // Convert total days back to dd/mm/yyyy format
    int yearFromTotalDays = 0, monthFromTotalDays = 0, dayFromTotalDays = 0;
    int totalDaysInYear = 0;

    for (year = 1; year <= 3000; year++) {
        totalDaysInYear += LEAP_YEAR(year) ? 366 : 365;
        if (totalDays <= totalDaysInYear + dayFromTotalDays) {
            yearFromTotalDays = year;
            break;
        }
        dayFromTotalDays++;
    }

    monthFromTotalDays = totalDaysInYear + dayFromTotalDays - 1;
    dayFromTotalDays -= totalDaysInYear;

    int daysInLastMonth = LEAP_YEAR(yearFromTotalDays) && monthFromTotalDays == 2 ? 29 : (monthFromTotalDays % 2 == 0 ? 28 : 31);

    if (dayFromTotalDays > daysInLastMonth) {
        monthFromTotalDays++;
        dayFromTotalDays -= daysInLastMonth;
    }

    printf("Date: %02d/%02d/%04d\n", dayFromTotalDays, monthFromTotalDays, yearFromTotalDays);

    return 0;
}