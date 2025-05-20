//FormAI DATASET v1.0 Category: Digital signal processing ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

void DFT(double *input, double *real_output, double *imag_output, int n);
void FFT(double *input, double *real_output, double *imag_output, int n);
void complex_mult(double x_real, double x_imag, double y_real, double y_imag, double *z_real, double *z_imag);

int main()
{
    int n, i;
    double *input, *real_output, *imag_output;

    printf("Enter the number of samples: ");
    scanf("%d", &n);

    input = (double *)malloc(n * sizeof(double));
    real_output = (double *)malloc(n * sizeof(double));
    imag_output = (double *)malloc(n * sizeof(double));

    printf("Enter the samples: ");
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &input[i]);
    }

    DFT(input, real_output, imag_output, n);

    printf("\nDFT Output:\n");

    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %lf + %lfj\n", i, real_output[i], imag_output[i]);
    }

    FFT(input, real_output, imag_output, n);

    printf("\nFFT Output:\n");

    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %lf + %lfj\n", i, real_output[i], imag_output[i]);
    }

    free(input);
    free(real_output);
    free(imag_output);

    return 0;
}

void DFT(double *input, double *real_output, double *imag_output, int n)
{
    int k, n1;
    double c, s, arg;

    for (k = 0; k < n; k++)
    {
        real_output[k] = 0;
        imag_output[k] = 0;

        for (n1 = 0; n1 < n; n1++)
        {
            arg = 2 * PI * k * n1 / (double)n;
            c = cos(arg);
            s = sin(arg);
            real_output[k] += input[n1] * c;
            imag_output[k] -= input[n1] * s;
        }
    }
}

void FFT(double *input, double *real_output, double *imag_output, int n)
{
    int i, j, k, n1, l, m;
    double c, s, arg, temp_real, temp_imag;
    double *x_real, *x_imag, *tmp_real, *tmp_imag;

    x_real = (double *)malloc(n * sizeof(double));
    x_imag = (double *)malloc(n * sizeof(double));
    tmp_real = (double *)malloc(n * sizeof(double));
    tmp_imag = (double *)malloc(n * sizeof(double));

    for (i = 0; i < n; i++)
    {
        x_real[i] = input[i];
        x_imag[i] = 0;
    }

    j = 0;
    for (i = 1; i < n - 1; i++)
    {
        k = n >> 1;
        while (k <= j)
        {
            j -= k;
            k >>= 1;
        }
        j += k;
        if (i < j)
        {
            temp_real = x_real[i];
            temp_imag = x_imag[i];
            x_real[i] = x_real[j];
            x_imag[i] = x_imag[j];
            x_real[j] = temp_real;
            x_imag[j] = temp_imag;
        }
    }

    for (i = 0; i < log2(n); i++)
    {
        l = 1 << i;
        for (j = 0; j < n; j += 2 * l)
        {
            for (k = 0; k < l; k++)
            {
                arg = 2 * PI * k / (double)(2 * l);
                c = cos(arg);
                s = sin(arg);
                complex_mult(x_real[j + k + l], x_imag[j + k + l], c, s, &temp_real, &temp_imag);
                tmp_real[j + k] = x_real[j + k] + temp_real;
                tmp_imag[j + k] = x_imag[j + k] + temp_imag;
                tmp_real[j + k + l] = x_real[j + k] - temp_real;
                tmp_imag[j + k + l] = x_imag[j + k] - temp_imag;
            }
        }

        for (m = 0; m < n; m++)
        {
            x_real[m] = tmp_real[m];
            x_imag[m] = tmp_imag[m];
        }
    }

    for (i = 0; i < n; i++)
    {
        real_output[i] = x_real[i];
        imag_output[i] = x_imag[i];
    }

    free(x_real);
    free(x_imag);
    free(tmp_real);
    free(tmp_imag);
}

void complex_mult(double x_real, double x_imag, double y_real, double y_imag, double *z_real, double *z_imag)
{
    *z_real = x_real * y_real - x_imag * y_imag;
    *z_imag = x_real * y_imag + x_imag * y_real;
}