//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

typedef struct {
  float *data;
  int capacity;
  int size;
} Buffer;

void init_buffer(Buffer *buffer) {
  buffer->data = malloc(BUFFER_SIZE * sizeof(float));
  buffer->capacity = BUFFER_SIZE;
  buffer->size = 0;
}

void free_buffer(Buffer *buffer) {
  free(buffer->data);
}

void push_sample(Buffer *buffer, float sample) {
  if (buffer->size == buffer->capacity) {
    printf("Buffer overflow\n");
    return;
  }
  buffer->data[buffer->size++] = sample;
}

float pop_sample(Buffer *buffer) {
  if (buffer->size == 0) {
    printf("Buffer underflow\n");
    return 0;
  }
  return buffer->data[--buffer->size];
}

void process_buffer(Buffer *buffer, float (*processor)(float)) {
  for (int i = 0; i < buffer->size; i++) {
    buffer->data[i] = processor(buffer->data[i]);
  }
}

float add_noise(float sample) {
  return sample + (rand() % 100) / 100.0;
}

int main() {
  Buffer input_buffer, output_buffer;
  init_buffer(&input_buffer);
  init_buffer(&output_buffer);

  while (1) {
    printf("Enter sample: ");
    float sample;
    scanf("%f", &sample);
    push_sample(&input_buffer, sample);

    if (input_buffer.size == BUFFER_SIZE) {
      process_buffer(&input_buffer, add_noise);
      for (int i = 0; i < input_buffer.size; i++) {
        push_sample(&output_buffer, pop_sample(&input_buffer));
      }
      init_buffer(&input_buffer);
    }
  }

  free_buffer(&input_buffer);
  free_buffer(&output_buffer);

  return 0;
}