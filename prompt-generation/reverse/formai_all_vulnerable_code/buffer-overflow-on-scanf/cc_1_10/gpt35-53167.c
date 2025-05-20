//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
/*
* Project Name: Cryptic Time Travel Simulator
* Description: This program simulates time travel in cryptic style where you enter the source and destination time.
* Some rules apply for time travel such as the max year is 2999 and the min year is 1. The time travel can't go beyond 
* the current year of execution of this program. 
* Author: CrypticBot
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_YEAR 1
#define MAX_YEAR 2999

//Function to generate a cryptic time
int generate_cryptic_time(int min_year, int max_year) {
    srand(time(NULL));
    int years = (rand() % (max_year - min_year + 1)) + min_year;
    int months = (rand() % 12) + 1;
    int days = (rand() % 30) + 1;
    int hours = (rand() % 24);
    int minutes = (rand() % 60);
    int seconds = (rand() % 60);
    int cryptic_time = (years * 10000000000) + (months * 100000000) + (days * 1000000) + (hours * 10000) + (minutes * 100) + seconds;
    return cryptic_time;
}

//Function to validate year
int validate_year(int year) {
    if (year < MIN_YEAR || year > MAX_YEAR) {
        printf("Invalid year. The year should be between %d and %d.\n", MIN_YEAR, MAX_YEAR);
        return 0;
    } else if(year > 2022) {
        printf("Time travel can't go beyond the current year.\n");
        return 0;
    } else {
        return 1;
    }
}

//Main function
int main() {
    int source_year, destination_year, source_time, destination_time;
    printf("Welcome to the Cryptic Time Travel Simulator!\n");
    printf("Enter the source year (between %d-%d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &source_year);
    if(!validate_year(source_year)) {
        return 0;
    }
    printf("Enter the destination year (between %d-%d): ", MIN_YEAR, MAX_YEAR);
    scanf("%d", &destination_year);
    if(!validate_year(destination_year)) {
        return 0;
    }
    source_time = generate_cryptic_time(source_year, MAX_YEAR);
    destination_time = generate_cryptic_time(destination_year, MAX_YEAR);
    printf("\n\nWe are now initiating time travel from %d to %d...\n\n", source_time, destination_time);
    printf("Connection Established! Preparing to travel...\n");
    for (int i = 10; i >= 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("\nYou have arrived at your destination time %d safely. Enjoy your time travel experience.\n", destination_time);
    return 0;
}