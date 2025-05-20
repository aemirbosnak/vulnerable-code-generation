//FormAI DATASET v1.0 Category: Natural Language Date Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_DATE_LENGTH 11

pthread_mutex_t lock;

char* monthNames[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int numOfDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

typedef struct date {
    int day;
    int month;
    int year;
    char* name;
} Date;

Date* createDate(int day, int month, int year, char* name) {
    Date* d = malloc(sizeof(Date));
    d->day = day;
    d->month = month;
    d->year = year;
    d->name = name;
    return d;
}

void freeDate(Date* d) {
    free(d->name);
    free(d);
}

void printDate(Date* d) {
    printf("%d%s %s %d\n", d->day, (d->day == 1 || d->day == 21 || d->day == 31) ? "st" : (d->day == 2 || d->day == 22) ? "nd" : (d->day == 3 || d->day == 23) ? "rd" : "th", d->name, d->year);
}

void* convert_date(void* dateStr) {
    pthread_mutex_lock(&lock);
    char* str = (char*)dateStr;
    int day, month, year;
    Date* d;

    if (strlen(str) != MAX_DATE_LENGTH) {
        printf("Invalid date format\n");
    }
    else if (str[2] != '-' || str[5] != '-') {
        printf("Invalid date format\n");
    }
    else {

        day = atoi(str);
        month = atoi(str + 3);
        year = atoi(str + 6);

        if (day > numOfDays[month] || day < 1 || month < 1 || month > 12 || year < 1) {
            printf("Invalid date\n");
        }
        else {
            d = createDate(day, month, year, monthNames[month]);
            printDate(d);
            freeDate(d);
        }
    }
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

int main() {
    int n = 0;
    char dateStr[MAX_DATE_LENGTH];
    pthread_t threads[5];

    if(pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex init failed\n");
        return 1;
    }

    while (1) {
        printf("Enter a date in dd-mm-yyyy format (type exit to quit): ");
        scanf("%s", dateStr);

        if (strcmp(dateStr, "exit") == 0) {
            break;
        }

        pthread_create(&threads[n++], NULL, convert_date, (void*)dateStr);

        if (n == 5) {
            for (int i = 0; i < 5; i++) {
                pthread_join(threads[i], NULL);
            }
            n = 0;
        }
    }

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            pthread_join(threads[i], NULL);
        }
    }

    pthread_mutex_destroy(&lock);

    return 0;
}