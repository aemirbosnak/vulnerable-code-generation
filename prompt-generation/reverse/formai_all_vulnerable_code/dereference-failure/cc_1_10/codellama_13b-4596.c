//Code Llama-13B DATASET v1.0 Category: Time Travel Simulator ; Style: happy
// Time Travel Simulator
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global variables
int year;
int month;
int day;
int hour;
int minute;
int second;

// Function to set the current time
void set_time() {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    year = current_time->tm_year + 1900;
    month = current_time->tm_mon + 1;
    day = current_time->tm_mday;
    hour = current_time->tm_hour;
    minute = current_time->tm_min;
    second = current_time->tm_sec;
}

// Function to display the current time
void display_time() {
    printf("The current time is: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);
}

// Function to set the time to a specific year
void set_year(int new_year) {
    year = new_year;
}

// Function to set the time to a specific month
void set_month(int new_month) {
    month = new_month;
}

// Function to set the time to a specific day
void set_day(int new_day) {
    day = new_day;
}

// Function to set the time to a specific hour
void set_hour(int new_hour) {
    hour = new_hour;
}

// Function to set the time to a specific minute
void set_minute(int new_minute) {
    minute = new_minute;
}

// Function to set the time to a specific second
void set_second(int new_second) {
    second = new_second;
}

// Function to travel back in time
void travel_back() {
    year--;
    month--;
    day--;
    hour--;
    minute--;
    second--;
}

// Function to travel forward in time
void travel_forward() {
    year++;
    month++;
    day++;
    hour++;
    minute++;
    second++;
}

// Function to display the time after traveling back in time
void display_time_back() {
    printf("The time after traveling back is: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);
}

// Function to display the time after traveling forward in time
void display_time_forward() {
    printf("The time after traveling forward is: %d-%d-%d %d:%d:%d\n", year, month, day, hour, minute, second);
}

int main() {
    set_time();
    display_time();
    set_year(2020);
    set_month(1);
    set_day(1);
    set_hour(12);
    set_minute(0);
    set_second(0);
    display_time();
    travel_back();
    display_time_back();
    travel_forward();
    display_time_forward();
    return 0;
}