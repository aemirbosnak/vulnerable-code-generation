//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include<stdio.h>
#include<math.h>
#include<time.h>

//This is the BENCHMARKING program
//It will test the speed of your CPU
//But remember, it's just for fun!

int main(){

  printf("Welcome to CPU Speedometer!\n");
  printf("Enter the number of loops you want to test: ");
  int n;
  scanf("%d",&n); // user input for number of loops

  printf("Initializing test...\n");

  clock_t t1 = clock();

  //start of loop
  for(int i = 0; i < n; i++){
    sqrt(i);  //square root calculation
  }
  //end of loop

  clock_t t2 = clock();

  double time_taken = ((double)(t2 - t1)) / CLOCKS_PER_SEC; //calculate time taken in seconds

  printf("Wow! Your CPU took %.2f seconds to complete %d loops of square root calculations.\n", time_taken, n);
  printf("Let's see how you compare to other CPUs.\n");

  //CPU speed rating benchmarks based on number of loops completed per second
  double slow_cpu = 10;
  double average_cpu = 100;
  double fast_cpu = 1000;
  double super_cpu = 10000;

  if(time_taken > 60){ //if it takes more than 1 minute to complete the test
      printf("Seems like your CPU needs a vacation.\n");
  }
  else if(time_taken > 30){ //if it takes more than 30 seconds but less than 1 minute
      printf("Wow, your CPU is slower than a snail on a treadmill.\n");
      printf("Your CPU speed rating is: %.2f loops/sec\n", slow_cpu/n);
  }
  else if(time_taken > 10){ //if it takes more than 10 seconds but less than 30 seconds
      printf("Hmmm, your CPU is average.\n");
      printf("Your CPU speed rating is: %.2f loops/sec\n", average_cpu/n);
  }
  else if(time_taken > 1){ //if it takes more than 1 second but less than 10 seconds
      printf("Impressive! Your CPU is faster than most.\n");
      printf("Your CPU speed rating is: %.2f loops/sec\n", fast_cpu/n);
  }
  else{ //if it takes less than 1 second
      printf("Holy cow! Your CPU is a superhero.\n");
      printf("Your CPU speed rating is: %.2f loops/sec\n", super_cpu/n);
  }

  return 0; //end of program
}