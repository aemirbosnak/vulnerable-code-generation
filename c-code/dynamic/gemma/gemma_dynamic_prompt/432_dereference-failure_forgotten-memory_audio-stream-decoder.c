#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *audio_buffer = NULL;
    audio_buffer = (int *)malloc(1024);
    if (audio_buffer == NULL)
    {
        return 1;
    }

    // Read audio data from stream
    FILE *audio_file = fopen("audio.dat", "r");
    if (audio_file == NULL)
    {
        return 1;
    }

    // Decode audio data
    int data_size = fread(audio_buffer, 1, 1024, audio_file);
    if (data_size != 1024)
    {
        return 1;
    }

    // Free memory
    free(audio_buffer);
    fclose(audio_file);

    return 0;
}
