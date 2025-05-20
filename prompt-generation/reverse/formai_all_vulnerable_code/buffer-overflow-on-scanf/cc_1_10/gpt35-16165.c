//FormAI DATASET v1.0 Category: Audio processing ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WAV_HEADER_LENGTH 44

int main()
{
    FILE *input, *output;
    char input_filename[50], output_filename[50];
    char wav_header[WAV_HEADER_LENGTH];
    short audio_sample;
    double decibel;
    int i;

    printf("Enter input wav file name: ");
    scanf("%s", input_filename);

    input = fopen(input_filename, "rb");
    if (input == NULL)
    {
        printf("Error opening file.");
        exit(1);
    }

    printf("Enter output wav file name (without extension): ");
    scanf("%s", output_filename);

    output = fopen(strcat(output_filename, ".wav"), "wb");
    if (output == NULL)
    {
        printf("Error creating file.");
        exit(1);
    }

    fread(wav_header, 1, WAV_HEADER_LENGTH, input);
    fwrite(wav_header, 1, WAV_HEADER_LENGTH, output);

    while (fread(&audio_sample, sizeof(audio_sample), 1, input))
    {
        decibel = 20 * log10(abs(audio_sample) / 32768.0);

        if (decibel > -90)
        {
            audio_sample /= 2;
        }

        fwrite(&audio_sample, sizeof(audio_sample), 1, output);
    }

    fclose(input);
    fclose(output);

    printf("Processing complete. Please check the output file.");
    return 0;
}