//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node    //structure to store GPS location of different places
{
    int id;
    char name[50];
    float lat,lon;
}; 
struct Node gps[5]={  //initialize GPS locations
                    {1,"Empire State Building",40.7484,-73.9857},
                    {2,"Statue of Liberty",40.6892,-74.0444},
                    {3,"Times Square",40.7579,-73.9850},
                    {4,"Central Park",40.7851,-73.9683},
                    {5,"One World Trade Center",40.7128,-74.0135}
                    };
float calcul(int v, float l1,float l2,float l3,float l4) //calculate distance between two GPS points
{
    float lat1,lat2,long1,long2,dist,radians; 
    lat1=l1;
    long1=l2;
    lat2=l3;
    long2=l4;
    radians = M_PI/180.0;
    lat1 *= radians;
    lat2 *= radians;
    long1 *= radians;
    long2 *= radians;
    dist = sin(lat1)*sin(lat2) + cos(lat1)*cos(lat2)*cos(long2-long1);
    dist = acos(dist);
    dist /= radians;
    dist *= 60 * 1.1515; //in miles
    if(v==1) //for metric system
    {
       dist *= 1.609344; //result in kilometers
       return dist;
    }
    else
    {
        return dist;
    }
}
int main()
{
    int i,j,opt;
    float curr_lat,curr_lon,distance;
    printf("Enter current latitude: ");
    scanf("%f",&curr_lat);
    printf("Enter current longitude: ");
    scanf("%f",&curr_lon);
    printf("\n\nEnter your choice\n1. Get distance between your location and all other GPS locations in miles\n2. Get distance between your location and all other GPS locations in kilometers\n3. Find closest location\n4. Exit\n");
    scanf("%d",&opt);
    
    
    switch(opt)   //menu
    {
        case 1:
            printf("\n\nDistance from your location to all other destinations in miles:\n");
            for(i=0;i<5;i++)
            {
                distance=calcul(0,curr_lat,curr_lon,gps[i].lat,gps[i].lon);
                printf("%d. %s: %.2f miles\n",gps[i].id,gps[i].name,distance);
            }
            break;
        case 2:
            printf("\n\nDistance from your location to all other destinations in kilometers:\n");
            for(i=0;i<5;i++)
            {
                distance=calcul(1,curr_lat,curr_lon,gps[i].lat,gps[i].lon);
                printf("%d. %s: %.2f km\n",gps[i].id,gps[i].name,distance);
            }
            break;
        case 3:
            printf("\n\nClosest Location to your current location is: ");
            float min_dis=calcul(0,curr_lat,curr_lon,gps[0].lat,gps[0].lon); //initialize minimum distance
            int index=0;
            for(i=1;i<5;i++)  //find minimum distance
            {
                distance=calcul(0,curr_lat,curr_lon,gps[i].lat,gps[i].lon);
                if(distance<min_dis)
                {
                    min_dis=distance;
                    index=i;
                }
            }
            printf("%s",gps[index].name);
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input");
            break;
    }
    return 0;
}