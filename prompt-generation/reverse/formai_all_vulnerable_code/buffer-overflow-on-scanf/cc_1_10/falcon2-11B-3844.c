//Falcon2-11B DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_name 50
#define max_rooms 10
#define max_dates 100

typedef struct room_info
{
    char name[max_name];
    int num_rooms;
    char availability[max_dates][max_name];
} room_info;

int main()
{
    room_info rooms[max_rooms];

    printf("enter the number of rooms:\n");
    int num_rooms;
    scanf("%d", &num_rooms);

    printf("enter the names of the rooms:\n");
    for (int i = 0; i < num_rooms; i++)
    {
        scanf("%s", rooms[i].name);
    }

    printf("enter the availability of each room:\n");
    for (int i = 0; i < num_rooms; i++)
    {
        char availability[max_dates][max_name];
        for (int j = 0; j < max_dates; j++)
        {
            scanf("%s", availability[j]);
            strcpy(rooms[i].availability[j], availability[j]);
        }
    }

    printf("the available rooms are:\n");
    for (int i = 0; i < num_rooms; i++)
    {
        printf("%s:\n", rooms[i].name);
        for (int j = 0; j < max_dates; j++)
        {
            printf("%s\n", rooms[i].availability[j]);
        }
    }

    return 0;
}