//FormAI DATASET v1.0 Category: Date and time ; Style: recursive
#include <stdio.h>
#include <time.h>

void print_time(int);
void print_date(int);

int main()
{
    int choice;

    do
    {
        printf("Enter the option:\n1. Print Time\n2. Print Date\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                print_time(1);
                printf("\n\n");
                break;
            case 2:
                print_date(1);
                printf("\n\n");
                break;
            case 3:
                printf("Exiting...........");
                break;
            default:
                printf("Wrong choice entered!\nPlease enter the correct choice!\n\n");
                break;
        }
        
    } while (choice != 3);
    
    return 0;
}

void print_time(int count)
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%I:%M:%S %p",timeinfo);
    printf("%s",buffer);

    if(count < 10)
    {
        printf("\n");
        print_time(count+1);
    }
}

void print_date(int count)
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y",timeinfo);
    printf("%s",buffer);

    if(count < 10)
    {
        printf("\n");
        print_date(count+1);
    }
}