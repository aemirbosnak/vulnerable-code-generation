//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CITY 10
#define MAX_DAY 365
#define MIN_TEMP -50
#define MAX_TEMP 50

struct City {
    char name[20];
    int x, y;
    int temp[MAX_DAY];
    int day;
};

void initCity(struct City *city, char *name, int x, int y) {
    strcpy(city->name, name);
    city->x = x;
    city->y = y;
    for(int i=0; i<MAX_DAY; i++) {
        city->temp[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    }
    city->day = 0;
}

void printCity(struct City *city) {
    printf("City: %s\n", city->name);
    printf("Location: (%d, %d)\n", city->x, city->y);
    printf("Current temperature: %d\n", city->temp[city->day]);
}

void updateCity(struct City *city) {
    city->day = (city->day + 1) % MAX_DAY;
    for(int i=0; i<MAX_DAY; i++) {
        city->temp[i] = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
    }
}

int main() {
    srand(time(NULL));
    struct City cities[MAX_CITY];
    int numCities = 0;
    char input[100];
    while(numCities < MAX_CITY) {
        printf("Enter name of the city: ");
        scanf("%s", input);
        if(numCities >= MAX_CITY) {
            printf("Maximum number of cities reached.\n");
        } else {
            int x, y;
            printf("Enter x-coordinate of the city: ");
            scanf("%d", &x);
            printf("Enter y-coordinate of the city: ");
            scanf("%d", &y);
            initCity(&cities[numCities], input, x, y);
            numCities++;
        }
    }
    while(1) {
        printf("Enter city name to print weather: ");
        scanf("%s", input);
        int i;
        for(i=0; i<numCities; i++) {
            if(strcmp(cities[i].name, input) == 0) {
                printCity(&cities[i]);
                break;
            }
        }
        if(i == numCities) {
            printf("City not found.\n");
        }
        printf("Press any key to continue...\n");
        getchar();
    }
    return 0;
}