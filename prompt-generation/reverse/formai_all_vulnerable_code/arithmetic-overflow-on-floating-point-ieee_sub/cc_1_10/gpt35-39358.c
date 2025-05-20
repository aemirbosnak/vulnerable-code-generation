//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: mind-bending
//Unique GPS Navigation Simulation Program

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Structure to hold coordinates
struct coordinates{
    float lat;
    float lon;
};

//Function to calculate distance between two coordinates
float calcDistance(struct coordinates curr_loc, struct coordinates target_loc){
    const int R = 6371000; //Radius of the earth in meters
    float lat1, lat2, lon1, lon2, delta_lat, delta_lon, a, c, distance;
    lat1 = curr_loc.lat * (M_PI / 180); //Convert latitude degree to radians
    lat2 = target_loc.lat * (M_PI / 180);
    delta_lat = (target_loc.lat - curr_loc.lat) * (M_PI / 180); //Change in latitude
    delta_lon = (target_loc.lon - curr_loc.lon) * (M_PI / 180); //Change in longitude
    lon1 = curr_loc.lon * (M_PI / 180); //Convert longitude degree to radians
    lon2 = target_loc.lon * (M_PI / 180);
    a = sin(delta_lat / 2) * sin(delta_lat / 2) + cos(lat1) * cos(lat2) * sin(delta_lon / 2) * sin(delta_lon / 2);
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    distance = R * c; //Distance between two coordinates in meters
    return distance;
}

//Main function
int main(){
    int num_of_locs, i;
    float target_lat, target_lon;
    printf("Enter the number of locations to navigate: ");
    scanf("%d", &num_of_locs);
    struct coordinates* locs;
    locs = (struct coordinates*) malloc(num_of_locs * sizeof(struct coordinates)); //Dynamically allocate memory for array of coordinates
    for(i = 0; i < num_of_locs; i++){
        printf("Enter the latitude of location %d: ", i+1);
        scanf("%f", &locs[i].lat);
        printf("Enter the longitude of location %d: ", i+1);
        scanf("%f", &locs[i].lon);
    }
    printf("Enter the target location coordinates: \n");
    printf("Latitude: ");
    scanf("%f", &target_lat);
    printf("Longitude: ");
    scanf("%f", &target_lon);
    struct coordinates target_loc = {target_lat, target_lon};
    float min_distance = calcDistance(locs[0], target_loc);
    int closest_loc_index = 0;
    for(i = 1; i < num_of_locs; i++){
        float distance = calcDistance(locs[i], target_loc);
        if(distance < min_distance){
            min_distance = distance;
            closest_loc_index = i;
        }
    }
    printf("The closest location to the target is location %d at coordinates (%.6f, %.6f)\n", closest_loc_index+1, locs[closest_loc_index].lat, locs[closest_loc_index].lon);
    return 0;
}