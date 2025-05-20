//FormAI DATASET v1.0 Category: Weather simulation ; Style: complex
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

//Fucntion for generatinig random temperature values
int generateTemperature(){
    int temp;
    temp = rand() % 50; // Generates random values from 0-50
    return temp;
}

//Function for generating random rainfall values
int generateRainfall(){
    int rain;
    rain = rand() % 100; // Generating random values from 0-100
    return rain;
}

//Function for generating random atmospheric pressure values
int generateAtmosphericPressure(){
    int pressure;
    pressure = rand() % 1000; //Generating rando values from 0-1000
    return pressure;
}

int main(){
    int days, temp, rain, pressure, cnt;
    int x, y;
    
    //Setting seed for random value generation
    srand(time(NULL));
    
    printf("Enter the number of days to simulate the weather: ");
    scanf("%d", &days);
    
    //Drawing box and assigning co-ordinates
    printf("\n\n\n");
    printf("               +-----------------------------------------------------------+\n");
    printf("               |                                                           |\n");
    printf("               |                                                           |\n");
    for (y = 0; y < 10; y++){
        printf("               |");
        for (x = 0; x < 69; x++){
            if (x == 0 || x == 68){
                printf("|");
            } else if (y == 0 || y == 9){
                printf("-");
            } else {
                printf(" ");
            }
        }
        printf("|\n");
    }
    printf("               |                                                           |\n");
    printf("               |                                                           |\n");
    printf("               +-----------------------------------------------------------+\n");
    
    //Labelling the axes
    printf("\n\n\n\n");
    printf("               Days\n");
    printf("\n\n");
    printf("          +-----------------------------------------------------------+\n");
    printf("   1000   |                                                           |\n");
    printf("          |                                                           |\n");
    printf("          |                                                           |\n");
    printf("   750    |       ****************                                    |\n");
    printf("          |    **                                           **       |\n");
    printf("          |  **                                               **     |\n");
    printf("   500    |**                                                   **   |\n");
    printf("          |                                                       ** |\n");
    printf("          |                                                         **|\n");
    printf("   250    |                                                           |\n");
    printf("          |                                                           |\n");
    printf("          |                                                           |\n");
    printf("    0     +-----------------------------------------------------------+\n");
    printf("                ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^    \n");
    printf("                0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5\n\n\n");
    
    //Drawing graph for temperature, rainfall and atmospheric pressure
    cnt = 1;
    for (int d = 1; d <= days; d++){
        temp = generateTemperature();
        rain = generateRainfall();
        pressure = generateAtmosphericPressure();
        printf("%2d [Temp: %2dC, Rain: %3dmm, Pressure: %4dPa] ", d, temp, rain, pressure);
        for (x = 1; x <= temp; x++){
            printf("+");
        }
        printf("\n");
        for (x = 1; x <= rain; x++){
            printf(".");
        }
        printf("\n");
        for (x = 1; x <= pressure/25; x++){
            printf("o");
        }
        printf("\n");
        printf("\n");    
        cnt++;
    }
    
    return 0;
}