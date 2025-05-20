//GPT-4o-mini DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define MAX_TRAVERSALS 10
#define TIME_LIMIT 10000 // 10,000 seconds for time travel
#define TIME_BUFFER 80 // Buffer for time string
#define MAX_YEAR 3000
#define MIN_YEAR 1000

typedef struct {
    int hours;
    int minutes;
    int seconds;
    int year;
    int month;
    int day;
} TimePoint;

typedef struct {
    TimePoint history[MAX_TRAVERSALS];
    int count;
} TimeTravelLog;

void initTimeLog(TimeTravelLog *log) {
    log->count = 0;
}

int isValidTimePoint(TimePoint tp) {
    if (tp.year < MIN_YEAR || tp.year > MAX_YEAR) return 0;
    // Check month
    if (tp.month < 1 || tp.month > 12) return 0;
    // Check day
    if (tp.day < 1 || tp.day > 31) return 0;
    // Check hours
    if (tp.hours < 0 || tp.hours >= 24) return 0;
    // Check minutes
    if (tp.minutes < 0 || tp.minutes >= 60) return 0;
    // Check seconds
    if (tp.seconds < 0 || tp.seconds >= 60) return 0;
    return 1;
}

void logTimePoint(TimeTravelLog *log, TimePoint tp) {
    if (log->count < MAX_TRAVERSALS) {
        log->history[log->count++] = tp;
    } else {
        // If log is full, remove the oldest entry (paranoid loss of history?)
        for (int i = 0; i < MAX_TRAVERSALS - 1; ++i) {
            log->history[i] = log->history[i + 1];
        }
        log->history[MAX_TRAVERSALS - 1] = tp;
    }
}

void printCurrentTime(TimePoint tp) {
    printf("Current Time: %04d-%02d-%02d %02d:%02d:%02d\n",
           tp.year, tp.month, tp.day, tp.hours, tp.minutes, tp.seconds);
}

void getTimePoint(TimePoint *tp) {
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    tp->year = tm_now->tm_year + 1900; // Years since 1900
    tp->month = tm_now->tm_mon + 1; // Months are 0-11
    tp->day = tm_now->tm_mday;
    tp->hours = tm_now->tm_hour;
    tp->minutes = tm_now->tm_min;
    tp->seconds = tm_now->tm_sec;
}

int travelThroughTime(TimePoint *tp, int years, int months, int days) {
    // This is not really time travel! Just simulating it conditionally
    if (years < -MAX_YEAR || years > MAX_YEAR || 
        months < -12 || months > 12 || 
        days < -31 || days > 31) {
        printf("Time travel declined. Paranoia level critical!\n");
        return 0;
    }
    
    tp->year += years;
    tp->month += months;
    tp->day += days;

    // Normalize the date (very simple normalization)
    if (tp->month > 12) {
        tp->month -= 12;
        tp->year++;
    } else if (tp->month < 1) {
        tp->month += 12;
        tp->year--;
    }

    // Check the day (days could cause overflows we cannot track exactly here)
    if (tp->day > 31) {
        tp->day = 1; // Simple overflow handling, paranoid style!
    } else if (tp->day < 1) {
        tp->day = 31; // Simple underflow handling, equally paranoid!
    }

    return 1;
}

void travel(TimeTravelLog *log) {
    TimePoint tp;
    int years, months, days;

    getTimePoint(&tp);
    printCurrentTime(tp);
    int timeSpan = 0;
    while (1) {
        printf("Enter years, months, and days to travel (negative to go back): ");
        scanf("%d %d %d", &years, &months, &days);
        
        timeSpan += abs(years) + abs(months) + abs(days);

        if (timeSpan > TIME_LIMIT) {
            printf("Time travel aborted! Exceeded safe limits. Paranoia overload!\n");
            break;
        }

        if (travelThroughTime(&tp, years, months, days)) {
            logTimePoint(log, tp);
            printCurrentTime(tp);
        }
    }
}

void displayLog(TimeTravelLog *log) {
    printf("\nTime Travel Log:\n");
    for (int i = 0; i < log->count; ++i) {
        printf("Log Entry %d: %04d-%02d-%02d %02d:%02d:%02d\n", i + 1, 
                log->history[i].year, log->history[i].month, log->history[i].day,
                log->history[i].hours, log->history[i].minutes, log->history[i].seconds);
    }
}

int main() {
    TimeTravelLog log;
    initTimeLog(&log);
    travel(&log);
    displayLog(&log);
    return 0;
}