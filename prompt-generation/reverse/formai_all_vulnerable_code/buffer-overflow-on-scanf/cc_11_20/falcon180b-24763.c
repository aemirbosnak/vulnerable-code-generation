//Falcon-180B DATASET v1.0 Category: Elevator Simulation ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct {
  int floor;
  int direction;
} elevator;

int main() {
  int floors, elevators, passengers, i, j, k, l, m, n;
  elevator e[10];
  char ch;

  printf("Enter the number of floors: ");
  scanf("%d", &floors);

  printf("Enter the number of elevators: ");
  scanf("%d", &elevators);

  printf("Enter the number of passengers: ");
  scanf("%d", &passengers);

  for(i=0; i<elevators; i++) {
    e[i].floor = 1;
    e[i].direction = 1;
  }

  for(i=0; i<passengers; i++) {
    printf("Enter the destination floor for passenger %d: ", i+1);
    scanf("%d", &k);

    for(j=0; j<elevators; j++) {
      if(e[j].floor == k) {
        e[j].direction = 0;
        break;
      }
    }
  }

  while(1) {
    system("clear");
    for(i=0; i<floors; i++) {
      printf("%d ", i+1);
    }

    printf("\n");
    for(i=0; i<elevators; i++) {
      if(e[i].direction == 1) {
        printf("Elevator %d going up\n", i+1);
      }
      else if(e[i].direction == 0) {
        printf("Elevator %d going down\n", i+1);
      }
    }

    for(i=0; i<passengers; i++) {
      printf("Passenger %d's elevator is at floor %d\n", i+1, e[i%elevators].floor);
    }

    printf("\n");
    for(i=0; i<elevators; i++) {
      if(e[i].direction == 1 && e[i].floor == floors) {
        e[i].direction = 0;
      }
      else if(e[i].direction == 0 && e[i].floor == 1) {
        e[i].direction = 1;
      }

      if(e[i].direction == 1) {
        e[i].floor++;
      }
      else if(e[i].direction == 0) {
        e[i].floor--;
      }
    }

    sleep(1);
  }

  return 0;
}