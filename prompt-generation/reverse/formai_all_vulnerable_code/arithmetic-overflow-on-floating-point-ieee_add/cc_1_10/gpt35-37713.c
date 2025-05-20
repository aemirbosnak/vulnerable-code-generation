//FormAI DATASET v1.0 Category: Audio processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    FILE *fpin, *fpout;
    char input_file_name[40], output_file_name[40];
    double input_array[100000], output_array[100000];
    double sample_rate, cutoff_frequency;
    int num_samples, i;

    // Get file input and output names from user
    printf("Enter input file name: ");
    scanf("%s", input_file_name);
    printf("Enter output file name: ");
    scanf("%s", output_file_name);

    // Open the input file
    fpin = fopen(input_file_name, "rb");
    if (fpin == NULL)
    {
        printf("Error opening input file\n");
        exit(0);
    }

    // Open the output file
    fpout = fopen(output_file_name, "wb");
    if (fpout == NULL)
    {
        printf("Error opening output file\n");
        exit(0);
    }

    // Get the sample rate and cutoff frequency from user
    printf("Enter sample rate: ");
    scanf("%lf", &sample_rate);
    printf("Enter cutoff frequency: ");
    scanf("%lf", &cutoff_frequency);

    // Read the samples from the input file
    num_samples = fread(input_array, sizeof(double), 100000, fpin);

    // Apply the filter to the samples
    double RC = 1.0/(cutoff_frequency*2*M_PI);
    double dt = 1.0/sample_rate;
    double alpha = dt/(RC+dt);
    output_array[0] = input_array[0];

    for (i = 1; i < num_samples; i++)
    {
        output_array[i] = alpha*input_array[i] + (1.0-alpha)*output_array[i-1];
    }

    // Write the filtered samples to the output file
    fwrite(output_array, sizeof(double), num_samples, fpout);

    // Close the input and output files
    fclose(fpin);
    fclose(fpout);

    printf("Done!\n");
    return 0;
}