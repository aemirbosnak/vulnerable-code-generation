//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROADLENGTH 20          // total distance from point A to point B
#define MAXCARS 10             // max number of cars on road
#define CARLENGTH 2            // length of each car in units
#define MAXSPEED 4             // max speed of each car in units/sec
#define MINPROBABILITY 10      // min probability of a new car entering in %
#define MAXPROBABILITY 30      // max probability of a new car entering in %
#define LEFTLANE 1             // left lane for slower traffic
#define RIGHTLANE 2            // right lane for faster traffic
#define SPACE '-'              // space character for empty space on road
#define CAR 'X'                // character for car on road

void printRoad(char road[]);   // print the road at current moment
int getSpeed();                // get speed of a new car on road
int checkPosition(char road[], int currentPos, int speed, int lane); // check if the position is free or not

int main(){
  char road[ROADLENGTH];      // initialize the road array
  int i,j,k;
  int carCount = 0;
  int probabilityOfNewCar;

  srand(time(NULL));          // initialize random function with system time

  for(i=0;i<ROADLENGTH;i++)   // initialize empty road with spaces
    road[i] = SPACE;
  for(i=0;i<MAXCARS;i++){     // add initial cars on road, one in each lane
    road[i*3+1] = CAR;
    carCount++;
  }
  printRoad(road);

  while(1){                   // game loop - simulate the traffic
    probabilityOfNewCar = rand() % (MAXPROBABILITY - MINPROBABILITY) + MINPROBABILITY;  // probability of new car entering
    if(carCount == MAXCARS){                                                        // check if road is full
      printf("\nRoad is full, game over!"); 
      break;
    }
    if(rand()%100 < probabilityOfNewCar){                                           // new car enters
      for(i=LEFTLANE;i<=RIGHTLANE;i++){                                             // enter in each lane
        if(checkPosition(road, i, 1, i) != -1){                                     // check if position is free
          road[checkPosition(road, i, -CARLENGTH, i)] = CAR;                        // add the new car to the road
          carCount++;                                                                // increment the car count
          break;
        }
      }
    }
    for(i=ROADLENGTH-1;i>=0;i--){                                                    // update each car on road
      if(road[i] == CAR){                                                            // car is present
        k = 0;
        while(checkPosition(road, i, ++k, RIGHTLANE) != -1)                          // check if forward slot is free in right lane
          ;
        if(k > MAXSPEED)                                                             // adjust speed if beyond max speed
          k = MAXSPEED;
        if(i+k >= ROADLENGTH){                                                       // car reaches destination
          road[i] = SPACE;                                                           
          carCount--;                                                                // decrement the car count
          continue;
        }
        if(checkPosition(road, i, k, RIGHTLANE) == i+k){                              // if space in right lane, car changes lane
          road[i] = SPACE;
          road[i+k] = CAR;
        }
        else if(checkPosition(road, i, 1, i) != i+1){                                 // move car in current lane if position is free
          road[i] = SPACE;
          road[i+1] = CAR;
        }
      }
    }
    printRoad(road);                                                                  // print the updated road
    printf("\nNumber of cars: %d\n", carCount);                                      // display car count on the road
    printf("\nPress Enter to simulate next step...");
    getchar();
  }

  return 0;
}

void printRoad(char road[]){
  int i;
  printf("\n");
  for(i=0;i<ROADLENGTH;i++)
    printf("%c", road[i]);
}

int getSpeed(){
  return rand() % MAXSPEED + 1;
}

int checkPosition(char road[], int currentPos, int speed, int lane){                 // return -1 if position is occupied, else return new position
  int newPos;
  if(lane == RIGHTLANE){                                                              // check if space in right lane
    if(currentPos+speed >= ROADLENGTH || road[currentPos+speed] == CAR) 
      return -1;
    return currentPos+speed;
  }
  else{                                                                               // check if space in left lane
    if(currentPos - speed < 0 || road[currentPos-speed] == CAR || road[currentPos-speed+1] == CAR)
      return -1;
    return currentPos-speed;
  }
}