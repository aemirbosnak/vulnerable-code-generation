//GPT-4o-mini DATASET v1.0 Category: Audio processing ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sndfile.h>

#define SAMPLE_RATE 44100
#define FREQUENCY 440.0
#define AMPLITUDE 0.5

void generate_sine_wave(float *buffer, size_t sample_count)
{
    for (size_t i = 0; i < sample_count; i++)
    {
        buffer[i] = (float)(AMPLITUDE * sin(2.0 * M_PI * FREQUENCY * ((double)i / SAMPLE_RATE)));
    }
}

void apply_fade_in(float *buffer, size_t sample_count, float duration)
{
    size_t fade_samples = (size_t)(duration * SAMPLE_RATE);
    for (size_t i = 0; i < fade_samples && i < sample_count; i++)
    {
        buffer[i] *= (float)i / (float)fade_samples;
    }
}

void apply_fade_out(float *buffer, size_t sample_count, float duration)
{
    size_t fade_samples = (size_t)(duration * SAMPLE_RATE);
    for (size_t i = 0; i < fade_samples && i < sample_count; i++)
    {
        buffer[sample_count - 1 - i] *= (float)i / (float)fade_samples;
    }
}

void write_to_audio_file(const char *filename, float *buffer, size_t sample_count)
{
    SNDFILE *outfile;
    SF_INFO sfinfo;
    
    sfinfo.frames = sample_count;
    sfinfo.samplerate = SAMPLE_RATE;
    sfinfo.channels = 1; // mono
    sfinfo.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;

    outfile = sf_open(filename, SFM_WRITE, &sfinfo);
    if (!outfile)
    {
        fprintf(stderr, "Could not open output file: %s\n", sf_strerror(NULL));
        exit(1);
    }

    // Write the generated sine wave to the file
    sf_write_float(outfile, buffer, sample_count);
    sf_close(outfile);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <output_file.wav> <duration_in_seconds>\n", argv[0]);
        return 1;
    }

    const char *output_file = argv[1];
    float duration = atof(argv[2]);
    size_t sample_count = (size_t)(SAMPLE_RATE * duration);

    // Allocate memory for the audio buffer
    float *buffer = (float *)malloc(sample_count * sizeof(float));
    if (!buffer)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate the sine wave
    generate_sine_wave(buffer, sample_count);

    // Apply fade in and fade out effects
    apply_fade_in(buffer, sample_count, 1.0); // 1 second fade in
    apply_fade_out(buffer, sample_count, 1.0); // 1 second fade out

    // Write the buffer to the output audio file
    write_to_audio_file(output_file, buffer, sample_count);

    // Free allocated memory
    free(buffer);

    printf("Audio file '%s' generated successfully with duration %f seconds\n", output_file, duration);
    return 0;
}