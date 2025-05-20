//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: paranoid
#include <stdio.h>
#include <time.h>

int main()
{
    char user_input;
    time_t curr_time;
    struct tm *time_info;
    char time_string[50];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Type 'y' to start, or any other key to exit: ");
    scanf("%c", &user_input);

    if (user_input == 'y' || user_input == 'Y') {
        printf("You have just activated the Time Travel Simulator!\n");
        printf("Enter a year to travel to (must be between 1900 and 2100): ");
        int year;
        scanf("%d", &year);

        if (year < 1900 || year > 2100) {
            printf("Invalid year entered. Goodbye!\n");
            return 0;
        }

        curr_time = time(NULL);
        time_info = localtime(&curr_time);
        strftime(time_string, sizeof(time_string), "%Y", time_info);
        int curr_year = atoi(time_string);

        if (year > curr_year) {
            printf("Travelling to the future...\n");
        } else if (year < curr_year) {
            printf("Travelling to the past...\n");
        } else {
            printf("You are already in the year %d! Goodbye!\n", year);
            return 0;
        }

        printf("Time travel successful! You are now in the year %d.\n", year);

        printf("You notice that things are a little different than what you're used to...\n");
        printf("Do you want to investigate further? (y/n): ");
        scanf(" %c", &user_input);

        if (user_input == 'y' || user_input == 'Y') {
            printf("As you explore your surroundings, you begin to feel paranoid...\n");

            // some paranoid actions, like looking for hidden cameras and microphones

            int i;
            for (i=0; i<10; i++) {
                printf("Searching for hidden cameras and microphones...%d%% complete\n", i*10);
            }

            printf("Everything seems to be clear, but you still feel uneasy... \n");
            printf("Do you want to time travel again? (y/n): ");
            scanf(" %c", &user_input);

            if (user_input == 'y' || user_input == 'Y') {
                main();  // restart the program to time travel again
            } else {
                printf("Goodbye!\n");
                return 0;
            }

        } else {
            printf("Goodbye!\n");
            return 0;
        }

    } else {
        printf("Goodbye!\n");
        return 0;
    }

    return 0;
}