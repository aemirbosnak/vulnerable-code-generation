#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE];
    time_t t;
    struct tm *tm_ptr;

    printf("Enter date and time in DD/MM/YYYY HH:MM AM/PM Timezone format: ");
    fgets(input, BUFFER_SIZE, stdin);

    sscanf(input, "%d/%d/%d %d:%d %s", &tm_ptr->tm_mday, &tm_ptr->tm_mon, &tm_ptr->tm_year, &tm_ptr->tm_hour, &tm_ptr->tm_min, tm_ptr->tm_zone);

    tm_ptr->tm_year -= 1900;
    tm_ptr->tm_mon--;

    if (tm_ptr->tm_mon < 0 || tm_ptr->tm_mon > 11) {
        printf("Invalid month\n");
        return 1;
    }

    if (tm_ptr->tm_mday > 31 || (tm_ptr->tm_mon == 2 && tm_ptr->tm_mday > 28)) {
        printf("Invalid day\n");
        return 1;
    }

    if (tm_ptr->tm_hour > 12 || tm_ptr->tm_hour < 0) {
        printf("Invalid hour\n");
        return 1;
    }

    t = mktime(tm_ptr);
    printf("Time traveled to: %s\n", asctime(localtime(&t)));

    return 0;
}
