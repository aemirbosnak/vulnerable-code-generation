//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the time machine's clock to 1970
    time_t timeMachine = 0;
    struct tm* timeInfo;
    char buffer[80];
    
    // Welcome message
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Let's travel to a random date in the past!\n\n");
    
    // Randomly generate a year between 0 and 70 (1970 - 2040)
    srand(time(NULL));
    int randomYear = rand() % 71; // 0 to 70
    
    // Set the year of the time machine's clock to the random year
    timeMachine += randomYear * 31536000; // 1 year = 31,536,000 sec
    
    // Randomly generate a month between 1 and 12
    int randomMonth = rand() % 12 + 1;
    
    // Set the month of the time machine's clock to the random month
    timeInfo = localtime(&timeMachine);
    timeInfo->tm_mon = randomMonth - 1; // tm_mon is 0 to 11
    
    // Randomly generate a day between 1 and 31
    int randomDay = rand() % 31 + 1;
    
    // Set the day of the time machine's clock to the random day
    timeInfo->tm_mday = randomDay;
    
    // Convert the time machine's clock to a string in the format "YYYY-MM-DD"
    strftime(buffer, 80, "%Y-%m-%d", timeInfo);
    
    // Display the randomly generated date
    printf("Traveling to: %s\n\n", buffer);
    
    // Delay for dramatic effect
    printf("Initializing time travel sequence...\n");
    for (int i = 0; i < 5; i++) {
        printf("...");
        fflush(stdout); // flush buffer to display dots immediately
        sleep(1); // sleep for 1 sec
    }
    printf("\n\n");
    
    // Display the current date and time in the format "YYYY-MM-DD hh:mm:ss"
    time_t currentTime = time(NULL);
    timeInfo = localtime(&currentTime);
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeInfo);
    printf("You have arrived in the past!\n");
    printf("Current date and time: %s\n\n", buffer);
    
    // Goodbye message
    printf("Thank you for using the Time Travel Simulator!\n");
    return 0;
}