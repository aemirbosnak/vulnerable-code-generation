//Falcon-180B DATASET v1.0 Category: Temperature monitor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

//Variables
int temperature = 0;
int humidity = 0;

//Functions
void getTemperature() {
    FILE *file;
    char line[50];
    file = fopen("temperature.txt", "r");
    if (file!= NULL) {
        fgets(line, 50, file);
        fclose(file);
        temperature = atoi(line);
    }
}

void getHumidity() {
    FILE *file;
    char line[50];
    file = fopen("humidity.txt", "r");
    if (file!= NULL) {
        fgets(line, 50, file);
        fclose(file);
        humidity = atoi(line);
    }
}

void display() {
    printf("Temperature: %d degrees Celsius\n", temperature);
    printf("Humidity: %d%%\n", humidity);
}

//Main
int main() {
    int choice;
    do {
        printf("1. Get Temperature\n2. Get Humidity\n3. Display Temperature and Humidity\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                getTemperature();
                break;
            case 2:
                getHumidity();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (TRUE);
    return 0;
}