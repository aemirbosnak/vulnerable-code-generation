//FormAI DATASET v1.0 Category: Elevator Simulation ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition = PTHREAD_COND_INITIALIZER;

int floor_count = 0, current_floor = 0, target_floor = 0, floors_to_travel = 0;
int direction = 1; //1 for up, -1 for down

void *elevator(void * val) {
  while(1) {
    pthread_mutex_lock(&lock);
    while(floors_to_travel == 0) {
      pthread_cond_wait(&condition, &lock);
    }
    printf("Elevator is moving. Current floor: %d\n", current_floor);
    while(floors_to_travel != 0) {
      current_floor += direction;
      if(current_floor == target_floor) {
        floors_to_travel--;
        printf("Elevator has reached floor %d\n", current_floor);
        if(floors_to_travel == 0) {
          printf("All floors covered! Exiting.\n");
          exit(0);
        }
        break;
      }
    }
    pthread_mutex_unlock(&lock);
  }
}

void *user(void * val) {
  int desired_floor = rand() % floor_count + 1;
  usleep(rand() % 1000);
  pthread_mutex_lock(&lock);
  printf("User at floor %d wants to go to floor %d\n", current_floor, desired_floor);
  if(desired_floor > current_floor) {
    if(direction == -1) {
      printf("Changing direction to up.\n");
      direction = 1;
    }
  } else if(desired_floor < current_floor) {
    if(direction == 1) {
      printf("Changing direction to down.\n");
      direction = -1;
    }
  }
  target_floor = desired_floor;
  floors_to_travel = abs(target_floor - current_floor);
  pthread_cond_signal(&condition);
  pthread_mutex_unlock(&lock);
  pthread_exit(NULL);
}

int main() {
  printf("Enter number of floors in the building: ");
  scanf("%d", &floor_count);

  pthread_t elevator_thread;
  pthread_create(&elevator_thread, NULL, elevator, NULL);

  srand(time(NULL));
  for(int i=0; i<floor_count; i++) {
    pthread_t user_thread;
    pthread_create(&user_thread, NULL, user, NULL);
    usleep(rand() % 5000);
  }

  pthread_join(elevator_thread, NULL);
}