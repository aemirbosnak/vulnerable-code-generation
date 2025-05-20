//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 1000000
#define MAX_TIME 1000000

int main() {
  int num = 0;
  int sum = 0;
  int i, j, k;
  int start_time;
  int end_time;
  int elapsed_time;
  int max_elapsed_time = 0;
  int max_num = 0;
  int max_sum = 0;
  int max_sum_num = 0;
  int max_elapsed_time_num = 0;
  int max_elapsed_time_sum = 0;
  int max_elapsed_time_sum_num = 0;

  srand(time(NULL));
  num = rand() % MAX_NUM;

  start_time = clock();
  for (i = 1; i <= num; i++) {
    sum += i;
  }
  end_time = clock();
  elapsed_time = (end_time - start_time) / CLOCKS_PER_SEC;

  if (elapsed_time > max_elapsed_time) {
    max_elapsed_time = elapsed_time;
    max_num = num;
    max_sum = sum;
    max_sum_num = i;
    max_elapsed_time_num = elapsed_time;
    max_elapsed_time_sum = sum;
    max_elapsed_time_sum_num = num;
  }

  printf("Random number: %d\n", num);
  printf("Sum: %d\n", sum);
  printf("Elapsed time: %d seconds\n", elapsed_time);
  printf("Maximum elapsed time: %d seconds\n", max_elapsed_time);
  printf("Maximum number: %d\n", max_num);
  printf("Maximum sum: %d\n", max_sum);
  printf("Number used to calculate maximum sum: %d\n", max_sum_num);
  printf("Elapsed time used to calculate maximum sum: %d seconds\n", max_elapsed_time_sum);
  printf("Sum used to calculate maximum elapsed time: %d\n", max_elapsed_time_sum_num);

  return 0;
}