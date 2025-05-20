//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to print a welcome message
void welcome_message() {
    printf("Welcome to the Time Travel Simulator!\n");
    printf("This program will demonstrate the power of time travel technology.\n\n");
}

// function to get user's date of birth
void get_dob(int *dob) {
    printf("Please enter your date of birth (dd-mm-yyyy): ");
    scanf("%d-%d-%d", &dob[0], &dob[1], &dob[2]);
    printf("\n");
}

// function to simulate the time travel
void time_travel(int *dob) {
    // get the current time
    time_t current_time = time(NULL);
    struct tm *timeinfo = localtime(&current_time);

    // display the current time
    printf("Current time: %02d-%02d-%04d %02d:%02d:%02d.\n",
           timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
           timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    // calculate the user's age
    int age = timeinfo->tm_year + 1900 - dob[2];

    // check if the user's birthday has passed this year
    if (timeinfo->tm_mon + 1 > dob[1] || (timeinfo->tm_mon + 1 == dob[1] && timeinfo->tm_mday >= dob[0])) {
        age--;
    }

    // display the user's age
    printf("You are %d years old.\n\n", age);

    // simulate time travel to the user's birth year
    printf("Welcome to the year %04d!\n", dob[2]);

    // wait for a moment before continuing
    sleep(1);

    // simulate the user's birth
    printf("You were born on %02d-%02d-%04d at %02d:%02d:%02d.\n\n",
           dob[0], dob[1], dob[2],
           rand()%24, rand()%60, rand()%60);

    // wait for another moment before continuing
    sleep(1);

    // simulate some major events in history
    printf("Some major events in this year:\n");

    if (dob[2] == 1969) {
        printf("- Neil Armstrong becomes the first person to walk on the moon.\n");
    } else if (dob[2] == 1989) {
        printf("- The Berlin Wall falls.\n");
    } else if (dob[2] == 2001) {
        printf("- The September 11 attacks take place.\n");
    } else if (dob[2] == 2020) {
        printf("- The COVID-19 pandemic begins.\n");
    } else {
        printf("- Nothing significant happened in this year.\n");
    }

    // wait for a moment before continuing
    sleep(1);

    // simulate time travel back to the current time
    printf("\nWelcome back to the present day!\n");

    // wait for a moment before ending the program
    sleep(1);

    printf("Thank you for using the Time Travel Simulator!\n");
}

int main() {
    int dob[3]; // array to store user's date of birth

    welcome_message();
    get_dob(dob);
    time_travel(dob);

    return 0;
}