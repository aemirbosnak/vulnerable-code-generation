//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX_CITIES 50
#define MAX_TEMP_RANGE 30
#define MAX_DAYS 30

typedef struct city {
    char name[50];
    int temp;
    int humidity;
} city;

typedef struct day {
    int temp[MAX_CITIES];
    int humidity[MAX_CITIES];
} day;

void generate_cities(city cities[]) {
    int i;
    for(i=0;i<MAX_CITIES;i++) {
        sprintf(cities[i].name,"City_%d",i+1);
        cities[i].temp = rand()%MAX_TEMP_RANGE+1;
        cities[i].humidity = rand()%100;
    }
}

void generate_weather(day days[], city cities[], int num_cities) {
    int i,j,k;
    for(i=0;i<MAX_DAYS;i++) {
        for(j=0;j<num_cities;j++) {
            days[i].temp[j] = cities[j].temp + rand()%MAX_TEMP_RANGE-cities[j].temp/2;
            days[i].humidity[j] = cities[j].humidity + rand()%20-cities[j].humidity/2;
        }
    }
}

void print_weather(day days[], int num_days, city cities[], int num_cities) {
    int i,j;
    printf("\nWeather Forecast:\n");
    for(i=0;i<num_days;i++) {
        printf("\nDay %d Forecast:\n",i+1);
        for(j=0;j<num_cities;j++) {
            printf("City: %s\tTemperature: %d\tHumidity: %d%%\n",cities[j].name,days[i].temp[j],days[i].humidity[j]);
        }
    }
}

int main() {
    city cities[MAX_CITIES];
    day days[MAX_DAYS];
    int num_cities,num_days;
    printf("Enter the number of cities: ");
    scanf("%d",&num_cities);
    generate_cities(cities);
    printf("\nCities generated:\n");
    for(int i=0;i<num_cities;i++) {
        printf("City: %s\tTemperature: %d\tHumidity: %d%%\n",cities[i].name,cities[i].temp,cities[i].humidity);
    }
    printf("\nEnter the number of days for the weather forecast: ");
    scanf("%d",&num_days);
    generate_weather(days,cities,num_cities);
    print_weather(days,num_days,cities,num_cities);
    return 0;
}