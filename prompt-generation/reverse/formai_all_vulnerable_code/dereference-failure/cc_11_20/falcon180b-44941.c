//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define INPUT_LENGTH 100
#define OUTPUT_LENGTH 500
#define TIME_LENGTH 20
#define DATE_LENGTH 20

typedef struct {
    char input[INPUT_LENGTH];
    char output[OUTPUT_LENGTH];
    struct tm time;
    struct tm date;
} TimeTravelData;

void printUsage() {
    printf("Usage:./program [input] [time] [date]\n");
    printf("Where:\n");
    printf("  input: The text to send to the past/future.\n");
    printf("  time: The time in the format 'hh:mm:ss'.\n");
    printf("  date: The date in the format 'dd/mm/yyyy'.\n");
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 5) {
        printUsage();
    }

    TimeTravelData data;

    strcpy(data.input, argv[1]);

    strptime(argv[2], "%T", &data.time);
    strptime(argv[3], "%d/%m/%Y", &data.date);

    printf("Traveling back/forward in time to %s...\n", asctime(&data.time));

    printf("The date is %s.\n", asctime(&data.date));

    switch (data.time.tm_hour) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("It's the middle of the night. You should be sleeping!\n");
            break;
        case 5:
        case 6:
        case 7:
            printf("It's early in the morning. Wake up and smell the coffee!\n");
            break;
        case 8:
        case 9:
        case 10:
        case 11:
            printf("It's morning. Time to start the day!\n");
            break;
        case 12:
            printf("It's noon. Time for lunch!\n");
            break;
        case 13:
        case 14:
        case 15:
            printf("It's afternoon. Keep up the good work!\n");
            break;
        case 16:
        case 17:
        case 18:
            printf("It's evening. Time to wind down.\n");
            break;
        case 19:
        case 20:
        case 21:
        case 22:
            printf("It's night. Time to relax.\n");
            break;
        case 23:
            printf("It's late at night. You should be sleeping!\n");
            break;
    }

    switch (data.date.tm_mday) {
        case 1:
        case 21:
        case 31:
            printf("It's the first/twenty-first/thirty-first of the month.\n");
            break;
        default:
            printf("It's the %dth of the month.\n", data.date.tm_mday);
            break;
    }

    printf("Your message has been sent to the past/future.\n");

    switch (data.time.tm_hour) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf("You receive a message from the future at %s:\n%s\n", asctime(&data.time), data.input);
            break;
        case 5:
        case 6:
        case 7:
            printf("You receive a message from the past at %s:\n%s\n", asctime(&data.time), data.input);
            break;
        default:
            printf("You receive a message from the future/past at %s:\n%s\n", asctime(&data.time), data.input);
            break;
    }

    return 0;
}