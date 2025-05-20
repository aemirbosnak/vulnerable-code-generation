//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

#define NUM_THREADS 4

struct thread_data {
  double a;
  double b;
  double result;
  int op;
};

void *thread_func(void *arg) {
  struct thread_data *data = (struct thread_data *)arg;
  switch (data->op) {
  case 0:
    data->result = data->a + data->b;
    break;
  case 1:
    data->result = data->a - data->b;
    break;
  case 2:
    data->result = data->a * data->b;
    break;
  case 3:
    data->result = data->a / data->b;
    break;
  case 4:
    data->result = pow(data->a, data->b);
    break;
  case 5:
    data->result = sqrt(data->a);
    break;
  case 6:
    data->result = log(data->a);
    break;
  case 7:
    data->result = exp(data->a);
    break;
  case 8:
    data->result = sin(data->a);
    break;
  case 9:
    data->result = cos(data->a);
    break;
  case 10:
    data->result = tan(data->a);
    break;
  case 11:
    data->result = asin(data->a);
    break;
  case 12:
    data->result = acos(data->a);
    break;
  case 13:
    data->result = atan(data->a);
    break;
  default:
    data->result = 0;
  }
  pthread_exit(NULL);
}

int main() {
  int num_ops;
  scanf("%d", &num_ops);
  pthread_t threads[num_ops];
  struct thread_data data[num_ops];
  for (int i = 0; i < num_ops; i++) {
    scanf("%lf", &data[i].a);
    scanf("%lf", &data[i].b);
    scanf("%d", &data[i].op);
    pthread_create(&threads[i], NULL, thread_func, (void *)&data[i]);
  }
  for (int i = 0; i < num_ops; i++) {
    pthread_join(threads[i], NULL);
    printf("%.10lf\n", data[i].result);
  }
  return 0;
}