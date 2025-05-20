//MISTRAL-7B DATASET v1.0 Category: Fitness Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
} birthday;

typedef struct {
    double steps;
    double calories;
    birthday bday;
} fitness_data;

void print_header() {
    printf("\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n");
    printf("//               C Fitness Tracker               //\n");
    printf("//                                            //\n");
    printf("//     A simple program to track daily steps    //\n");
    printf("//          and calculate calories burned      //\n");
    printf("//                                            //\n");
    printf("//     Copyright (C) 2022 Christopher J. Madsen  //\n");
    printf("//                                            //\n");
    printf("//     This program is free software; you can   //\n");
    printf("//     redistribute it and/or modify it under  //\n");
    printf("//     the terms of the GNU General Public License  //\n");
    printf("//     as published by the Free Software Foundation;  //\n");
    printf("//     either version 3 of the License, or (at your option) //\n");
    printf("//     any later version.                        //\n");
    printf("//                                            //\n");
    printf("//     This program is distributed in the hope  //\n");
    printf("//     that it will be useful, but WITHOUT ANY  //\n");
    printf("//     WARRANTY; without even the implied warranty //\n");
    printf("//     of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  //\n");
    printf("//     See the GNU General Public License for more details.   //\n");
    printf("//                                            //\n");
    printf("//     You should have received a copy of the GNU General Public License  //\n");
    printf("//     along with this program. If not, see <https://www.gnu.org/licenses/>  //\n");
    printf("//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n\n");
}

void print_data(fitness_data data) {
    printf("Steps: %llu\n", (unsigned long long) data.steps);
    printf("Calories: %.2f\n", data.calories);
    printf("Birthday: %d-%d-%d\n", data.bday.year, data.bday.month, data.bday.day);
}

void update_data(fitness_data *data, double new_steps, double new_calories) {
    data->steps += new_steps;
    data->calories += new_calories;
}

int main() {
    clock_t start_time, current_time;
    double elapsed_seconds;
    double steps_per_day = 5000.0;
    double calories_per_step = 0.17;
    fitness_data data = {.steps = 0.0, .calories = 0.0, .bday = {.year = 1990, .month = 1, .day = 1}};

    print_header();

    start_time = clock();

    while (1) {
        current_time = clock();
        elapsed_seconds = (double) (current_time - start_time) / CLOCKS_PER_SEC;

        if (elapsed_seconds >= 86400.0) { // One day has passed
            printf("\nNew Day: %d-%d-%d\n", data.bday.year, data.bday.month, data.bday.day + 1);
            data.steps = 0.0;
            data.calories = 0.0;
        }

        if (data.steps >= steps_per_day) {
            printf("\nYou reached your daily goal of %llu steps!\n", (unsigned long long) steps_per_day);
            double total_calories = data.calories + (data.steps * calories_per_step);
            printf("Total calories burned this day: %.2f\n", total_calories);
            print_data(data);
            data.steps = 0.0;
            data.calories = 0.0;
        }

        printf("Enter steps for today: ");
        double steps;
        scanf("%lf", &steps);
        update_data(&data, steps, steps * calories_per_step);
    }

    return EXIT_SUCCESS;
}