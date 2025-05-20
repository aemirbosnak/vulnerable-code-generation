//Code Llama-13B DATASET v1.0 Category: Audio processing ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>

#define BUFFER_SIZE 4096
#define SAMPLE_RATE 44100

typedef struct {
  float *buffer;
  uint32_t size;
  uint32_t read_idx;
  uint32_t write_idx;
} audio_buffer_t;

void audio_buffer_init(audio_buffer_t *buffer, uint32_t size) {
  buffer->size = size;
  buffer->read_idx = 0;
  buffer->write_idx = 0;
  buffer->buffer = (float *)malloc(size * sizeof(float));
}

void audio_buffer_free(audio_buffer_t *buffer) {
  free(buffer->buffer);
}

void audio_buffer_write(audio_buffer_t *buffer, float value) {
  buffer->buffer[buffer->write_idx] = value;
  buffer->write_idx = (buffer->write_idx + 1) % buffer->size;
}

float audio_buffer_read(audio_buffer_t *buffer) {
  float value = buffer->buffer[buffer->read_idx];
  buffer->read_idx = (buffer->read_idx + 1) % buffer->size;
  return value;
}

void audio_buffer_mix(audio_buffer_t *buffer, float value) {
  float old_value = audio_buffer_read(buffer);
  audio_buffer_write(buffer, old_value * 0.5 + value * 0.5);
}

int main(int argc, char *argv[]) {
  audio_buffer_t buffer;
  audio_buffer_init(&buffer, BUFFER_SIZE);

  // Generate a sine wave at 440 Hz
  float freq = 440.0;
  float phase = 0.0;
  float sample_rate = SAMPLE_RATE;
  for (int i = 0; i < buffer.size; i++) {
    float sample = sinf(phase);
    audio_buffer_write(&buffer, sample);
    phase += (2 * M_PI * freq) / sample_rate;
    if (phase > 2 * M_PI) {
      phase -= 2 * M_PI;
    }
  }

  // Read the buffer and print the values
  for (int i = 0; i < buffer.size; i++) {
    float sample = audio_buffer_read(&buffer);
    printf("%.2f\n", sample);
  }

  audio_buffer_free(&buffer);
  return 0;
}