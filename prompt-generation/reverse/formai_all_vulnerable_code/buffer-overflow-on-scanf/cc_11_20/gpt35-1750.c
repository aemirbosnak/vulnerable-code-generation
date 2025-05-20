//FormAI DATASET v1.0 Category: Digital signal processing ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* A funny DSP program that generates music from your name! */

int main()
{
    char name[50];
    int i;
    float freq = 0.0;
    float amplitude = 0.0;

    printf("Hi there, I am your friendly music generator!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nGenerating music for %s...\n\n", name);

    for (i = 0; name[i] != '\0'; ++i)
    {
        if (name[i] == ' ')
        {
            freq = 0.0;
            amplitude = 0.0;
        }
        else if (name[i] == 'a' || name[i] == 'A')
        {
            freq = 440.0;
            amplitude = 0.8;
        }
        else if (name[i] == 'b' || name[i] == 'B')
        {
            freq = 493.88;
            amplitude = 0.6;
        }
        else if (name[i] == 'c' || name[i] == 'C')
        {
            freq = 523.25;
            amplitude = 0.7;
        }
        else if (name[i] == 'd' || name[i] == 'D')
        {
            freq = 587.33;
            amplitude = 0.5;
        }
        else if (name[i] == 'e' || name[i] == 'E')
        {
            freq = 659.25;
            amplitude = 0.4;
        }
        else if (name[i] == 'f' || name[i] == 'F')
        {
            freq = 698.46;
            amplitude = 0.3;
        }
        else if (name[i] == 'g' || name[i] == 'G')
        {
            freq = 783.99;
            amplitude = 0.2;
        }
        else
        {
            freq = 0.0;
            amplitude = 0.0;
        }

        if (freq != 0.0)
        {
            printf("Playing %c with frequency %.2f Hz and amplitude %.2f\n", name[i], freq, amplitude);
            //generate sinusoidal sound wave
            for (float t = 0; t < 1.0; t += 0.001)
            {
                float sample = amplitude * sin(2 * M_PI * freq * t);
                //play the sample
                printf("%d ", (int)(32767 * sample)); //not really playing, just printing out samples ;)
            }
            printf("\n");
        }
    }

    printf("\nDone generating music for %s!\n", name);

    return 0;
}