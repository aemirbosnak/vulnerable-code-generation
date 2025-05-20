#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *audio_data = malloc(1024);
    FILE *audio_file = fopen("audio.wav", "rb");

    if (audio_file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    // Read audio data from file
    size_t read_size = fread(audio_data, 1, 1024, audio_file);

    // Out-of-bounds write vulnerability
    audio_data[read_size] = 0xdeadbeef;

    // Free memory and close file
    free(audio_data);
    fclose(audio_file);

    return 0;
}
