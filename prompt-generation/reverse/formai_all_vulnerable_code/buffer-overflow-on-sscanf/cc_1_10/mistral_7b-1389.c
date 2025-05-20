//MISTRAL-7B DATASET v1.0 Category: Natural Language Date Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MONTHS_IN_YEAR 12
#define DAYS_IN_MONTH(m) ((((15 + (m)) % 4) == 0 && ((15 + (m)) % 100) != 0 || ((15 + (m)) % 100) == 0 && ((15 + (m)) % 400) == 0)) ? 29 : ((m) == 2) ? 28 : 30

char* parseDate(char* date) {
    int day, month, year;
    char* token;

    sscanf(date, "%d/%d/%d", &day, &month, &year);

    if (month < 1 || month > MONTHS_IN_YEAR || day < 1 || DAYS_IN_MONTH(month) < day) {
        free(date);
        return NULL;
    }

    char* result = malloc(11);
    sprintf(result, "%04d-%02d-%02d", year, month, day);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <dd/mm/yyyy>\n", argv[0]);
        return 1;
    }

    char* inputDate = argv[1];
    char* parsedDate = parseDate(inputDate);

    if (parsedDate == NULL) {
        printf("Invalid date format: %s\n", inputDate);
        free(inputDate);
        return 1;
    }

    struct tm* inputTime = localtime(strptime(parsedDate, "%Y-%m-%d"));
    time_t inputTimestamp = mktime(inputTime);

    char* outputFormat = "%Y-%m-%d %H:%M:%S";
    char output[32];

    strftime(output, sizeof(output), outputFormat, localtime(&inputTimestamp));
    printf("Unix timestamp: %ld\n", (long int) inputTimestamp);
    printf("Local time: %s\n", output);

    free(parsedDate);
    free(inputDate);

    return 0;
}