//FormAI DATASET v1.0 Category: Digital signal processing ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 10

void fft(double data[], unsigned long nn, int isign);

int main()
{
    unsigned long nn;
    int isign = 1;
    double data[SIZE] = {0.0};
        
    // generate some dummy data
    for(int i=0; i<SIZE; i++)
        data[i] = sin(2*M_PI*i/SIZE) + sin(4*M_PI*i/SIZE);
        
    nn = SIZE;
    fft(data, nn, isign);

    printf("Data to be calculated by FFT.\n");
    for(int i=0; i<nn; i++)
        printf("data[%d] = %lf\n", i, data[i]);

    return 0;    
}

void fft(double data[], unsigned long nn, int isign)
{
    unsigned long n, mmax, m, j, istep;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    double c1 = 0.5, c2, h1r, h1i, h2r, h2i; 

    n = nn << 1;
    j = 1;        
        
    for(int i=1; i < n; i += 2)
    {    
        if(j > i)
        {
            tempr = data[j]; 
            tempi = data[j+1];
            data[j] = data[i];
            data[j+1] = data[i+1];
            data[i] = tempr;
            data[i+1] = tempi;
        }
                    
        m = n >> 1;

        while(m >= 2 && j > m)
        {
            j = j - m;
            m = m >> 1;
        }

        j = j + m;           
    }

    mmax = 2;
    while(n > mmax)
    {
        istep = mmax << 1;
        theta = isign * (2 * M_PI / mmax);
        wtemp = sin(0.5 * theta);
        wpr = -2.0 * wtemp * wtemp;
        wpi = sin(theta);

        wr = 1.0;
        wi = 0.0;

        for(m=1; m < mmax; m += 2)
        {
            for(int i=m; i <= n; i += istep)
            {
                j = i + mmax;
                tempr = wr * data[j] - wi * data[j+1];
                tempi = wr * data[j+1] + wi * data[j];
                data[j] = data[i] - tempr;
                data[j+1] = data[i+1] - tempi;
                data[i] = data[i] + tempr;
                data[i+1] = data[i+1] + tempi;
            }
            wtemp = wr;
            wr = wr * wpr - wi * wpi + wr;
            wi = wi * wpr + wtemp * wpi + wi;                          
        }
        mmax = istep;
    }

    //Normalization of FFT
    c2 = -isign*n;
    for(int i = 0; i < nn; i++)
    {
        c1 += c2;
        data[i] = c1 * data[i];
    }
}