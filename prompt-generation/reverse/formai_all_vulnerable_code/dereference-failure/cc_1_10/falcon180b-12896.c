//Falcon-180B DATASET v1.0 Category: Audio processing ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SAMPLE_RATE 44100
#define BUFFER_SIZE 1024

int main()
{
    FILE *input_file;
    FILE *output_file;
    short int input_buffer[BUFFER_SIZE];
    short int output_buffer[BUFFER_SIZE];
    int i;
    int j;
    float gain;
    float left_channel;
    float right_channel;
    float left_channel_out;
    float right_channel_out;
    int count;
    input_file = fopen("input.wav", "rb");
    output_file = fopen("output.wav", "wb");
    if(input_file == NULL || output_file == NULL)
    {
        printf("Error opening file\n");
        exit(0);
    }
    fseek(input_file, 44, SEEK_SET); //skip header
    count = 0;
    while(fread(input_buffer, sizeof(short int), BUFFER_SIZE, input_file)!= 0)
    {
        for(i=0; i<BUFFER_SIZE; i++)
        {
            left_channel = input_buffer[i];
            right_channel = input_buffer[i+1];
            gain = 1.5;
            left_channel_out = left_channel * gain;
            right_channel_out = right_channel * gain;
            output_buffer[i] = (short int) left_channel_out;
            output_buffer[i+1] = (short int) right_channel_out;
        }
        fwrite(output_buffer, sizeof(short int), BUFFER_SIZE, output_file);
        count++;
        if(count == 44100)
        {
            break;
        }
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}