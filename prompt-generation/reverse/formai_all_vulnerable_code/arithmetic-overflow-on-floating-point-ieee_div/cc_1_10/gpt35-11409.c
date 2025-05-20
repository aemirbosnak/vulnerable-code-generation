//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {

    long double usage;
    char buffer[BUF_SIZE];
    FILE *fPtr;

    //Get the Process ID
    int pid = getpid();

    // Infinite loop to monitor CPU usage
    while(1) {
        //Open the file to read
        fPtr = fopen("/proc/stat", "r");

        //If the file couldn't be opened
        if(fPtr == NULL) {
            printf("Error: Unable to open the statistics file.\n");
            return 1;
        }

        //Move the file cursor to the beginning of the file
        fseek(fPtr, 0L, SEEK_SET);

        //Read CPU usage statistics
        fgets(buffer, BUF_SIZE, fPtr);

        //Close the opened file
        fclose(fPtr);

        //Parse and calculate CPU usage percentage
        char *token = strtok(buffer, " ");
        int i = 0;
        long double total_time = 0;
        while (token != NULL) {
            token = strtok(NULL, " ");
            if(i >= 1 && i <= 3) {
                total_time += atof(token);
            } else if (i == 4) {
                break;
            }
            i++;
        }
        usage = ((total_time / sysconf(_SC_CLK_TCK)) * 100.0) / (double) get_nprocs();

        //Print the CPU usage percentage
        printf("PID: %d, CPU Usage: %.2Lf%%\n", pid, usage);
        usleep(1000000); // Wait for 1 second
    }

    return 0;
}