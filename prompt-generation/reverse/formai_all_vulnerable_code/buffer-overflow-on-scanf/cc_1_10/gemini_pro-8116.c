//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// Define the thread data structure
typedef struct thread_data {
  double a;
  double b;
  char op;
  double result;
} thread_data_t;

// Define the thread function
void *thread_function(void *arg) {
  thread_data_t *data = (thread_data_t *)arg;

  // Perform the calculation based on the operation
  switch (data->op) {
    case '+':
      data->result = data->a + data->b;
      break;
    case '-':
      data->result = data->a - data->b;
      break;
    case '*':
      data->result = data->a * data->b;
      break;
    case '/':
      data->result = data->a / data->b;
      break;
    case '^':
      data->result = pow(data->a, data->b);
      break;
    case 's':
      data->result = sin(data->a);
      break;
    case 'c':
      data->result = cos(data->a);
      break;
    case 't':
      data->result = tan(data->a);
      break;
    default:
      printf("Invalid operation\n");
      break;
  }

  // Return the result
  return NULL;
}

int main() {
  // Get the input from the user
  double a, b;
  char op;
  printf("Enter the first number: ");
  scanf("%lf", &a);
  printf("Enter the second number: ");
  scanf("%lf", &b);
  printf("Enter the operation (+, -, *, /, ^, s, c, t): ");
  scanf(" %c", &op);

  // Create the thread data structure
  thread_data_t data;
  data.a = a;
  data.b = b;
  data.op = op;

  // Create the thread
  pthread_t thread;
  pthread_create(&thread, NULL, thread_function, &data);

  // Wait for the thread to finish
  pthread_join(thread, NULL);

  // Print the result
  printf("Result: %lf\n", data.result);

  return 0;
}