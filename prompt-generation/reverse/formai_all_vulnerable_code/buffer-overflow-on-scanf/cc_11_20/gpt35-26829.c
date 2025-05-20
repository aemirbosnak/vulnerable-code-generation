//FormAI DATASET v1.0 Category: Weather simulation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to check if the input is valid or not
int is_valid(int input){
    if(input >= 0 && input <= 100){
        return 1;
    } else {
        printf("Invalid input! Please enter a number between 0 and 100.\n");
        return 0;
    }
}

int main(){
    int temperature, humidity, wind_speed, precipitation_chance, visibility;
    int month, day, year, hour, minute;
    int weather_score = 0;

    // get current date and time
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);

    // get user inputs for weather variables
    printf("Enter current temperature (in Celsius): ");
    scanf("%d", &temperature);
    while(!is_valid(temperature)){
        printf("Enter current temperature (in Celsius): ");
        scanf("%d", &temperature);
    }

    printf("Enter current humidity (in percentage): ");
    scanf("%d", &humidity);
    while(!is_valid(humidity)){
        printf("Enter current humidity (in percentage): ");
        scanf("%d", &humidity);
    }

    printf("Enter current wind speed (in km/h): ");
    scanf("%d", &wind_speed);
    while(!is_valid(wind_speed)){
        printf("Enter current wind speed (in km/h): ");
        scanf("%d", &wind_speed);
    }

    printf("Enter current precipitation chance (in percentage): ");
    scanf("%d", &precipitation_chance);
    while(!is_valid(precipitation_chance)){
        printf("Enter current precipitation chance (in percentage): ");
        scanf("%d", &precipitation_chance);
    }

    printf("Enter current visibility (in km): ");
    scanf("%d", &visibility);
    while(!is_valid(visibility)){
        printf("Enter current visibility (in km): ");
        scanf("%d", &visibility);
    }

    // get user inputs for current date and time
    printf("Enter current month (1-12): ");
    scanf("%d", &month);
    while(!is_valid(month) || month > 12){
        printf("Enter current month (1-12): ");
        scanf("%d", &month);
    }

    printf("Enter current day (1-31): ");
    scanf("%d", &day);
    while(!is_valid(day) || day > 31){
        printf("Enter current day (1-31): ");
        scanf("%d", &day);
    }

    printf("Enter current year: ");
    scanf("%d", &year);

    printf("Enter current hour (0-23): ");
    scanf("%d", &hour);
    while(!is_valid(hour) || hour > 23){
        printf("Enter current hour (0-23): ");
        scanf("%d", &hour);
    }

    printf("Enter current minute (0-59): ");
    scanf("%d", &minute);
    while(!is_valid(minute) || minute > 59){
        printf("Enter current minute (0-59): ");
        scanf("%d", &minute);
    }

    // calculate weather score based on inputs
    weather_score += temperature;
    weather_score += humidity/10;
    weather_score += wind_speed/2;
    weather_score -= precipitation_chance/2;
    weather_score += visibility/10;

    // output results
    printf("\nCurrent weather condition at %02d/%02d/%d %02d:%02d:\n", month, day, year, hour, minute);
    printf("Temperature: %d C\nHumidity: %d%%\nWind Speed: %d km/h\nPrecipitation Chance: %d%%\nVisibility: %d km\n", temperature, humidity, wind_speed, precipitation_chance, visibility);
    printf("Weather Score: %d\n", weather_score);

    // generate random weather conditions for tomorrow
    srand(time(NULL));
    int tomorrow_temperature = temperature + (rand() % 11) - 5;
    while(!is_valid(tomorrow_temperature)){
        tomorrow_temperature = temperature + (rand() % 11) - 5;
    }

    int tomorrow_humidity = humidity + (rand() % 21) - 10;
    while(!is_valid(tomorrow_humidity)){
        tomorrow_humidity = humidity + (rand() % 21) - 10;
    }

    int tomorrow_wind_speed = wind_speed + (rand() % 21) - 10;
    while(!is_valid(tomorrow_wind_speed)){
        tomorrow_wind_speed = wind_speed + (rand() % 21) - 10;
    }

    int tomorrow_precipitation_chance = precipitation_chance + (rand() % 21) - 10;
    while(!is_valid(tomorrow_precipitation_chance)){
        tomorrow_precipitation_chance = precipitation_chance + (rand() % 21) - 10;
    }

    int tomorrow_visibility = visibility + (rand() % 11) - 5;
    while(!is_valid(tomorrow_visibility)){
        tomorrow_visibility = visibility + (rand() % 11) - 5;
    }

    // output tomorrow's weather condition
    printf("\nTomorrow's weather condition:\n");
    printf("Temperature: %d C\nHumidity: %d%%\nWind Speed: %d km/h\nPrecipitation Chance: %d%%\nVisibility: %d km\n", tomorrow_temperature, tomorrow_humidity, tomorrow_wind_speed, tomorrow_precipitation_chance, tomorrow_visibility);

    return 0;
}