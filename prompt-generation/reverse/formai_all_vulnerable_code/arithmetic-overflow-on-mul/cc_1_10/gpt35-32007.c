//FormAI DATASET v1.0 Category: Benchmarking ; Style: funny
#include <stdio.h>
#include <time.h>

int main() {
  // Setting up the benchmarking variables
  clock_t t;
  double time_taken;

  // Initializing the variables to be benchmarked
  int a = 1000000000;
  int b = 1000000000;

  // Starting the benchmark
  t = clock();

  // The most advanced benchmarking algorithm known to mankind
  while(a > 1) {
      a /= 2;
      b *= 2;
  }

  // Ending the benchmark
  t = clock() - t;
  time_taken = ((double)t)/CLOCKS_PER_SEC;

  // Printing the benchmark results with some humor
  printf("Wow, that was fast! It only took %f seconds to halve %d and double %d...\n", time_taken, 1000000000, 1000000000);
  printf("Now let's run the same algorithm but with much larger numbers\n");

  // Initializing the new variables to be benchmarked
  long long x = 2000000000000000000;
  long long y = 2000000000000000000;

  // Starting the new benchmark
  t = clock();

  // The even more advanced benchmarking algorithm known to alien civilizations
  while(x > 1) {
      x /= 2;
      y *= 2;
  }

  // Ending the new benchmark
  t = clock() - t;
  time_taken = ((double)t)/CLOCKS_PER_SEC;

  // Printing the final benchmark results with even more humor
  printf("Holy cow! It took %f seconds to halve %lld and double %lld!\n", time_taken, 2000000000000000000, 2000000000000000000);
  printf("I think that's a new record! Maybe we should apply for the Guinness World Record of fastest benchmark program?\n");
  printf("Nah, let's just stick to coding and making pointless benchmarks...\n");

  return 0;
}