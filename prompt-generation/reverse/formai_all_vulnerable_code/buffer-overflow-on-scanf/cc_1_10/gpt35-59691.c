//FormAI DATASET v1.0 Category: Weather simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //initiate variables
    int i, j, day, temp[7], rainfall[7], humid[7], max_temp=0, max_rain=0, max_humid=0;
    char week[7][10] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
    srand(time(0));

    //get data for each day
    for(i=0;i<7;i++){
        printf("Please enter weather data for %s.\n",week[i]);
        printf("Temperature (degrees Celsius): ");
        scanf("%d",&temp[i]);
        printf("Rainfall (millimeters): ");
        scanf("%d",&rainfall[i]);
        printf("Humidity (percentage): ");
        scanf("%d",&humid[i]);

        //check for extreme values
        if(temp[i] > max_temp){
            max_temp = temp[i];
            day = i;
        }
        if(rainfall[i] > max_rain){
            max_rain = rainfall[i];
            j = i;
        }
        if(humid[i] > max_humid){
            max_humid = humid[i];
        }
    }

    //print extreme values
    printf("\n\nExtreme weather conditions during the week:\n");
    printf("The highest temperature of %d degrees Celsius was recorded on %s.\n",max_temp,week[day]);
    printf("The highest rainfall of %d millimeters was recorded on %s.\n",max_rain,week[j]);
    printf("The highest humidity of %d percent was recorded on multiple days.\n\n",max_humid);

    //simulate the upcoming week's weather
    printf("Simulating upcoming week's weather...\n");
    for(i=0;i<7;i++){
        temp[i] += (rand()%6) - 2;
        if(temp[i] < -10){
            temp[i] = -10;
        }
        rainfall[i] += (rand()%21) - 10;
        if(rainfall[i] < 0){
            rainfall[i] = 0;
        }
        humid[i] += (rand()%11) - 5;
        if(humid[i] < 0){
            humid[i] = 0;
        }
    }
    printf("Done! Here's the upcoming week's weather:\n");

    //print the upcoming week's weather
    for(i=0;i<7;i++){
        printf("%s - Temperature: %d degrees Celsius, Rainfall: %d millimeters, Humidity: %d percent\n",week[i],temp[i],rainfall[i],humid[i]);
    }
    return 0;
}