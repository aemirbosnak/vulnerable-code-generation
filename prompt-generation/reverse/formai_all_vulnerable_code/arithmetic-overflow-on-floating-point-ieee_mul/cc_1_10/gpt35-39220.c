//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <math.h>

// Function to calculate distance between two points
double distance(double lat1, double lon1, double lat2, double lon2){
    double radlat1, radlat2, radlon1, radlon2, difflat, difflon, a, c, d;
    radlat1 = M_PI * lat1/180.0;
    radlat2 = M_PI * lat2/180.0;
    radlon1 = M_PI * lon1/180.0;
    radlon2 = M_PI * lon2/180.0;
    difflat = radlat2 - radlat1;
    difflon = radlon2 - radlon1;
    a = sin(difflat/2) * sin(difflat/2) + cos(radlat1) * cos(radlat2) * sin(difflon/2) * sin(difflon/2);
    c = 2 * atan2(sqrt(a), sqrt(1-a));
    d = 6371 * c;
    return d;
}

int main(){
    double lat1, lon1, lat2, lon2, distanceTravelled = 0.0;
    char ch;
    int choice;

    printf("=========================== GPS Navigation Simulation ===========================\n");

    printf("Enter current latitude: ");
    scanf("%lf", &lat1);

    printf("Enter current longitude: ");
    scanf("%lf", &lon1);

    do{
        printf("\nChoose an option: \n");
        printf("1. Input destination coordinates\n");
        printf("2. Calculate distance to destination\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter destination latitude: ");
                scanf("%lf", &lat2);

                printf("Enter destination longitude: ");
                scanf("%lf", &lon2);

                printf("\nDestination set!\n");
                break;
            case 2:
                if(lat2 == 0.0 && lon2 == 0.0){
                    printf("\nDestination not set yet!\n");
                }
                else{
                    double dist = distance(lat1, lon1, lat2, lon2);
                    distanceTravelled += dist;
                    printf("\nDistance to destination: %.2lf km\n", dist);
                    lat1 = lat2;
                    lon1 = lon2;
                    lat2 = 0.0;
                    lon2 = 0.0;
                }
                break;
            case 3:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }

    }while(choice != 3);

    printf("\nTotal distance travelled: %.2lf km\n", distanceTravelled);
    return 0;
}