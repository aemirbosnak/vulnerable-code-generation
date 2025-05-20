//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITIES 100
#define MAX_DAYS 365

typedef struct {
    char name[20];
    int x, y;
    double temp, humidity;
} city;

city cities[MAX_CITIES];
int num_cities;

void init_cities() {
    int i;
    for (i = 0; i < MAX_CITIES; i++) {
        cities[i].temp = 0;
        cities[i].humidity = 0;
    }
    num_cities = 0;
}

void add_city(char *name, int x, int y) {
    if (num_cities >= MAX_CITIES) {
        printf("Error: too many cities\n");
        return;
    }
    strcpy(cities[num_cities].name, name);
    cities[num_cities].x = x;
    cities[num_cities].y = y;
    num_cities++;
}

void update_weather(int day) {
    int i;
    for (i = 0; i < num_cities; i++) {
        cities[i].temp += (rand() % 10 - 5);
        cities[i].humidity += (rand() % 10 - 5);
    }
}

void print_weather(int day) {
    int i;
    for (i = 0; i < num_cities; i++) {
        printf("%s: %.1f°C %.1f%%\n", cities[i].name, cities[i].temp, cities[i].humidity);
    }
}

int main() {
    srand(time(NULL));
    init_cities();
    int days;
    printf("Enter number of days to simulate: ");
    scanf("%d", &days);
    if (days <= 0 || days > MAX_DAYS) {
        printf("Error: invalid number of days\n");
        return 1;
    }
    int i;
    for (i = 0; i < num_cities; i++) {
        printf("%s added\n", cities[i].name);
    }
    for (i = 0; i < days; i++) {
        update_weather(i);
        print_weather(i);
    }
    return 0;
}