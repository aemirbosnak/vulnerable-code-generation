//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main()
{
    int choice;
    double lat1, lat2, lon1, lon2, d, r, PI = 3.141592653589793;
    srand(time(NULL));
    printf("\n\nWelcome to GPS Navigation Simulation!\n");
    printf("**************************************\n\n");
    printf("\t1. Measure distance between two points\n");
    printf("\t2. Navigate to a random location\n");
    printf("\t3. Exit\n\n");
    while(1)
    {
        printf("Please enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter coordinates of point #1 (latitude, longitude): ");
                scanf("%lf %lf", &lat1, &lon1);
                printf("Enter coordinates of point #2 (latitude, longitude): ");
                scanf("%lf %lf", &lat2, &lon2);
                r = 6371; // radius of earth in km
                lat1 = lat1*PI/180; 
                lat2 = lat2*PI/180; 
                lon1 = lon1*PI/180; 
                lon2 = lon2*PI/180;
                d = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2-lon1))*r;
                printf("\nDistance between given points is %.2lf km\n\n", d);
                break;
            case 2:
                printf("\nCalculating current location...\n\n");
                lat1=rand()%181-90;
                lon1=rand()%361-180;
                printf("Your current location is:\nLatitude: %.2lf\nLongitude: %.2lf\n\n",lat1,lon1);
                printf("Enter destination coordinates (latitude, longitude): ");
                scanf("%lf %lf", &lat2, &lon2);
                lat2 = lat2*PI/180;
                lon2 = lon2*PI/180; 
                d = acos(sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(lon2-lon1))*r;
                printf("Distance to the destination is %.2lf km\n", d);
                printf("Please proceed towards the destination.\n\n");
                break;
            case 3:
                printf("\nThank you for using GPS Navigation Simulation. Goodbye!\n\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter again.\n\n");
                break;
        }   
    }
    return 0;
}