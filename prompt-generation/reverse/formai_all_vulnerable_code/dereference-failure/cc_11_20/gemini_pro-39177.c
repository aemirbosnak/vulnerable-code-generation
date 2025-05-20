//GEMINI-pro DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WAV_HEADER_SIZE 44

typedef struct {
  uint32_t chunk_id;
  uint32_t chunk_size;
  uint32_t format;
} wav_header;

typedef struct {
  uint32_t sub_chunk1_id;
  uint32_t sub_chunk1_size;
  uint16_t audio_format;
  uint16_t num_channels;
  uint32_t sample_rate;
  uint32_t byte_rate;
  uint16_t block_align;
  uint16_t bits_per_sample;
} wav_format;

typedef struct {
  uint32_t sub_chunk2_id;
  uint32_t sub_chunk2_size;
} wav_data;

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <input.wav> <output.wav>\n", argv[0]);
    return -1;
  }

  FILE *input_file = fopen(argv[1], "rb");
  if (input_file == NULL) {
    perror("fopen");
    return -1;
  }

  FILE *output_file = fopen(argv[2], "wb");
  if (output_file == NULL) {
    perror("fopen");
    return -1;
  }

  wav_header header;
  wav_format format;
  wav_data data;

  // Read the WAV header
  if (fread(&header, sizeof(header), 1, input_file) != 1) {
    perror("fread");
    return -1;
  }

  // Check if the WAV file is valid
  if (header.chunk_id != 0x52494646 || header.format != 0x57415645) {
    fprintf(stderr, "Invalid WAV file\n");
    return -1;
  }

  // Read the WAV format
  if (fread(&format, sizeof(format), 1, input_file) != 1) {
    perror("fread");
    return -1;
  }

  // Check if the WAV format is valid
  if (format.sub_chunk1_id != 0x666D7420 || format.audio_format != 1) {
    fprintf(stderr, "Invalid WAV format\n");
    return -1;
  }

  // Read the WAV data
  if (fread(&data, sizeof(data), 1, input_file) != 1) {
    perror("fread");
    return -1;
  }

  // Write the WAV header to the output file
  if (fwrite(&header, sizeof(header), 1, output_file) != 1) {
    perror("fwrite");
    return -1;
  }

  // Write the WAV format to the output file
  if (fwrite(&format, sizeof(format), 1, output_file) != 1) {
    perror("fwrite");
    return -1;
  }

  // Write the WAV data to the output file
  if (fwrite(&data, sizeof(data), 1, output_file) != 1) {
    perror("fwrite");
    return -1;
  }

  fclose(input_file);
  fclose(output_file);

  return 0;
}