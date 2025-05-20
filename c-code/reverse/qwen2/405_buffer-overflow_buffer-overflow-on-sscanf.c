#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_date(char *date) {
    int day, month, year, hour, minute;
    char am_pm[3], timezone[3];
    if (sscanf(date, "%d/%d/%d %d:%d %2s %2s", &day, &month, &year, &hour, &minute, am_pm, timezone) != 7) return 0;
    if (month < 1 || month > 12) return 0;
    if (day < 1 || day > 31) return 0;
    if (year < 1900 || year > 2100) return 0;
    if (hour < 1 || hour > 12) return 0;
    if (minute < 0 || minute > 59) return 0;
    if (strcmp(am_pm, "AM") != 0 && strcmp(am_pm, "PM") != 0) return 0;
    if (strlen(timezone) != 3) return 0;
    return 1;
}

int main() {
    char date[50];
    printf("Enter date (DD/MM/YYYY HH:MM AM/PM Timezone): ");
    fgets(date, sizeof(date), stdin);
    date[strcspn(date, "\n")] = '\0';
    if (validate_date(date)) {
        printf("Date is valid.\n");
    } else {
        printf("Date is invalid.\n");
    }
    return 0;
}
