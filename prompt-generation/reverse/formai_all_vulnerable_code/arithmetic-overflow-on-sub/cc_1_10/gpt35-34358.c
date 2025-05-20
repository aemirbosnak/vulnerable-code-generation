//FormAI DATASET v1.0 Category: Smart home automation ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Defining Rooms and Appliances inside them
typedef struct
{
    int num_of_thermostats;
    int num_of_lights;
    int num_of_locks;
} Room;

//Global array of Rooms
Room rooms[5];

//Function to show menu
void menu()
{
    printf("Choose an option from the following:\n");
    printf("1. Add a room\n");
    printf("2. Add an appliance\n");
    printf("3. Display current status\n");
    printf("4. Exit\n");
}

//Function to add a room
void add_room()
{
    int room_num;
    printf("Enter the room number: ");
    scanf("%d", &room_num);
    room_num--;
    if(room_num >= 0 && room_num < 5)
    {
        printf("\nEnter the number of thermostats in the room: ");
        scanf("%d", &rooms[room_num].num_of_thermostats);
        printf("\nEnter the number of lights in the room: ");
        scanf("%d", &rooms[room_num].num_of_lights);
        printf("\nEnter the number of locks in the room: ");
        scanf("%d", &rooms[room_num].num_of_locks);
    }
    else
    {
        printf("\nInvalid room number.\n");
    }
}

//Function to add an appliance
void add_appliance()
{
    int room_num, appliance_type, num_of_appliances;
    printf("Enter the room number: ");
    scanf("%d", &room_num);
    room_num--;
    if(room_num >= 0 && room_num < 5)
    {
        printf("\nChoose the type of appliance:\n");
        printf("1. Thermostat\n");
        printf("2. Light\n");
        printf("3. Lock\n");
        scanf("%d", &appliance_type);
        printf("\nEnter the number of appliances: ");
        scanf("%d", &num_of_appliances);
        switch(appliance_type)
        {
            case 1:
                rooms[room_num].num_of_thermostats += num_of_appliances;
                break;
            case 2:
                rooms[room_num].num_of_lights += num_of_appliances;
                break;
            case 3:
                rooms[room_num].num_of_locks += num_of_appliances;
                break;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    }
    else
    {
        printf("\nInvalid room number.\n");
    }
}

//Function to display current status
void display_status()
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("Room %d:\n", i+1);
        printf("Thermostats: %d\n", rooms[i].num_of_thermostats);
        printf("Lights: %d\n", rooms[i].num_of_lights);
        printf("Locks: %d\n\n", rooms[i].num_of_locks);
    }
}

int main()
{
    int option;
    while(1)
    {
        menu();
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                add_room();
                break;
            case 2:
                add_appliance();
                break;
            case 3:
                display_status();
                break;
            case 4:
                return 0;
            default:
                printf("\nInvalid option.\n");
                break;
        }
    }
    return 0;
}