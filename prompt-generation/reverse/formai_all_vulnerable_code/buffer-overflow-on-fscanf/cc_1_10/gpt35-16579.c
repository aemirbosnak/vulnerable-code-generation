//FormAI DATASET v1.0 Category: Digital signal processing ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define SIZE 1000 //Define a constant variable - size of input signal


//Function for calculating Discrete Fourier Transform of the signal
void DFT(double x[SIZE][2],int N){

    double W[2];
    W[0]=cos(2*M_PI/N);
    W[1]=-sin(2*M_PI/N);

    //Loop for calculating DFT
    for(int k=0;k<N;k++){
        double t[2]={0.0,0.0};
        for(int n=0;n<N;n++){
            double p[2]={cos(2*M_PI*n*k/N),-sin(2*M_PI*n*k/N)};
            t[0]+=x[n][0]*p[0]-x[n][1]*p[1];
            t[1]+=x[n][0]*p[1]+x[n][1]*p[0];
        }
        x[k][0]=t[0];
        x[k][1]=t[1];
    }

}


int main(){

    double signal[SIZE][2];
    FILE* data_file;
    data_file=fopen("input_data.txt","r");

    //Reading input signal from file
    for(int i=0;i<SIZE;i++){
        fscanf(data_file,"%lf",&signal[i][0]);
        signal[i][1]=0.0;
    }

    fclose(data_file);

    DFT(signal,SIZE);

    //Writing output to file
    FILE* output_file;
    output_file=fopen("output_data.txt","w");
    for(int i=0;i<SIZE;i++){
        fprintf(output_file,"%d : Real = %lf\t Imag = %lf\n",i,signal[i][0],signal[i][1]);
    }
    fclose(output_file);

    return 0;
}