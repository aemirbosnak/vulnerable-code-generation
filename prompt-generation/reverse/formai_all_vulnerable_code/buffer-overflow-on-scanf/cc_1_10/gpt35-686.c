//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 1000
#define FEEDER_CAPACITY 120
#define SORTER_CAPACITY 400
#define MAX_TIME 10 // time limit for the simulation

int baggage_tray[FEEDER_CAPACITY]; // array for baggage feeding tray
int sorter_queue[SORTER_CAPACITY]; // queue for sorter conveyor belt
int bags_checked_in = 0; // counter for number of bags checked in
int bags_processed = 0; // counter for number of bags processed
int bags_lost = 0; // counter for number of misplaced bags
int time_elapsed = 0; // counter for time elapsed

void reset_tray()
{
    for (int i = 0; i < FEEDER_CAPACITY; i++)
    {
        baggage_tray[i] = 0;
    }
}

bool is_full(int *arr, int capacity)
{
    int count = 0;
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] != 0)
        {
            count++;
        }
    }
    if (count == capacity)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_empty(int *arr, int capacity)
{
    for (int i = 0; i < capacity; i++)
    {
        if (arr[i] != 0)
        {
            return false;
        }
    }
    return true;
}

void feed_baggage()
{
    if (is_full(baggage_tray, FEEDER_CAPACITY))
    {
        printf("Feeder is full. Waiting for bags to be processed...\n");
        return;
    }
    int bags_to_add = rand() % 50 + 1; // random number of bags between 1 and 50
    for (int i = 0; i < bags_to_add; i++)
    {
        if (!is_full(baggage_tray, FEEDER_CAPACITY))
        {
            int index;
            do
            {
                index = rand() % FEEDER_CAPACITY; // random index between 0 and capacity-1
            } while (baggage_tray[index] != 0); // check if index is empty
            baggage_tray[index] = bags_checked_in + 1; // assign bag ID and increment counter
            bags_checked_in++;
        }
        else
        {
            printf("Feeder is full. Waiting for bags to be processed...\n");
            return;
        }
    }
    printf("Added %d bags to the feeder.\n", bags_to_add);
}

void process_baggage()
{
    if (is_empty(baggage_tray, FEEDER_CAPACITY))
    {
        printf("Feeder is empty. Nothing to process...\n");
        return;
    }
    int bags_to_process = rand() % 30 + 1; // random number of bags between 1 and 30
    for (int i = 0; i < bags_to_process; i++)
    {
        if (!is_empty(baggage_tray, FEEDER_CAPACITY))
        {
            int index;
            do
            {
                index = rand() % FEEDER_CAPACITY; // random index between 0 and capacity-1
            } while (baggage_tray[index] == 0); // check if index is not empty
            if (!is_full(sorter_queue, SORTER_CAPACITY))
            {
                sorter_queue[bags_processed] = baggage_tray[index]; // transfer bag to sorter queue
                baggage_tray[index] = 0; // remove bag from feeder tray
                bags_processed++;
            }
            else
            {
                printf("Sorter queue is full. Bag lost...\n");
                baggage_tray[index] = 0; // remove bag from feeder tray
                bags_lost++;
            }
        }
        else
        {
            printf("Feeder is empty. Nothing to process...\n");
            return;
        }
    }
    printf("Processed %d bags from the feeder.\n", bags_to_process);
}

void sort_baggage()
{
    if (is_empty(sorter_queue, SORTER_CAPACITY))
    {
        printf("Sorter queue is empty. Nothing to sort...\n");
        return;
    }
    int bags_to_sort = rand() % 20 + 1; // random number of bags between 1 and 20
    for (int i = 0; i < bags_to_sort; i++)
    {
        if (!is_empty(sorter_queue, SORTER_CAPACITY))
        {
            int index = rand() % SORTER_CAPACITY; // random index between 0 and capacity-1
            if (sorter_queue[index] <= bags_processed)
            {
                sorter_queue[index] = 0; // remove bag from sorter queue
            }
            else
            {
                printf("Bag %d sent to wrong destination...\n", sorter_queue[index]);
                sorter_queue[index] = 0; // remove bag from sorter queue
                bags_lost++;
            }
        }
        else
        {
            printf("Sorter queue is empty. Nothing to sort...\n");
            return;
        }
    }
    printf("Sorted %d bags from the sorter queue.\n", bags_to_sort);
}

int main()
{
    srand(time(NULL)); // seed random number generator
    printf("Welcome to the baggage handling simulation!\n\n");
    while (time_elapsed < MAX_TIME)
    {
        printf("Time elapsed: %d\n\n", time_elapsed);
        printf("What would you like to do?\n");
        printf("1. Add baggage to feeder tray\n");
        printf("2. Process baggage from feeder tray to sorter queue\n");
        printf("3. Sort baggage from sorter queue to airplane\n");
        printf("4. Quit simulation\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                feed_baggage();
                break;
            case 2:
                process_baggage();
                break;
            case 3:
                sort_baggage();
                break;
            case 4:
                printf("Ending simulation...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        printf("\n");
        time_elapsed++;
        if (time_elapsed == MAX_TIME)
        {
            printf("Time limit reached. Ending simulation...\n");
        }
    }
    return 0;
}