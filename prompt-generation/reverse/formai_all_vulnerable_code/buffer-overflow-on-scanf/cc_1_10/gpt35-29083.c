//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* A structure to represent temperature data */
struct temperature {
    char date[15];
    float temperature;
};

void getTemp(struct temperature *temp)
{
    printf("Enter the date (dd-mm-yyyy): ");
    scanf("%s", temp->date);

    printf("Enter the temperature: ");
    scanf("%f", &(temp->temperature));
}

void displayTemp(struct temperature *temp)
{
    printf("%s: %.1f", temp->date, temp->temperature);
}

int findMaxTemp(struct temperature *temps, int numTemps)
{
    int maxIndex = 0;
    float maxTemp = temps[0].temperature;

    for(int i = 1; i < numTemps; i++)
    {
        if(temps[i].temperature > maxTemp)
        {
            maxTemp = temps[i].temperature;
            maxIndex = i;
        }
    }

    return maxIndex;
}

int findMinTemp(struct temperature *temps, int numTemps)
{
    int minIndex = 0;
    float minTemp = temps[0].temperature;

    for(int i = 1; i < numTemps; i++)
    {
        if(temps[i].temperature < minTemp)
        {
            minTemp = temps[i].temperature;
            minIndex = i;
        }
    }

    return minIndex;
}

float findAvgTemp(struct temperature *temps, int numTemps)
{
    float sum = 0;

    for(int i = 0; i < numTemps; i++)
    {
        sum += temps[i].temperature;
    }

    return sum / numTemps;
}

void saveTempToFile(struct temperature *temp)
{
    FILE *fp;

    fp = fopen("temperature_data.txt", "a");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    fprintf(fp, "%s %.1f\n", temp->date, temp->temperature);

    fclose(fp);
}

void readTempFromFile(struct temperature *temps, int *numTemps)
{
    FILE *fp;
    char date[15];
    float temperature;

    fp = fopen("temperature_data.txt", "r");

    if(fp == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while(fscanf(fp, "%s %f", date, &temperature) != EOF)
    {
        strcpy(temps[*numTemps].date, date);
        temps[*numTemps].temperature = temperature;
        (*numTemps)++;
    }

    fclose(fp);
}

int main()
{
    int choice, numTemps = 0;
    struct temperature temps[100];

    readTempFromFile(temps, &numTemps);

    do
    {
        printf("\nMenu\n");
        printf("1. Enter temperature data\n");
        printf("2. Display temperature data\n");
        printf("3. Find maximum temperature\n");
        printf("4. Find minimum temperature\n");
        printf("5. Find average temperature\n");
        printf("6. Save temperature data to file\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                getTemp(&temps[numTemps]);
                numTemps++;
                break;

            case 2:
                printf("\nTemperature Data\n");
                for(int i = 0; i < numTemps; i++)
                {
                    displayTemp(&temps[i]);
                    printf("\n");
                }
                break;

            case 3:
                if(numTemps > 0)
                {
                    int maxIndex = findMaxTemp(temps, numTemps);
                    printf("\nMaximum temperature:\n");
                    displayTemp(&temps[maxIndex]);
                }
                else
                {
                    printf("\nNo temperature data available\n");
                }
                break;

            case 4:
                if(numTemps > 0)
                {
                    int minIndex = findMinTemp(temps, numTemps);
                    printf("\nMinimum temperature:\n");
                    displayTemp(&temps[minIndex]);
                }
                else
                {
                    printf("\nNo temperature data available\n");
                }
                break;

            case 5:
                if(numTemps > 0)
                {
                    float avgTemp = findAvgTemp(temps, numTemps);
                    printf("\nAverage temperature: %.1f\n", avgTemp);
                }
                else
                {
                    printf("\nNo temperature data available\n");
                }
                break;

            case 6:
                if(numTemps > 0)
                {
                    saveTempToFile(&temps[numTemps - 1]);
                    printf("\nTemperature data saved to file\n");
                }
                else
                {
                    printf("\nNo temperature data available\n");
                }
                break;

            case 7:
                printf("\nExiting program\n");
                break;

            default:
                printf("\nInvalid choice\n");
        }

    } while(choice != 7);

    return 0;
}