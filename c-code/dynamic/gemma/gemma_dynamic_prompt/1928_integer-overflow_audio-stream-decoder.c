#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sample_rate = 44100;
    int num_samples = 100000;
    int sample_buffer[num_samples];

    for (int i = 0; i < num_samples; i++)
    {
        sample_buffer[i] = (rand() % 2) * 2 - 1;
    }

    FILE *fp = fopen("audio.wav", "w");
    fwrite(sample_buffer, sizeof(int), num_samples, fp);
    fclose(fp);

    return 0;
}
