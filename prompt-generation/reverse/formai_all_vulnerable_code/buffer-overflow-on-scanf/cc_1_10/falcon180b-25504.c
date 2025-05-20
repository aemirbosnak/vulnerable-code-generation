//Falcon-180B DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_DATE_FORMATS 10

typedef struct {
    char *date_format;
    time_t date;
} date_t;

void *convert_date(void *arg) {
    date_t *date = (date_t *) arg;
    struct tm tm;

    strptime(date->date_format, "%Y-%m-%d", &tm);
    date->date = mktime(&tm);

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    date_t dates[MAX_DATE_FORMATS];
    int num_dates = 0;

    printf("Enter the number of dates to convert: ");
    scanf("%d", &num_dates);

    for (int i = 0; i < num_dates; i++) {
        printf("Enter date format (%d/%d/%d): ", i+1, i+1, i+1);
        scanf("%s", dates[i].date_format);
    }

    for (int i = 0; i < num_dates; i++) {
        pthread_create(&threads[i], NULL, convert_date, &dates[i]);
    }

    for (int i = 0; i < num_dates; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < num_dates; i++) {
        printf("Date %d: %s\n", i+1, ctime(&dates[i].date));
    }

    return 0;
}