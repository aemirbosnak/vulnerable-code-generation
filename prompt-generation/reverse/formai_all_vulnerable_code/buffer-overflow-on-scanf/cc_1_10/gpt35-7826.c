//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

#define MAX_LOCATIONS 10

struct location 
{
    char name[100];
    float latitude;
    float longitude;
};

struct location locations[MAX_LOCATIONS];

int num_locations = 0;

void add_location() 
{
    if(num_locations<MAX_LOCATIONS) 
    {
        printf("Enter the name of the location:\n");
        scanf("%s", locations[num_locations].name);
        printf("Enter the latitude of the location:\n");
        scanf("%f", &locations[num_locations].latitude);
        printf("Enter the longitude of the location:\n");
        scanf("%f", &locations[num_locations].longitude);
        num_locations++;
    }
    else 
    {
        printf("Cannot add more locations. Maximum limit reached.\n");
    }
}

void display_locations() 
{
    printf("List of available locations:\n");
    for(int i=0;i<num_locations;i++) 
    {
        printf("%d. %s\n", i+1, locations[i].name);
    }
}

void get_directions(char from[], char to[]) 
{
    int from_index = -1;
    int to_index = -1;
  
    for(int i=0;i<num_locations;i++) 
    {
        if(strcmp(from, locations[i].name)==0) 
        {
            from_index = i;
        }
        if(strcmp(to, locations[i].name)==0) 
        {
            to_index = i;
        }
    }

    if(from_index==-1) 
    {
        printf("Cannot find the starting location: %s\n", from);
        return;
    }

    if(to_index==-1) 
    {
        printf("Cannot find the destination location: %s\n", to);
        return;
    }

    printf("Route from %s to %s:\n", from, to);
    printf("Latitudes and Longitudes:\n");
    printf("%f, %f\n", locations[from_index].latitude, locations[from_index].longitude);
    printf("%f, %f\n", locations[to_index].latitude, locations[to_index].longitude);
}

int main() 
{
    int choice;

    printf("GPS Navigation Simulation Program\n\n");

    while(1) 
    {
        printf("\nChoose an option:\n");
        printf("1. Add a location\n");
        printf("2. Display available locations\n");
        printf("3. Get directions from one location to another\n");
        printf("4. Exit\n");

        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                add_location();
                break;
            case 2:
                display_locations();
                break;
            case 3:
                {
                    char from[100];
                    char to[100];
                    printf("Enter the starting location:\n");
                    scanf("%s", from);
                    printf("Enter the destination location:\n");
                    scanf("%s", to);
                    get_directions(from, to);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}