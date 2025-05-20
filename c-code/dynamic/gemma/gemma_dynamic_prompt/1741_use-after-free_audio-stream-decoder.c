#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *audio_stream_decoder(int stream_id) {
  // Allocate memory for the audio data
  void *audio_data = malloc(1024);

  // Free the memory, but keep the pointer
  free(audio_data);

  // Use the freed memory to store data
  audio_data = "This is the data stored in the freed memory";

  return audio_data;
}

int main() {
  // Decode the audio stream
  void *audio_data = audio_stream_decoder(1);

  // Print the audio data
  printf("%s", audio_data);

  return 0;
}
