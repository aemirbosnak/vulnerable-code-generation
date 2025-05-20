//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed the random generator with time
    
    char input;
    
    printf("Welcome to the Automated Fortune Teller.\n");
    printf("Ask a yes or no question and receive your fortune!\n");
    
    do {
        printf("\nAsk your question (type 'quit' to end): ");
        scanf("%s", &input);
        
        // check if user wants to quit
        if (strcmp(input, "quit") == 0) {
            break;
        }
        
        // generate random number
        int random_number = rand() % 10 + 1;
        
        // give fortune based on random number
        switch (random_number) {
            case 1:
                printf("\nIt is certain.\n");
                break;
            case 2:
                printf("\nIt is decidedly so.\n");
                break;
            case 3:
                printf("\nWithout a doubt.\n");
                break;
            case 4:
                printf("\nYes - definitely.\n");
                break;
            case 5:
                printf("\nYou may rely on it.\n");
                break;
            case 6:
                printf("\nAs I see it, yes.\n");
                break;
            case 7:
                printf("\nMost likely.\n");
                break;
            case 8:
                printf("\nOutlook good.\n");
                break;
            case 9:
                printf("\nYes.\n");
                break;
            case 10:
                printf("\nSigns point to yes.\n");
                break;
            default:
                printf("\nError: Invalid random number.\n");
                break;
        }
        
    } while (strcmp(input, "quit") != 0);
    
    printf("\nThank you for using the Automated Fortune Teller.\n");
    
    return 0;
}