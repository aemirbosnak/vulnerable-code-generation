//FormAI DATASET v1.0 Category: Temperature monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float temp[5][3]; //2D array for storing temperature values
int hours[5]; //1D array for storing the hours when temperature was recorded
int days[5]; //1D array for storing the days when temperature was recorded

void recordTemperature();
void displayTemperature(float temp[5][3], int hours[5], int days[5]);

int main()
{
    recordTemperature(); //function call to record temperature
    displayTemperature(temp, hours, days); //function call to display temperature
    
    return 0;
}

void recordTemperature()
{
    srand(time(NULL)); //to generate random temperature values
    int temp_count = 0;
    
    printf("\nPlease enter temperature details for 5 different days:\n");
    
    for(int i=0; i<5; i++)
    {
        printf("\nTemperature details for Day %d:\n", i+1);
        days[i] = i+1;
        
        for(int j=0; j<3; j++)
        {
            printf("\nPlease enter temperature details for hour %d (between 0-24): ", j+1);
            scanf("%d",&hours[j]);
            
            if(hours[j] < 0 || hours[j] > 24)
            {
                printf("\nInvalid Input! Please enter hour between 0-24.\n");
                continue;
            }
            
            temp[i][j] = (rand()%10)+20; //random temperature values between 20-30 degrees Celsius
            temp_count++;
        }
    }
    
    printf("\n%d temperature details were successfully recorded!\n", temp_count);    
}

void displayTemperature(float temp[5][3], int hours[5], int days[5])
{
    int count = 0;
    printf("\nTemperature details for the past 5 days:\n");
    
    for(int i=0; i<5; i++)
    {
        printf("\nDay %d:\n", days[i]);
        for(int j=0; j<3; j++)
        {
            printf("Temperature recorded at hour %d: %.2f°C\n", hours[j], temp[i][j]);
            count++;
        }
    }
    
    printf("\n%d temperature details were displayed successfully!\n", count);    
}