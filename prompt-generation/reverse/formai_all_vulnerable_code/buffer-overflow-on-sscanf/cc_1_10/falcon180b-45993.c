//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to convert a given date string to a tm struct
struct tm *parse_date(const char *str) {
    struct tm tm = {0};
    int year, month, day;
    char *token = strtok(str, " ");
    if (token == NULL) {
        return NULL;
    }
    if (sscanf(token, "%d", &day)!= 1 || day < 1 || day > 31) {
        return NULL;
    }
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    if (sscanf(token, "%d", &month)!= 1 || month < 1 || month > 12) {
        return NULL;
    }
    token = strtok(NULL, " ");
    if (token == NULL) {
        return NULL;
    }
    if (sscanf(token, "%d", &year)!= 1 || year < 1000 || year > 9999) {
        return NULL;
    }
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    return &tm;
}

// Function to print a given date in a natural language format
void print_date(const struct tm *date) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%A, %B %d, %Y", date);
    printf("%s\n", buffer);
}

int main() {
    char input[80];
    while (fgets(input, sizeof(input), stdin)!= NULL) {
        struct tm *date = parse_date(input);
        if (date!= NULL) {
            print_date(date);
        }
    }
    return 0;
}