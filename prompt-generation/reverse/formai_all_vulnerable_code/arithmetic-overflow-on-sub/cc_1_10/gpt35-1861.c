//FormAI DATASET v1.0 Category: Temperature monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

// function to read temperature
double read_temperature() {
    // generate random temperature with floating point precision
    double temp = (double)(rand() % 100)/2.0 + 10.0;
    return temp;
}

// callback function to process the temperature reading
void temp_callback(double temp) {
    // print the temperature asynchronously
    printf("Temperature: %.2f C\n", temp);
}

// function to simulate asynchronous temperature monitoring
void monitor_temperature() {
    bool is_running = true;
    time_t start_time;
    double temp;
    
    // record the start time
    start_time = time(NULL);
    
    // monitor temperature for 30 seconds
    while(is_running) {
        // read the temperature asynchronously every 2 seconds
        temp = read_temperature();
        temp_callback(temp);
        sleep(2);
        
        // check if 30 seconds have passed
        if(time(NULL) - start_time >= 30) {
            is_running = false;
        }
    }
}

// main function to run the program
int main() {
    srand(time(0));
    
    // run the temperature monitor asynchronously
    monitor_temperature();
    
    return 0;
}