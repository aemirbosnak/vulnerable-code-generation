//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char* stat = "/proc/stat"; // path to the system proc file
    const int interval_seconds = 1; // monitoring interval
    const int length_command = 50; // maximum length of a command name
    FILE* proc_file = NULL;
    int total_cpu_ticks[2][10] = {0}; // store the ticks for two different readings
    char command[100]; // variable to store the command name of the process
    int pid = 0; // process id 
    int user_mode = 0;
    int nice_mode = 0;
    int system_mode = 0;
    int idle_mode = 0;
    int total_mode = 0;

    // clear the screen
    system("clear");

    // display header
    printf("%-10s  %9s %9s %9s %9s %9s\n", "PID", "%USER", "%NICE", "%SYSTEM", "%IDLE", "%TOTAL");

    while (1) {
        // clear the terminal
        printf("\033[2J\033[H");

        // open the proc file
        proc_file = fopen(stat, "r");

        // read the first line
        fgets(command, length_command, proc_file);

        // read each line individually
        while (strncmp(command, "cpu ", 4) != 0) {
            fscanf(proc_file, "%s", command);
        }

        // read the CPU ticks for user, nice, system and idle modes
        fscanf(proc_file, "%d %d %d %d", &total_cpu_ticks[0][0], &total_cpu_ticks[0][1], &total_cpu_ticks[0][2], &total_cpu_ticks[0][3]);

        // close the proc file
        fclose(proc_file);

        // wait for the specified interval
        sleep(interval_seconds);

        // open the proc file again
        proc_file = fopen(stat, "r");

        // read the first line
        fgets(command, length_command, proc_file);

        // read each line individually
        while (strncmp(command, "cpu ", 4) != 0) {
            fscanf(proc_file, "%s", command);
        }

        // read the CPU ticks for user, nice, system and idle modes
        fscanf(proc_file, "%d %d %d %d", &total_cpu_ticks[1][0], &total_cpu_ticks[1][1], &total_cpu_ticks[1][2], &total_cpu_ticks[1][3]);

        // close the proc file
        fclose(proc_file);

        // loop through all processes in the system
        for (pid = 0; pid < 32768; pid++) {
            // construct the file name
            sprintf(command, "/proc/%d/stat", pid);

            // open the process stat file
            proc_file = fopen(command, "r");

            // break if the file does not exist
            if (proc_file == NULL) {
                continue;
            }

            // read the command name
            fscanf(proc_file, "%d (%[^)]s", &pid, command);

            // read the CPU times for user, system and nice modes
            fscanf(proc_file, "%*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %d %d %d", &user_mode, &system_mode, &nice_mode);

            // calculate the total CPU time for the process
            total_mode = user_mode + nice_mode + system_mode;

            // close the process stat file
            fclose(proc_file);

            // calculate the CPU usage percentage
            float cpu_percent = ((float) total_mode / (total_cpu_ticks[1][0] + total_cpu_ticks[1][1] + total_cpu_ticks[1][2] + total_cpu_ticks[1][3] - total_cpu_ticks[0][0] - total_cpu_ticks[0][1] - total_cpu_ticks[0][2] - total_cpu_ticks[0][3])) * 100;

            // display the CPU usage percentage
            printf("%-10d  %8.2f%% %8.2f%% %8.2f%% %8.2f%% %8.2f%%\n", pid, cpu_percent, ((float)nice_mode/total_mode)*100, ((float)system_mode/total_mode)*100, ((float)idle_mode/total_mode)*100, 100 - cpu_percent);
        }
    }

    return 0;
}