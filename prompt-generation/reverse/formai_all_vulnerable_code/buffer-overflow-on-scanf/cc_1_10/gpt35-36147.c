//FormAI DATASET v1.0 Category: Temperature monitor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

//Prototypes
void printLogo();
void printMenu();
void temperatureMonitor(int* temp, int size);

int main() {
    printLogo();

    int temp[24];
    char input[10];
    bool quit = false;
    bool validInput = false;

    //Main loop
    while (!quit) {
        printMenu();
        scanf("%s", input);

        //Input validation loop
        while (!validInput) {
            if (input[0] == 'a' || input[0] == 'A') {
                //Time seeding for RNG
                srand(time(NULL));

                //Populating temperature array with random values between 0 and 100
                for (int i = 0; i < 24; i++) {
                    temp[i] = rand() % 101;
                }

                printf("\nTemperature data has been simulated!\n\n");
                validInput = true;
            }
            else if (input[0] == 'm' || input[0] == 'M') {
                if (temp[0] != '\0') {
                    temperatureMonitor(temp, 24);
                    validInput = true;
                }
                else {
                    printf("\nPlease enter temperature data first!\n");
                    validInput = true;
                }
            }
            else if (input[0] == 'q' || input[0] == 'Q') {
                quit = true;
                validInput = true;
            }
            else {
                printf("\nInvalid input, please try again.\n");
                scanf("%s", input);
            }
        }
        validInput = false;
    }

    return 0;
}

void printLogo() {
    printf(" _   _          _ _       _      _            \n");
    printf("| | | |        | (_)     (_)    | |           \n");
    printf("| |_| |__   ___| |_ _ __  _  ___| | __ _ _ __ \n");
    printf("| __| '_ \\ / _ \\ | | '_ \\| |/ _ \\ |/ _` | '__|\n");
    printf("| |_| | | |  __/ | | | | | |  __/ | (_| | |   \n");
    printf(" \\__|_| |_|\\___|_|_|_| |_|_|\\___|_|\\__,_|_|   \n\n");
}

void printMenu() {
    printf("Please select an option:\n");
    printf("A) Enter random temperature data\n");
    printf("M) Monitor temperature data\n");
    printf("Q) Quit program\n\n");
}

void temperatureMonitor(int* temp, int size) {
    int counter[10] = { 0 };
    int total = 0;
    float average;

    //Looping through temperature array and sorting into counters based on temperature range
    for (int i = 0; i < size; i++) {
        if (temp[i] >= 0 && temp[i] <= 9) {
            counter[0]++;
            total += temp[i];
        }
        else if (temp[i] >= 10 && temp[i] <= 19) {
            counter[1]++;
            total += temp[i];
        }
        else if (temp[i] >= 20 && temp[i] <= 29) {
            counter[2]++;
            total += temp[i];
        }
        else if (temp[i] >= 30 && temp[i] <= 39) {
            counter[3]++;
            total += temp[i];
        }
        else if (temp[i] >= 40 && temp[i] <= 49) {
            counter[4]++;
            total += temp[i];
        }
        else if (temp[i] >= 50 && temp[i] <= 59) {
            counter[5]++;
            total += temp[i];
        }
        else if (temp[i] >= 60 && temp[i] <= 69) {
            counter[6]++;
            total += temp[i];
        }
        else if (temp[i] >= 70 && temp[i] <= 79) {
            counter[7]++;
            total += temp[i];
        }
        else if (temp[i] >= 80 && temp[i] <= 89) {
            counter[8]++;
            total += temp[i];
        }
        else if (temp[i] >= 90 && temp[i] <= 100) {
            counter[9]++;
            total += temp[i];
        }
    }

    //Calculating and displaying average temperature
    average = (float)total / size;
    printf("\nAverage temperature: %.2f\n\n", average);

    //Displaying temperature counters
    printf("Temperatures:\n");
    printf("0-9   : %d\n", counter[0]);
    printf("10-19 : %d\n", counter[1]);
    printf("20-29 : %d\n", counter[2]);
    printf("30-39 : %d\n", counter[3]);
    printf("40-49 : %d\n", counter[4]);
    printf("50-59 : %d\n", counter[5]);
    printf("60-69 : %d\n", counter[6]);
    printf("70-79 : %d\n", counter[7]);
    printf("80-89 : %d\n", counter[8]);
    printf("90-100: %d\n\n", counter[9]);
}