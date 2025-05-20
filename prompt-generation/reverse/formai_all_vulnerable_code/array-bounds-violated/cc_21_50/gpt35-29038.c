//FormAI DATASET v1.0 Category: Digital signal processing ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159265358979323846

int main(){

    int i,j,k,n,N;			// Declaring variables
    double x[100],h[100],X_exp[100],H_exp[100],Y_exp[100],X_re[100],H_re[100],Y_re[100],Y[100],X_re_tmp,X_im,W_re,W_im; //Declaring variables for real and imaginary parts of fft calculation.

    printf("Enter the value of n (Length of Sequences): ");
    scanf("%d",&n);

    // Taking Input of x(n) sequence.
    printf("Enter the Input Sequence (x(n)):\n");
    for(i=0;i<n;i++){
        scanf("%lf",&x[i]);
    }

    // Taking Input of h(n) sequence.
    printf("Enter the Sequence (h(n)):\n");
    for(i=0;i<n;i++){
        scanf("%lf",&h[i]);
    }

    //Padding the sequences with zeroes.
    for(i=n;i<2*n;i++){
        x[i]=h[i]=X_exp[i]=H_exp[i]=X_re[i]=H_re[i]=0;
    }

    //FFT Calculation of x(n)
    for(i=0;i<n;i++){
        X_re[i]=x[i];
    }
    for(i=n;i<2*n;i++){
        X_re[i]=0;
    }

    for(i=0;i<n;i++){
        X_exp[i]=x[i];
    }
    for(i=n;i<2*n;i++){
        X_exp[i]=0;
    }

    for(k=0;k<n;k++){
        X_re_tmp=0;
        for(j=0;j<n;j++){
            W_re=cos(2*PI*j*k/n);
            W_im=-sin(2*PI*j*k/n);
            X_re_tmp=X_re_tmp+(X_re[j]*W_re);
            X_re_tmp=X_re_tmp+(X_exp[j]*W_im);
        }
        X_re[k]=X_re_tmp;
        X_exp[k]=X_re_tmp;
    }

    //FFT Calculation of h(n)
    for(i=0;i<n;i++){
        H_re[i]=h[i];
    }
    for(i=n;i<2*n;i++){
        H_re[i]=0;
    }

    for(i=0;i<n;i++){
        H_exp[i]=h[i];
    }
    for(i=n;i<2*n;i++){
        H_exp[i]=0;
    }

    for(k=0;k<n;k++){
        X_re_tmp=0;
        for(j=0;j<n;j++){
            W_re=cos(2*PI*j*k/n);
            W_im=-sin(2*PI*j*k/n);
            X_re_tmp=X_re_tmp+(H_re[j]*W_re);
            X_re_tmp=X_re_tmp+(H_exp[j]*W_im);
        }
        H_re[k]=X_re_tmp;
        H_exp[k]=X_re_tmp;
    }

    //Multiplication of the two transformed sequences
    for(i=0;i<n;i++){
        Y_exp[i]=(X_re[i]*H_re[i])-(X_exp[i]*H_exp[i]);
        Y_re[i]=(X_re[i]*H_exp[i])+(X_exp[i]*H_re[i]);
    }

    //IFFT Calculation of Y(k)
    for(i=0;i<n;i++){
        Y_re[i]=Y_exp[i];
    }
    for(i=n;i<2*n;i++){
        Y_re[i]=0;
    }

    for(i=0;i<n;i++){
        Y_exp[i]=Y_re[i];
    }
    for(i=n;i<2*n;i++){
        Y_exp[i]=0;
    }

    for(k=0;k<n;k++){
        X_re_tmp=0;
        for(j=0;j<n;j++){
            W_re=cos(2*PI*j*k/n);
            W_im=sin(2*PI*j*k/n);
            X_re_tmp=X_re_tmp+(Y_re[j]*W_re);
            X_re_tmp=X_re_tmp+(Y_exp[j]*W_im);
        }
        Y[k]=X_re_tmp/n;
    }

    //Output of Convolved Sequence
    printf("\n\nOutput Sequence (y(n)): ");
    for(i=0;i<n;i++){
        printf("%.2lf\t",Y[i]);
    }

    return 0;
}