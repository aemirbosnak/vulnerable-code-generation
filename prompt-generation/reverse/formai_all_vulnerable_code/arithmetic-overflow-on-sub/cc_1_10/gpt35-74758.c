//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TEST_DURATION 10 // seconds

int main() {
    char buffer[BUFFER_SIZE];
    time_t start_time, end_time;
    int total_bytes = 0;
    double speed;
    FILE *file;
    
    printf("Starting internet speed test...\n");
    
    // open file for writing
    file = fopen("speed_test.txt", "w");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // get start time
    start_time = time(NULL);
    
    // download data for TEST_DURATION seconds
    while (time(NULL) - start_time < TEST_DURATION) {
        system("curl -s https://speedtest.free.net.pk/10MB.zip -o /dev/null");
        total_bytes += BUFFER_SIZE;
        usleep(100000); // sleep for 100ms to avoid CPU being fully utilized
    }
    
    // get end time
    end_time = time(NULL);
    
    // calculate speed
    speed = (double)total_bytes / (end_time - start_time) / 1024 / 1024 * 8;
    
    // write results to file
    fprintf(file, "Start Time: %s", ctime(&start_time));
    fprintf(file, "End Time: %s", ctime(&end_time));
    fprintf(file, "Total Bytes Downloaded: %d\n", total_bytes);
    fprintf(file, "Average Download Speed: %.2f Mbps\n", speed);
    
    // close file
    fclose(file);
    
    printf("Internet speed test completed successfully.\n");
    
    return 0;
}