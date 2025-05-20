//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_STOCKS 100
#define MAX_DAYS 365

struct stock {
    char name[20];
    double price;
    int volume;
};

struct day {
    time_t timestamp;
    struct stock stocks[MAX_STOCKS];
};

void print_stock(struct stock stock) {
    printf("%s: $%.2f (%d)\n", stock.name, stock.price, stock.volume);
}

void print_day(struct day day) {
    printf("Day %d:\n", day.timestamp);
    for (int i = 0; i < MAX_STOCKS; i++) {
        if (day.stocks[i].price!= 0) {
            print_stock(day.stocks[i]);
        }
    }
}

void add_stock(struct day *day, char *name, double price, int volume) {
    int index = 0;
    while (index < MAX_STOCKS && day->stocks[index].name[0]!= '\0') {
        index++;
    }
    if (index == MAX_STOCKS) {
        printf("Error: Maximum number of stocks reached.\n");
        return;
    }
    strcpy(day->stocks[index].name, name);
    day->stocks[index].price = price;
    day->stocks[index].volume = volume;
}

void main() {
    struct day days[MAX_DAYS];
    int num_days = 0;
    int current_day = 0;

    while (1) {
        printf("Enter stock information (name price volume): ");
        char name[20];
        double price;
        int volume;
        scanf("%s %lf %d", name, &price, &volume);

        if (strcmp(name, "") == 0) {
            break;
        }

        add_stock(&days[current_day], name, price, volume);

        if (++num_days >= MAX_DAYS) {
            printf("Error: Maximum number of days reached.\n");
            break;
        }
    }

    printf("Stock Market Tracker\n");
    printf("=====================\n");

    while (1) {
        printf("Enter day to view (0-%d): ", num_days - 1);
        int day_num;
        scanf("%d", &day_num);

        if (day_num < 0 || day_num >= num_days) {
            printf("Invalid day number.\n");
            continue;
        }

        print_day(days[day_num]);
    }
}