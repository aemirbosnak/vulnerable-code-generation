//FormAI DATASET v1.0 Category: Task Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

void task1()
{
    printf("Task 1: ");
    time_t current_time = time(NULL);
    printf("%s\n", ctime(&current_time));
}

void task2()
{
    printf("Task 2: ");
    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (file_descriptor < 0)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    char buffer[256];
    time_t current_time = time(NULL);
    sprintf(buffer, "%s", ctime(&current_time));
    write(file_descriptor, buffer, sizeof(buffer));
    close(file_descriptor);
}

int main()
{
    // Define schedule
    struct tm task1_time = {0, 0, 9, 15, 6, 121}; // 9:00am, 7th June 2021
    struct tm task2_time = {0, 0, 15, 15, 6, 121}; // 3:00pm, 7th June 2021

    // Set timer for task 1
    time_t task1_timer = mktime(&task1_time);
    if (task1_timer == -1)
    {
        perror("Unable to set task 1 timer");
        exit(EXIT_FAILURE);
    }

    // Set timer for task 2
    time_t task2_timer = mktime(&task2_time);
    if (task2_timer == -1)
    {
        perror("Unable to set task 2 timer");
        exit(EXIT_FAILURE);
    }

    // Start scheduler loop
    while (1)
    {
        time_t current_time = time(NULL);

        // Check if it's time for task 1
        if (current_time >= task1_timer)
        {
            task1();
            // Update timer for next task 1 run
            task1_timer += 24 * 60 * 60; // 1 day in seconds
        }

        // Check if it's time for task 2
        if (current_time >= task2_timer)
        {
            task2();
            // Update timer for next task 2 run
            task2_timer += 24 * 60 * 60; // 1 day in seconds
        }

        // Wait for 1 second before checking again
        sleep(1);
    }

    return 0;
}