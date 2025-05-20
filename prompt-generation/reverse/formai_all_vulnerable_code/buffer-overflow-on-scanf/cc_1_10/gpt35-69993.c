//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to display current available slots
void display_slots(int slots[], int size)
{
    printf("Available Slots: ");
    for(int i=0;i<size;i++)
    {
        if(slots[i]==1)
        {
            printf("%d ",i+1);
        }
    }
    printf("\n");
}

//function to reschedule an appointment
void reschedule(int slots[], int size)
{
    int choice;
    printf("Enter the slot number to reschedule: ");
    scanf("%d",&choice);
    if(slots[choice-1]==0)
    {
        printf("This slot is not available\n");
        return;
    }
    printf("Enter the new slot number: ");
    int new_slot;
    scanf("%d",&new_slot);
    if(slots[new_slot-1]==1)
    {
        printf("This slot is not available\n");
        return;
    }
    slots[choice-1]=0;
    slots[new_slot-1]=1;
    printf("Slot rescheduled successfully!\n");
}

int main()
{
    int slots[10]={1,1,1,1,1,1,1,1,1,1}; //initialize all slots as available
    int choice;
    printf("Welcome to the post-apocalyptic appointment scheduler!\n");
    while(1)
    {
        printf("\n");
        printf("1. Book an appointment\n");
        printf("2. Reschedule an appointment\n");
        printf("3. Check available slots\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter the slot number to book: ");
                int slot;
                scanf("%d",&slot);
                if(slots[slot-1]==0)
                {
                    printf("This slot is not available\n");
                    break;
                }
                char name[20];
                printf("Enter your name: ");
                scanf("%s",name);
                printf("Appointment booked successfully! Your name: %s, Slot number: %d\n",name,slot);
                slots[slot-1]=0; //mark the slot as booked
                break;
            }
            case 2:
            {
                reschedule(slots,10);
                break;
            }
            case 3:
            {
                display_slots(slots,10);
                break;
            }
            case 4:
            {
                printf("Thank you for using the post-apocalyptic appointment scheduler!\n");
                exit(0);
            }
            default:
            {
                printf("Invalid choice, try again\n");
                break;
            }
        }
    }
    return 0;
}