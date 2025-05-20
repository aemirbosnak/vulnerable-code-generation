//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct {
    int day;
    int month;
    int year;
} Date;

void convert_date_to_words(Date date, char* buffer) {
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    if (date.day < 1 || date.day > 31) {
        strcpy(buffer, "Invalid day");
        return;
    }

    if (date.month < 1 || date.month > 12) {
        strcpy(buffer, "Invalid month");
        return;
    }

    if (date.year < 1000 || date.year > 9999) {
        strcpy(buffer, "Invalid year");
        return;
    }

    sprintf(buffer, "%s, %d %s %d", days[date.day - 1], date.day, months[date.month - 1], date.year);
}

int main() {
    Date date;
    char input_buffer[MAX_BUFFER_SIZE];
    char output_buffer[MAX_BUFFER_SIZE];

    printf("Enter a date in YYYY-MM-DD format: ");
    fgets(input_buffer, MAX_BUFFER_SIZE, stdin);

    if (sscanf(input_buffer, "%d-%d-%d", &date.year, &date.month, &date.day)!= 3) {
        strcpy(output_buffer, "Invalid date format");
        printf("%s\n", output_buffer);
        return 1;
    }

    convert_date_to_words(date, output_buffer);
    printf("%s\n", output_buffer);

    return 0;
}