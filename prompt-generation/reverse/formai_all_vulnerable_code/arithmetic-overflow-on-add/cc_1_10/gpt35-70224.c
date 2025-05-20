//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Initializing global variables
int total_bags = 0, conveyer_capacity = 10, baggage_count = 0, conveyer_count = 1;
int bags_on_conveyer = 0, terminal_count = 1, time_elapsed = 0;

// Initializing functions
void new_bag();
void break_down();
void new_conveyer();
void new_terminal();
void delay(int);

int main()
{
    srand(time(NULL)); // Initializing random values

    printf("Welcome to the Airport Baggage Handling Simulation!\n\n");

    delay(1);

    printf("At this airport, there are multiple terminals, conveyer belts, and baggage breakdown stations.\n\n");

    delay(1);

    printf("Each terminal has a unique destination code, which is printed on the luggage tag.\n\n");

    delay(1);

    printf("As the bags arrive on the conveyer belt, they are sorted and redirected to the correct terminal.\n\n");

    delay(1);

    printf("Let's begin the simulation!\n\n");

    delay(1);

    while (1) // continuously running the simulation
    {
        if (bags_on_conveyer > 0) // if there are bags on the conveyer belt
        {
            for (int i = 0; i < bags_on_conveyer; i++) // looping through the bags on the conveyer
            {
                int random_num = rand() % 100 + 1; // determining a random number to simulate break downs

                if (random_num < 5) // 5% chance of breakdown
                {
                    break_down();
                    break;
                }
                else // if no breakdown
                {
                    new_bag(); // sending the bag to the correct terminal
                }
            }
        }

        if (bags_on_conveyer < conveyer_capacity) // if there is space on the conveyer belt
        {
            bags_on_conveyer++; // adding a new bag to the conveyer
            total_bags++; // increasing the total bag count
            printf("New Bag with Destination Code %d added to Conveyer Belt %d\n", (rand() % terminal_count) + 1, conveyer_count);
            delay(1);
        }

        if (total_bags >= 500) // exiting the simulation once 500 bags have been processed
        {
            printf("\n500 bags have been processed successfully! Exiting Simulation.\n");
            break;
        }

        time_elapsed++; // increasing the time elapsed

        if (time_elapsed % 5 == 0) // adding a new conveyer belt every 5 units of time
        {
            new_conveyer();
        }

        if (time_elapsed % 10 == 0) // adding a new terminal every 10 units of time
        {
            new_terminal();
        }

        delay(1); // delay between each loop
    }

    return 0;
}

void new_bag()
{
    int destination_code = rand() % terminal_count + 1;
    printf("Bag with Destination Code %d has been redirected to Terminal %d\n", destination_code, destination_code);
    delay(1);
}

void break_down()
{
    printf("Conveyer Belt %d has broken down! Please fix the issue.\n", conveyer_count);
    conveyer_capacity -= 2; // temporarily reducing the conveyer capacity
    delay(rand() % 4 + 2); // simulating the time taken to fix the issue
    conveyer_capacity += 2; // increasing the conveyer capacity back to normal
    printf("Conveyer Belt %d has been fixed and is back to normal capacity.\n", conveyer_count);
    delay(1);
}

void new_conveyer()
{
    conveyer_count++; // increasing the conveyer count
    conveyer_capacity = conveyer_count * 10; // increasing the conveyer capacity based on the conveyer count
    printf("A new Conveyer Belt has been added! Conveyer Belt %d with capacity %d\n", conveyer_count, conveyer_capacity);
    delay(1);
}

void new_terminal()
{
    terminal_count++; // increasing the terminal count
    printf("A new Terminal has been added! Terminal %d\n", terminal_count);
    delay(1);
}

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}