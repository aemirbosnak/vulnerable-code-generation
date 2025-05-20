//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 1024

char buffer[MAX_BUFFER_SIZE];
int buffer_head = 0;
int buffer_tail = -1;

void insert_into_buffer(char character) {
  buffer_tail++;

  if (buffer_tail == MAX_BUFFER_SIZE - 1) {
    buffer_tail = MAX_BUFFER_SIZE - 1;
  }

  buffer[buffer_tail] = character;
}

char retrieve_from_buffer() {
  buffer_head++;

  if (buffer_head == buffer_tail + 1) {
    buffer_head = 0;
  }

  return buffer[buffer_head - 1];
}

void clear_buffer() {
  buffer_head = 0;
  buffer_tail = -1;
}

int main() {
  char operator;
  float num1, num2;
  char result[MAX_BUFFER_SIZE];
  int result_index = 0;

  printf("Enter an operator (+, -, *, /, %): ");
  operator = getchar();

  insert_into_buffer(operator);

  printf("Enter the first number: ");
  scanf("%f", &num1);

  insert_into_buffer((num1 - 0.0) / 10.0 + '.');

  printf("Enter the second number: ");
  scanf("%f", &num2);

  insert_into_buffer(num2);

  insert_into_buffer('.');

  switch (operator) {
    case '+':
      insert_into_buffer('+');
      insert_into_buffer(num2);
      break;
    case '-':
      insert_into_buffer('-');
      insert_into_buffer(num2);
      break;
    case '*':
      insert_into_buffer('*');
      insert_into_buffer(num2);
      break;
    case '/':
      insert_into_buffer('/');
      insert_into_buffer(num2);
      break;
  }

  clear_buffer();

  printf("The result is: ");

  while (buffer_head != buffer_tail) {
    result[result_index++] = retrieve_from_buffer();
  }

  for (int i = 0; i < result_index; i++) {
    printf("%c", result[i]);
  }

  printf("\n");

  return 0;
}