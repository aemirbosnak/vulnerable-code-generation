//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate random number
int random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;
    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }
    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

//Function to display the traffic signal
void display_signal(int signal) {
    if (signal == 1) {
        printf("\n\n------------------\n");
        printf("|     RED        |\n");
        printf("------------------\n");
    } else if (signal == 2) {
        printf("\n\n------------------\n");
        printf("|     YELLOW     |\n");
        printf("------------------\n");
    } else {
        printf("\n\n------------------\n");
        printf("|     GREEN      |\n");
        printf("------------------\n");
    }
}

//Main function
int main() {
    int signal = 1;
    while (1) {
        display_signal(signal);
        printf("\nPlease press '1' to switch traffic signal or '0' to exit: ");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            if (signal == 1)
                signal = 2; //Change signal to YELLOW
            else if (signal == 2)
                signal = 3; //Change signal to GREEN
            else
                signal = 1; //Change signal to RED
        } else if (choice == 0) {
            break;
        } else {
            printf("\nInvalid choice. Please try again.");
        }
        //Pause for 2 seconds before changing signal
        int wait_time = random_number(1, 5);
        printf("\nPlease wait for %d seconds...", wait_time);
        for (int i = 0; i < wait_time; i++) {
            printf(".");
            sleep(1);
        }
    }
    return 0;
}