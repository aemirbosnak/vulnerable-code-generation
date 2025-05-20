//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100
#define MIN 0
#define WINDY 8
#define STORMY 10
#define RAINY 7
#define SNOWY 5
#define SUNNY 1
#define CLOUDY 3
#define FOGGY 2

int weather[MAX];
int temp[MAX];
int humidity[MAX];
int wind_speed[MAX];

void generate_weather(int days)
{
    int i;
    srand(time(NULL));
    for(i=0;i<days;i++)
    {
        weather[i] = rand()%7;
        temp[i] = rand()%20+5;
        humidity[i] = rand()%10+50;
        wind_speed[i] = rand()%10+1;
    }
}

void print_weather(int days)
{
    int i;
    for(i=0;i<days;i++)
    {
        if(weather[i] == SUNNY)
        {
            printf("%d is a sunny day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == CLOUDY)
        {
            printf("%d is a cloudy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == RAINY)
        {
            printf("%d is a rainy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == STORMY)
        {
            printf("%d is a stormy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == SNOWY)
        {
            printf("%d is a snowy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == FOGGY)
        {
            printf("%d is a foggy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
        else if(weather[i] == WINDY)
        {
            printf("%d is a windy day with temperature %d degrees Celsius and humidity %d%%.\n",i+1,temp[i],humidity[i]);
        }
    }
}

int main()
{
    int days;
    printf("Enter the number of days you want to simulate the weather for: ");
    scanf("%d",&days);
    generate_weather(days);
    print_weather(days);
    return 0;
}