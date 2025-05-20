//FormAI DATASET v1.0 Category: Task Scheduler ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void task1(){
  printf("Executing task 1...\n");
  // Code for task 1
}

void task2(){
  printf("Executing task 2...\n");
  // Code for task 2
}

void task3(){
  printf("Executing task 3...\n");
  // Code for task 3
}

int main() {

  int interval[3] = {5, 10, 15}; // Set interval for each task
  int next_exec[3]; // Array to hold the next execution time for each task
  time_t current_time;

  for(int i=0; i<3; i++){
      next_exec[i] = time(NULL) + interval[i]; // Set the initial next execution time
  }

  while(1){

    current_time = time(NULL);

    // Execute task 1 if its scheduled execution time has arrived
    if(current_time >= next_exec[0]){
      task1();
      next_exec[0] += interval[0]; // Update the next execution time for task 1
    }

    // Execute task 2 if its scheduled execution time has arrived
    if(current_time >= next_exec[1]){
      task2();
      next_exec[1] += interval[1]; // Update the next execution time for task 2
    }

    // Execute task 3 if its scheduled execution time has arrived
    if(current_time >= next_exec[2]){
      task3();
      next_exec[2] += interval[2]; // Update the next execution time for task 3
    }

    // Sleep for 1 second before checking next task
    sleep(1);
  }

  return 0;
}