//Falcon2-11B DATASET v1.0 Category: Traffic Flow Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int x;
  int y;
  int direction;
} vehicle;

vehicle vehicles[100];
int numVehicles;

void addVehicle(int x, int y, int direction){
  vehicle v;
  v.x = x;
  v.y = y;
  v.direction = direction;
  vehicles[numVehicles++] = v;
}

void moveVehicles(){
  int i, j;
  for(i=0; i<numVehicles; i++){
    for(j=0; j<numVehicles; j++){
      if(i!=j){
        int dx = vehicles[i].x - vehicles[j].x;
        int dy = vehicles[i].y - vehicles[j].y;
        int dist = sqrt(dx*dx + dy*dy);
        if(dist <= 2){
          vehicles[i].direction = vehicles[j].direction;
        }
      }
    }
  }
}

int main(){
  srand(time(NULL));
  for(int i=0; i<numVehicles; i++){
    addVehicle(rand()%10, rand()%10, rand()%2);
  }
  while(1){
    moveVehicles();
    printf("%.2f %.2f %.2f\n", vehicles[0].x, vehicles[0].y, vehicles[0].direction);
    printf("%.2f %.2f %.2f\n", vehicles[numVehicles-1].x, vehicles[numVehicles-1].y, vehicles[numVehicles-1].direction);
    sleep(1);
  }
  return 0;
}