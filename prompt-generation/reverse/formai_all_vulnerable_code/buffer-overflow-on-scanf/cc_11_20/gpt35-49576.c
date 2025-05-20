//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(NULL)); //seed random number generator
  
  //initialize variables
  int num_baggages = 0;
  int max_weight = 0;
  int num_conveyors = 0;
  int num_planes = 0;
  int conveyors_capacity = 0;
  int planes_capacity = 0;
  
  //get user input
  printf("Enter the number of baggages: ");
  scanf("%d", &num_baggages);
  
  printf("Enter the maximum weight of the baggages: ");
  scanf("%d", &max_weight);
  
  printf("Enter the number of conveyors: ");
  scanf("%d", &num_conveyors);
  
  printf("Enter the capacity of each conveyor: ");
  scanf("%d", &conveyors_capacity);
  
  printf("Enter the number of planes: ");
  scanf("%d", &num_planes);
  
  printf("Enter the capacity of each plane: ");
  scanf("%d", &planes_capacity);
  
  //initialize arrays
  int baggages_weights[num_baggages];
  int baggages_conveyors[num_baggages];
  int baggages_planes[num_baggages];
  int conveyors_weights[num_conveyors];
  int planes_weights[num_planes];

  //generate random baggages weight and initial conveyor
  for(int i = 0; i < num_baggages; i++){
    baggages_weights[i] = rand() % max_weight + 1;
    baggages_conveyors[i] = rand() % num_conveyors + 1; //initially assigned to a random conveyor
  }
  
  //initialize empty conveyor weights
  for(int i = 0; i < num_conveyors; i++){
    conveyors_weights[i] = 0;
  }
  
  //initialize empty plane weights
  for(int i = 0; i < num_planes; i++){
    planes_weights[i] = 0;
  }
  
  //simulate conveyor to plane transfer
  for(int i = 0; i < num_baggages; i++){
    int conveyor = baggages_conveyors[i] - 1; //convert to 0-indexed array
    int weight = baggages_weights[i];
    if(conveyors_weights[conveyor] + weight <= conveyors_capacity){
      conveyors_weights[conveyor] += weight; //add baggage weight to conveyor
      baggages_planes[i] = -1; //set plane to -1 indicating that it has not yet been assigned
    }
  }
  
  //simulate plane loading
  for(int i = 0; i < num_planes; i++){
    for(int j = 0; j < num_baggages; j++){
      if(baggages_planes[j] == -1 && planes_weights[i] + baggages_weights[j] <= planes_capacity){
        planes_weights[i] += baggages_weights[j];
        baggages_planes[j] = i; //assign baggage to current plane
      }
    }
  }
  
  //print results
  printf("Baggage\tConveyor\tPlane\n");
  for(int i = 0; i < num_baggages; i++){
    printf("%d\t%d\t", baggages_weights[i], baggages_conveyors[i]);
    if(baggages_planes[i] == -1){
      printf("Not loaded");
    }
    else{
      printf("%d", baggages_planes[i] + 1); //convert to 1-indexed plane number
    }
    printf("\n");
  }
  
  return 0;
}