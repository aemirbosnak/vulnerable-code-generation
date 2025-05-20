//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BAGGAGE 1000
#define MAX_TERMINALS 10

// Structure to hold information about baggage
typedef struct baggage
{
    int terminal;
    bool is_checked_in;
    bool is_processed;
} baggage;

int main()
{
    // Initialize airport terminals
    int num_terminals = 5;
    bool is_terminal_open[MAX_TERMINALS] = {true, true, true, true, true};

    // Initialize baggage list
    baggage baggage_list[MAX_BAGGAGE];

    int num_baggage = 0;

    while (true)
    {
        // Display Menu
        printf("\n\nAirport Baggage Handling Simulation Menu\n");
        printf("1. Check-In Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Open Terminal\n");
        printf("4. Close Terminal\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                // Check-In Baggage
                if (num_baggage >= MAX_BAGGAGE)
                {
                    printf("\n Baggage Limit Exceeded. Cannot add more baggage");
                    break;
                }

                printf("\n Enter Terminal Number: ");
                int terminal_num;
                scanf("%d", &terminal_num);

                if (!is_terminal_open[terminal_num - 1])
                {
                    printf("\n Terminal %d is Closed. Please choose a different terminal", terminal_num);
                    break;
                }

                // Add baggage
                baggage_list[num_baggage].terminal = terminal_num;
                baggage_list[num_baggage].is_checked_in = true;
                baggage_list[num_baggage].is_processed = false;

                num_baggage++;

                printf("\n Baggage Added Successfully!");
                break;

            case 2:
                // Process Baggage
                if (num_baggage <= 0)
                {
                    printf("\n No Baggage to Process");
                    break;
                }

                printf("\n Enter Terminal Number: ");
                int terminal;
                scanf("%d", &terminal);

                if (!is_terminal_open[terminal - 1])
                {
                    printf("\n Terminal %d is Closed. Please choose a different terminal", terminal);
                    break;
                }

                for (int i = 0; i < num_baggage; i++)
                {
                    if (baggage_list[i].terminal == terminal && baggage_list[i].is_checked_in && !baggage_list[i].is_processed)
                    {
                        baggage_list[i].is_processed = true;
                        printf("\n Baggage Processed Successfully!");
                        break;
                    }
                }
                break;

            case 3:
                // Open Terminal
                printf("\n Enter Terminal Number: ");
                int terminal_to_open;
                scanf("%d", &terminal_to_open);

                if (terminal_to_open > 0 && terminal_to_open <= num_terminals)
                {
                    is_terminal_open[terminal_to_open - 1] = true;
                    printf("\n Terminal %d Opened Successfully!", terminal_to_open);
                }
                else
                    printf("\n Invalid Terminal Number!");
                
                break;

            case 4:
                // Close Terminal
                printf("\n Enter Terminal Number: ");
                int terminal_to_close;
                scanf("%d", &terminal_to_close);

                if (terminal_to_close > 0 && terminal_to_close <= num_terminals)
                {
                    is_terminal_open[terminal_to_close - 1] = false;
                    printf("\n Terminal %d Closed Successfully!", terminal_to_close);
                }
                else
                    printf("\n Invalid Terminal Number!");
                
                break;

            case 5:
                // Exit
                printf("\n Exiting Program. Goodbye!\n");
                exit(0);

            default:
                printf("\n Invalid Choice. Please Try Again");
                break;
        }
    }
    
    return 0;
}