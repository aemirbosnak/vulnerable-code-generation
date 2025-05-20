//FormAI DATASET v1.0 Category: Weather simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 40
#define MIN_TEMP -20

int main(){

    int temperature[24]; // stores hourly temperature from 0 to 23
    int days, i, j;

    srand((unsigned int) time(NULL)); // initialize RNG

    printf("Enter the number of days you want to simulate weather for: ");
    scanf("%d", &days); // get the number of days from user

    printf("Generating weather report....\n");

    // print header
    printf("Hourly temperature for %d day(s):\n", days);
    printf("+----+----------+\n");
    printf("|Day |Temperature|\n");
    printf("+----+----------+\n");

    // loop through each day
    for(i=1;i<=days;i++){

        int average_temp=0;
        // loop through each hour
        for(j=0;j<24;j++){
            // generate temperature between MIN_TEMP and MAX_TEMP
            int temp = rand() % (MAX_TEMP - MIN_TEMP + 1) + MIN_TEMP;
            temperature[j]=temp;
            average_temp+=temp;
        }
        average_temp/=24;

        // print hourly temperature for the day
        printf("|%3d |",i);
        for(j=0;j<24;j++){
            printf("%2d",temperature[j]);
            if(temperature[j]>=0){
                printf(" ");
            }
            printf("|");
        }
        printf("\n");

        // print average temperature for the day
        printf("|    |   AVG: %2d |",average_temp);

        // print weather conditions for the day
        if(average_temp>25){
            printf("  HOT   ");
        }else if(average_temp>15){
            printf("WARMISH ");
        }else if(average_temp>5){
            printf(" CHILLY ");
        }else{
            printf(" WINTER ");
        }
        printf("|\n");

        printf("+----+----------+\n");

    }

    return 0;
}