//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: mathematical
#include <stdio.h>
#include <time.h>

int main()
{
    int num_of_fortunes = 10; // number of possible fortunes
    int month, day, sum;
    time_t now;
    time(&now);

    struct tm *local = localtime(&now); // get local time
    month = local->tm_mon + 1; // get current month
    day = local->tm_mday; // get current day

    sum = month + day; // calculate sum of month and day

    // generate random number based on sum
    srand(sum);
    int fortune_num = rand() % num_of_fortunes + 1;

    // display fortune based on random number
    switch(fortune_num)
    {
        case 1:
            printf("You will have a very lucky day today.\n");
            break;

        case 2:
            printf("You will have a great week ahead.\n");
            break;

        case 3:
            printf("You will receive good news soon.\n");
            break;

        case 4:
            printf("You will make a new friend today.\n");
            break;

        case 5:
            printf("You will discover a hidden talent within yourself.\n");
            break;

        case 6:
            printf("You will find a solution to a problem that has been bothering you.\n");
            break;

        case 7:
            printf("You will receive a gift from someone special.\n");
            break;

        case 8:
            printf("You will have a satisfying dinner tonight.\n");
            break;

        case 9:
            printf("You will have a peaceful and restful sleep tonight.\n");
            break;

        case 10:
            printf("You will have an unexpected adventure today.\n");
            break;

        default:
            printf("Error: Invalid fortune number.\n");
            break;
    }

    return 0;
}